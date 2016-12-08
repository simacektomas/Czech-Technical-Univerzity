package tripservice;

import java.util.ArrayList;
import java.util.List;

import javax.jws.WebService;

import entities.Booking;
import entities.Trip;
import entities.TripBooking;

@WebService
public class TravelAgencyTrips {
        private static int lastBookingId = 0;
        private static List<TripBooking> lBookings = new ArrayList<TripBooking>();
        private static List<Trip> lTrips = new ArrayList<Trip>();        

        public Trip addTripBooking(Booking booking){
                for(int i = 0; i < lTrips.size(); i++)
                        if(lTrips.get(i).getDestination().equals(booking.getDestination())){
                                //We have trip to book
                                Trip trip = lTrips.get(i);
                                if(trip.getOccupied() < trip.getCapacity()){
                                        //flight has capacity, create booking
                                        TripBooking newBooking = new TripBooking(lastBookingId,
                                                                                 trip.getId(),
                                                                                 booking.getName(),
                                                                                 booking.getDestination());
                                        lastBookingId++;
                                        trip.setOccupied(trip.getOccupied()+1); // increment occupied status
                                        lBookings.add(newBooking);
                                        return trip;
                                }
                                //not enough capacity
                                continue;
                        }
                return null;
        }
        public int addTrip(Trip trip){
                for(int i = 0; i < lTrips.size(); i++)
                        if(trip.getId() == lTrips.get(i).getId())
                                return 1;
                lTrips.add(trip);
                return 0;
        }

}

