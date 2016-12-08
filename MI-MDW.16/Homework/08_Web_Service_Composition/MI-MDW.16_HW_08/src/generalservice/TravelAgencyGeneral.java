package generalservice;

import java.rmi.RemoteException;

import javax.jws.WebParam;
import javax.jws.WebService;

import flightserviceclient.Flight;
import flightserviceclient.TravelAgencyFlightsProxy;
import tripserviceclient.TravelAgencyTripsProxy;

@WebService
public class TravelAgencyGeneral {
	
	TravelAgencyFlightsProxy flights = new TravelAgencyFlightsProxy();
	TravelAgencyTripsProxy trips = new TravelAgencyTripsProxy();
	
	public String makeBooking(@WebParam(name = "type") String type, @WebParam(name = "name")String name, @WebParam(name = "destination") String destination){	
		System.out.println(type + " " + name + " " + destination);
		if(type.equals("flight")){	
			Flight flight = null;
			try {
				flight = flights.addFlightBooking(new flightserviceclient.Booking(destination, name, type));
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if (flight != null){
				return flight.toString();
			}
			return "No available fligh booking for destination " + destination;
		}
		else if (type.equals("trip")){
			tripserviceclient.Trip trip = null;		
			try {
				trip = trips.addTripBooking(new tripserviceclient.Booking(destination, name, type));
			} catch (RemoteException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if (trip != null){
				return trip.toString();
			}
			return "No available trip booking for destination " + destination;
		}
		return "Invalid booking type. Use 'trip' or 'flight'.";
	}
}
