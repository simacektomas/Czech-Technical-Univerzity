package mi.mdw.service.trips;

import java.util.ArrayList;
import java.util.List;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;

import entities.Trip;
import entities.TripBooking;

@WebService(name="TripBookingWS")
public class TripBookingWS {
	private static int lastBookingId = 0;
    private static List<TripBooking> lBookings = new ArrayList<TripBooking>();
    private static List<Trip> lTrips = new ArrayList<Trip>();
    
    @WebMethod(operationName="makeTripBooking")
    @WebResult(name="result")
    public Trip addTripBooking(@WebParam(name="customerName") String name, @WebParam(name="tripDestination") String destination){
        for(int i = 0; i < lTrips.size(); i++)
                if(lTrips.get(i).getDestination().equals(destination)){
                        //We have trip to book
                        Trip trip = lTrips.get(i);
                        if(trip.getOccupied() < trip.getCapacity()){
                                //flight has capacity, create booking
                                TripBooking newBooking = new TripBooking(lastBookingId,
                                                                         trip.getId(),
                                                                         name,
                                                                         destination);
                                lastBookingId++;
                                trip.setOccupied(trip.getOccupied()+1); // increment occupied status
                                lBookings.add(newBooking);
                                System.out.println(newBooking.toString());
                                System.out.println(trip);
                                return trip;
                        }
                        //not enough capacity
                        continue;
                }
        System.out.println("Nothing");
        return null;
    }
    
    @WebMethod(operationName="addTrip")
    @WebResult(name="result")
    public int addTrip(Trip trip){
        for(int i = 0; i < lTrips.size(); i++)
                if(trip.getId() == lTrips.get(i).getId())
                        return 1;
        lTrips.add(trip);
        return 0;
    }

}
