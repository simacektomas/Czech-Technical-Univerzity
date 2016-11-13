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
import javax.jms.QueueSession;
import javax.jms.Session;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import config.Config;
import messages.Booking;

public class BookingProcessor implements MessageListener{
	
    private QueueConnectionFactory qconFactory;
    private QueueConnection qcon;
    private QueueSession qsession;
    private QueueReceiver bookingReceiver;
    private Queue bookingQueue;
 
    // callback when the message exist in the queue
    public void onMessage(Message msg) {
        try {
        	if ( msg instanceof ObjectMessage ){
				ObjectMessage message = (ObjectMessage) msg;
				Serializable object = message.getObject();
				if (object instanceof Booking) System.out.println("Message received: " + object.toString());
				else return; 								
			} else return;	
        } catch (JMSException jmse) {
            System.err.println("An exception occurred: " + jmse.getMessage());
        }
    }
 
    // create a connection to the WLS using a JNDI context
    public void init(Context ctx, String queueName) throws NamingException, JMSException {
 
        qconFactory = (QueueConnectionFactory) ctx.lookup(Config.JMS_FACTORY);
        qcon = qconFactory.createQueueConnection();
        qsession = qcon.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
        bookingQueue = (Queue) ctx.lookup(queueName);
 
        bookingReceiver = qsession.createReceiver(bookingQueue);
        bookingReceiver.setMessageListener(this);
 
        qcon.start();
    }
 
    // close sender, connection and the session
    public void close() throws JMSException {
        bookingReceiver.close();
        qsession.close();
        qcon.close();
    }
 
    // start receiving messages from the queue
    public void receive(String queueName) throws Exception {
        Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, Config.JNDI_FACTORY);
        env.put(Context.PROVIDER_URL, Config.PROVIDER_URL);
 
        InitialContext ic = new InitialContext(env);
 
        init(ic, queueName);
 
        System.out.println("Connected to " + bookingQueue.toString() + ", receiving messages...");
        try {
            synchronized (this) {
                while (true) {
                    this.wait();
                }
            }
        } finally {
            close();
            System.out.println("Finished.");
        }
    }
 
    public static void main(String[] args) throws Exception {
        // input arguments
        String queueName = "jms/booking_queue" ;
 
        // create the producer object and receive the message
        BookingProcessor consumer = new BookingProcessor();
        consumer.receive(queueName);
    }

}
