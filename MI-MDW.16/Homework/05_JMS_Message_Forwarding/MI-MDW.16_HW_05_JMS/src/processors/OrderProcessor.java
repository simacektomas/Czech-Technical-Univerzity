package processors;

import java.io.Serializable;
import java.util.Hashtable;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.ObjectMessage;
import javax.jms.Queue;
import javax.jms.QueueConnection;
import javax.jms.QueueConnectionFactory;
import javax.jms.QueueReceiver;
import javax.jms.QueueSender;
import javax.jms.QueueSession;
import javax.jms.Session;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import config.Config;
import messages.Booking;
import messages.Trip;

public class OrderProcessor implements MessageListener {

	private QueueConnectionFactory qf;
	private QueueConnection con;
	private QueueSession qsession;	
	private QueueReceiver orderReceiver;
	private QueueSender bookingSender;
	private QueueSender tripSender;
	private Queue orderQueue;
	private Queue bookingQueue;
	private Queue tripQueue;
	
	
	@Override
	public void onMessage(Message msg) {
		// TODO Auto-generated method stub
		try {
			if ( msg instanceof ObjectMessage ){
				ObjectMessage message = (ObjectMessage) msg;
				Serializable object = message.getObject();
				if (object instanceof Trip) {
					tripSender.send(message);
					System.out.println("Forwarding message from " + orderQueue.toString()
					+ " to " + tripSender.getDestination().toString() + "");
				}
				else if (object instanceof Booking) {
					bookingSender.send(message); 
					System.out.println("Forwarding message from " + orderQueue.toString()
					+ " to " + bookingSender.getDestination().toString() + "");
				}
				else return;
			} else return;		
		} catch ( JMSException jmse) {
			System.err.println("An exception occurred: " + jmse.getMessage());
		}															
	}
	
	public void init(Context ctx, String orderQueue, String bookingQueue, String tripQueue) throws JMSException, NamingException {
		qf = (QueueConnectionFactory) ctx.lookup(Config.JMS_FACTORY);
		con = qf.createQueueConnection();
		qsession = con.createQueueSession(false,  Session.AUTO_ACKNOWLEDGE);
		
		this.orderQueue = (Queue) ctx.lookup(orderQueue);
		this.bookingQueue = (Queue) ctx.lookup(bookingQueue);
		this.tripQueue = (Queue) ctx.lookup(tripQueue);
		
		orderReceiver = qsession.createReceiver(this.orderQueue);
		orderReceiver.setMessageListener(this);
		
		bookingSender = qsession.createSender(this.bookingQueue);
		tripSender = qsession.createSender(this.tripQueue);
		
		con.start();		
	}
	
	public void close() throws JMSException {
		orderReceiver.close();
		bookingSender.close();
		tripSender.close();
		qsession.close();
		con.close();
	}
	
	public void receive(String orderQueue, String bookingQueue, String tripQueue) throws NamingException, JMSException, InterruptedException {
		Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, Config.JNDI_FACTORY);
        env.put(Context.PROVIDER_URL, Config.PROVIDER_URL);
 
        InitialContext ic = new InitialContext(env);
        init(ic, orderQueue, bookingQueue, tripQueue);
        
        System.out.println("Connected to " + orderQueue.toString() + ", receiving messages...");
        try {
        	synchronized (this) {
				while(true){
					this.wait();
				}
			}
        } finally {
				close();
				System.out.println("Finished.");		
        }
        
	}
	public static void main(String[] args) throws NamingException, JMSException, InterruptedException {
		String orderQueue = "jms/order_queue";
		String bookingQueue = "jms/booking_queue";
		String tripQueue = "jms/trips_queue";
		
		OrderProcessor orderProcessor = new OrderProcessor();
		orderProcessor.receive(orderQueue, bookingQueue, tripQueue);
	}

}
