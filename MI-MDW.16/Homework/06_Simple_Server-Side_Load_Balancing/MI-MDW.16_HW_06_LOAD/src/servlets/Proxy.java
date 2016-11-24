package servlets;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Collections;
import java.util.Enumeration;
import java.util.function.Consumer;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import services.Service;

/**
 * Servlet implementation class Proxy
 */
public class Proxy extends HttpServlet implements Runnable {
	private static final long serialVersionUID = 1L;	
    private Service services[] = {
    		  new Service("http://147.32.233.18:8888/MI-MDW-LastMinute1/list"),
			  new Service("http://147.32.233.18:8888/MI-MDW-LastMinute2/list"),
			  new Service("http://147.32.233.18:8888/MI-MDW-LastMinute3/list")
    };   
    private Thread serviceMonitor;
    private int lastService;
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Proxy() {
        super();        
        serviceMonitor = new Thread(this);
        serviceMonitor.start();
        lastService = 0;
    }
    
    @Override
	public void run() {
    	int i = 0;	
		while(true) {					
			this.checkService( services[i] );									
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) { 
				e.printStackTrace();
			}			
			i = (i+1) % services.length;			
		}
	}
    
    private void checkService( Service service ) {
		String url = service.getAddress();
		HttpURLConnection connection;
		try {
			connection = (HttpURLConnection) (new URL(url)).openConnection();		
			connection.setRequestMethod("GET");		
			int code = connection.getResponseCode();			
			if ( code == 200 ) service.setHealthy(true);
			else service.setHealthy(false);		 			
		}
		catch (Exception e) {
			e.printStackTrace();
		}	
	}
    
    private Service getHealthyService() {
    	int i = this.lastService;
    	int modulo = i % services.length;
    	Service service = null;
    	while( true ){    		    		    	
    		if(this.services[modulo].isHealthy()){    			
    			service = this.services[modulo];
    			this.lastService = (modulo + 1) % services.length;
    			break;
    		}    		    		
    		i++;
    		modulo = i % services.length;
    		if (modulo == this.lastService) {    			
    			service = null;
    			this.lastService = (modulo + 1) % services.length;
    			break;
    		}
    	}
        return service;    		
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(final HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		Service service = this.getHealthyService();		
		if ( service == null ) {
			
			return;
		}
		System.out.println(service.toString());
 		String url = service.getAddress();
 		HttpURLConnection connection = (HttpURLConnection) (new URL(url)).openConnection();
        // HTTP method
        connection.setRequestMethod("GET");
        // copy headers
        Enumeration<String> headerNames = request.getHeaderNames();
		while( headerNames.hasMoreElements() ) {
			String header = headerNames.nextElement();
			connection.setRequestProperty(header, request.getHeader(header));
		}        
        // copy body
        BufferedReader inputStream = new BufferedReader(
                new InputStreamReader(connection.getInputStream()));
        String inputLine;
        ServletOutputStream sout = response.getOutputStream();
        while ((inputLine = inputStream.readLine()) != null) {
            sout.write(inputLine.getBytes());
        }
        // close
        inputStream.close();
        sout.flush();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
}
