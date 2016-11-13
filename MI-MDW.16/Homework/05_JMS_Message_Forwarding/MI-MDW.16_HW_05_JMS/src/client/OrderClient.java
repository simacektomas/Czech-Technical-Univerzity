package client;

import java.io.Serializable;
import java.util.Hashtable;

import javax.jms.DeliveryMode;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.Queue;
import javax.jms.QueueConnection;
import javax.jms.QueueConnectionFactory;
import javax.jms.QueueSender;
import javax.jms.QueueSession;
import javax.jms.Session;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import config.Config;
import messages.Booking;
import messages.Trip;

public class OrderClient {
	
	private QueueConnectionFactory qf;
	private QueueConnection con;
	private QueueSession qsession;
	private QueueSender qsender;
	private Queue queue;
	private Message msg;
	
	public void init(Context ctx, String queue) throws NamingException, JMSException {
		qf = (QueueConnectionFactory) ctx.lookup(Config.JMS_FACTORY);
		con = qf.createQueueConnection();
		qsession = con.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
		
		this.queue = (Queue) ctx.lookup(queue);
		
		qsender = qsession.createSender(this.queue);
		// init the message		
	}
	
	public void close() throws JMSException {
		qsender.close();
		qsession.close();
		con.close();
	}
	
	public void send(String queue, Object message) throws Exception {
		// create a JNDI context to lookup JNDI objects (connection factory and queue)
        Hashtable<String, String> env = new Hashtable<String, String>();
        env.put(Context.INITIAL_CONTEXT_FACTORY, Config.JNDI_FACTORY);
        env.put(Context.PROVIDER_URL, Config.PROVIDER_URL);
        
        InitialContext ic = new InitialContext(env);
        init(ic, queue);
        
        try {
        	msg = qsession.createObjectMessage((Serializable) message);
        	qsender.send(msg, DeliveryMode.PERSISTENT, 8, 0);
        	System.out.println("Message: " + message.toString() + "\nDestitnation: " + qsender.getDestination().toString());
        } finally {
        	close();
        }
	}
	
	public static void main(String[] args) throws Exception {
		String queue = "jms/order_queue";
		
		OrderClient client = new OrderClient();
		client.send(queue, new Trip(0, "Stockholm", 5));
		client.send(queue, new Booking(0, "Thomas"));
	}
	

}
