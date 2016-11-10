package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import entities.Booking;
import enums.Status;

/**
 * Servlet implementation class BookingManager
 */
public class BookingManager extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public BookingManager() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// try to retrieve session
		// 
		
		HttpSession session = request.getSession(false);
		
		if( session != null ) {			
			// session was created
			// client booked a trip, status = NEW
			Booking booking = (Booking) session.getAttribute("booking");
			if ( booking == null ) {
				response.getWriter().append("Error Booking is not in session\n");
				return;
			}
			if ( booking.getStatus() == Status.NEW ) {
				// Booking was just created Status == NEW
				// We will sent payment information
				int max = 100000000, min = 0;				
				int random = min + (int)(Math.random()*(max-min) + 1 );
				
				Cookie paymentCookie = new Cookie( "transaction", Integer.toString(random) );
				session.setAttribute("paymentCookie", paymentCookie);				
				response.addCookie(paymentCookie);
				
				// Set status waiting for payment
				booking.setStatus( Status.PAYMENT );
				response.getWriter().append("Waiting for payment for " + booking.getTrip() + " trip\n");
				response.getWriter().append("See cookies\n");
				response.getWriter().append("Status = PAYMENT\n");
				return;
			}
			else if ( booking.getStatus() == Status.PAYMENT ) {
				// Booking was just created Status == NEW
				// This request should pay for booking (cookie simulation)
				Cookie[] cookies = request.getCookies();
				// find payment cookie
				for( int i = 0; i < cookies.length; ++i ) {					
					if ( cookies[i].getName().equals("transaction") ) {
						// Compare retrieved cookie with cookie from session
						Cookie paymentCookieOrig = (Cookie) session.getAttribute("paymentCookie");
						if ( paymentCookieOrig == null ) {
							response.getWriter().append("Session error, cannot find original payment cookie\n");
							return;
						}
						if ( paymentCookieOrig.getValue().equals( cookies[i].getValue() )) {
							// Client sent valid cookie = trip is paid
							response.getWriter().append("You have successfully paid " + booking.getTrip() + "\n");							
							booking.paid();
							response.getWriter().append("Status = COMPLETED\n");
							session.invalidate();
							return;
						}
						else {
							response.getWriter().append("Invalid payment (invalid cookie)\n");
							response.getWriter().append("Status = PAYMENT\n");
							return;
						}
						
					}								
				}
				response.getWriter().append("Invalid payment (no cookie)\n");
				response.getWriter().append("Status = PAYMENT\n");
				return;
				
			}			
			
			response.getWriter().append("Unknow error\n");
			return;
		}
		else {
			// session was not created
			// check for name and trip for book 
			String name = request.getParameter("name");
			String trip = request.getParameter("trip");
			
			if ( trip == null || name == null ) {
				// client did not sent parameters				
				response.getWriter().append("Cannot retrive parameters from request\n");
				return;
			}
			
			session = request.getSession(true);
			// create session
			if( session == null ) {
				response.getWriter().append("Cannot created session\n");
				return;
			}
			// create booking Status = NEW
			Booking booking = new Booking(name, trip);
			session.setAttribute("booking", booking);
			response.getWriter().append("Hello " + booking.getName() + ", you have booked " + booking.getTrip() + " trip\n");
			response.getWriter().append("Status = NEW\n");									
		}									
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
