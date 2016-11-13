package clients;

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

public class BookingClient implements MessageListener{
	// connection factory
    private QueueConnectionFactory qconFactory;

    // connection to a queue
    private QueueConnection qcon;

    // session within a connection
    private QueueSession qsession;

    // queue sender that sends a message to the queue
    private QueueSender bookingSender;
    private QueueReceiver confirmationReceiver;

    // queue where the message will be sent to
    private Queue bookingQueue;
    private Queue confirmationQueue;

    // a message that will be sent to the queue
    private TextMessage booking;

    // create a connection to the WLS using a JNDI context
    public void init(Context ctx, String bookingQueue, String confirmationQueue)
        throws NamingException, JMSException {

        // create connection factory based on JNDI and a connection
        qconFactory = (QueueConnectionFactory) ctx.lookup(Config.JMS_FACTORY);
        qcon = qconFactory.createQueueConnection();

        // create a session within a connection
        qsession = qcon.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

        // lookups the queue using the JNDI context
        this.bookingQueue = (Queue) ctx.lookup(bookingQueue);
        this.confirmationQueue = (Queue) ctx.lookup(confirmationQueue);

        // create sender and message
        bookingSender = qsession.createSender(this.bookingQueue);
        confirmationReceiver = qsession.createReceiver(this.confirmationQueue);
        
        confirmationReceiver.setMessageListener(this);
        booking = qsession.createTextMessage();
        
        qcon.start();
    }

    // close sender, connection and the session
    public void close() throws JMSException {
        bookingSender.close();
        confirmationReceiver.close();
        qsession.close();
        qcon.close();
    }

    // sends the message to the queue
    public void send(String bookingQueue, String confirmationQueue, String message) throws Exception {

        // create a JNDI context to lookup JNDI objects (connection factory and queue)
        Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, Config.JNDI_FACTORY);
        env.put(Context.PROVIDER_URL, Config.PROVIDER_URL);

        InitialContext ic = new InitialContext(env);
        init(ic, bookingQueue, confirmationQueue);

        // send the message and close
        try {
            booking.setText(message);
            bookingSender.send(booking, DeliveryMode.PERSISTENT, 8, 0);
            System.out.println("Booking was sent to the destination " +
                    bookingSender.getDestination().toString());
            
            synchronized (this) {
				this.wait();
			}
            // wait for confirmation
        } finally {
            close();
        }
    }

    public static void main(String[] args) throws Exception {
        // input arguments
        String msg = "Hello" ;
        String bookingQueue = "jms/mdw-booking_queue" ;
        String confirmationQueue = "jms/mdw-confirmation_queue";

        // create the producer object and send the message
        BookingClient bookingClient = new BookingClient();
        bookingClient.send(bookingQueue, confirmationQueue, msg);
    }

	@Override
	public void onMessage(Message msg) {
		// TODO Auto-generated method stub
		System.out.println("Confirmation received: " + msg.toString());
		
	}
}
