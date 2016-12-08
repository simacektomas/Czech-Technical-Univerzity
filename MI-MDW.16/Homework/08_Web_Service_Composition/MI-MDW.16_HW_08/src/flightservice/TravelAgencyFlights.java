package flightservice;

import java.util.ArrayList;
import java.util.List;

import javax.jws.WebService;

import entities.Booking;
import entities.Flight;
import entities.FlightBooking;

@WebService
public class TravelAgencyFlights {
        private static int lastBookingId = 0;
        private static List<FlightBooking> lBookings = new ArrayList<FlightBooking>();
        private static List<Flight> lFlights = new ArrayList<Flight>();

        public Flight addFlightBooking(Booking booking){
                for(int i = 0; i < lFlights.size(); i++)
                        if(lFlights.get(i).getDestination().equals(booking.getDestination())){
                                //We have trip to book
                                Flight flight = lFlights.get(i);
                                if(flight.getOccupied() < flight.getCapacity()){
                                        //flight has capacity, create booking
                                        FlightBooking newBooking = new FlightBooking(lastBookingId,
                                                                                     flight.getId(),
                                                                                     booking.getName(),
                                                                                     booking.getDestination());
                                        lastBookingId++;
                                        flight.setOccupied(flight.getOccupied()+1); // increment occupied status
                                        lBookings.add(newBooking);
                                        return flight;
                                }
                                //not enough capacity
                                continue;
                        }
                return null;
        }
        public int addFlight(Flight flight){
                for(int i = 0; i < lFlights.size(); i++)
                        if(flight.getId() == lFlights.get(i).getId())
                                return 1;
                lFlights.add(flight);
                return 0;
        }
}


