package service;
import java.util.ArrayList;
import java.util.List;

import javax.jws.WebService;

import entities.FlightBooking;
@WebService
public class TravelAgencyFlights {
	private static List<FlightBooking> lBookings = new ArrayList<FlightBooking>();
	
	public List<FlightBooking> listBookings(){
		return lBookings;
	}
	public int addBooking(FlightBooking booking){
		for(int i = 0; i < lBookings.size(); i++)
			if(booking.getId() == lBookings.get(i).getId())
				return 1;
		lBookings.add(booking);
		return 0;
	}
	public int removeBooking(int id){
		for(int i = 0; i < lBookings.size(); i++)
			if(id == lBookings.get(i).getId()){
				lBookings.remove(i);
				return 0;
			}
		return 1;
	}
	public int updateBooking(FlightBooking booking){
		for(int i = 0; i < lBookings.size(); i++)
			if(booking.getId() == lBookings.get(i).getId()){
				lBookings.remove(i);
				lBookings.add(booking);
				return 0;
			}
		return 1;
	}
}
