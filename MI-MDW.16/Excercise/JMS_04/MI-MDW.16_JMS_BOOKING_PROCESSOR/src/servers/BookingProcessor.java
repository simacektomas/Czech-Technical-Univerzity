package servers;

import java.util.Hashtable;

import javax.jms.DeliveryMode;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageListener;
import javax.jms.Queue;
import javax.jms.QueueConnection;
import javax.jms.QueueConnectionFactory;
import javax.jms.QueueReceiver;
import javax.jms.QueueSender;
import javax.jms.QueueSession;
import javax.jms.Session;
import javax.jms.TextMessage;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import config.Config;

public class BookingProcessor implements MessageListener {

	//
	private QueueConnectionFactory qconFactory;
	private QueueConnection qcon;	
	private QueueSession qsession;
	
	private QueueSender confirmationSender;
	private QueueReceiver bookingReciever;
	
	private Queue bookingQueue;
	private Queue confirmationQueue;
	
	private TextMessage response;
	
	
	@Override
	public void onMessage(Message msg) {
		// TODO Auto-generated method stub
		try {
			String msgText;
			if(msg instanceof TextMessage) {
				msgText = ((TextMessage) msg).getText();
			}
			else {
				msgText = msg.toString();
			}
			System.out.println("Message received: " + msgText);
			
			response.setText("Confirmed");
			confirmationSender.send(response, DeliveryMode.PERSISTENT, 8, 0);
			System.out.println("Confirmation sent to destination " +
                    confirmationSender.getDestination().toString());
			
		} catch (JMSException jmse ){
			System.err.println("An exception occured: " + jmse.getMessage());
		}
		
	}
	
	public void init(Context ctx, String bookingQueue, String confirmationQueue) throws JMSException, NamingException{
		qconFactory = (QueueConnectionFactory) ctx.lookup(Config.JMS_FACTORY);
		qcon = qconFactory.createQueueConnection();
		qsession = qcon.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
		
		this.bookingQueue = (Queue) ctx.lookup(bookingQueue);
		this.confirmationQueue = (Queue) ctx.lookup(confirmationQueue);
		
		bookingReciever = qsession.createReceiver(this.bookingQueue);
		confirmationSender = qsession.createSender(this.confirmationQueue);
		
		bookingReciever.setMessageListener(this);
		this.response = qsession.createTextMessage();
		
		qcon.start();
	}
	
	public void close() throws JMSException {
		bookingReciever.close();
		confirmationSender.close();
		qsession.close();
		qcon.close();
	}
	
	public void receive(String bookingQueue, String confirmationQueue) throws Exception{
		Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, Config.JNDI_FACTORY);
        env.put(Context.PROVIDER_URL, Config.PROVIDER_URL);
        
        InitialContext ic = new InitialContext(env);
        init(ic, bookingQueue, confirmationQueue);
        
        System.out.println("Listening to " + this.bookingQueue.toString() + " and connected to " + this.confirmationQueue.toString() + ", receiving messages...");
        try {
        	synchronized (this) {
				while(true) {
					this.wait();
				}
			}        	
        } finally {
        	close();
        	System.out.println("Finished.");
        }
	}
	
	public static void main(String[] args) throws Exception {
		String bookingQueue = "jms/mdw-booking_queue";
		String confirmationQueue = "jms/mdw-confirmation_queue";
		
		BookingProcessor bookingProcessor = new BookingProcessor();
		bookingProcessor.receive(bookingQueue, confirmationQueue);		
		
		
	}

}
