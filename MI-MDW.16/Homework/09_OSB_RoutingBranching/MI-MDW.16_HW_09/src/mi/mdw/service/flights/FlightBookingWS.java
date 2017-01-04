package mi.mdw.service.flights;

import java.util.ArrayList;
import java.util.List;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;

import entities.Flight;
import entities.FlightBooking;

@WebService(name="FlightBookingWS")
public class FlightBookingWS {
	private static int lastBookingId = 0;
    private static List<FlightBooking> lBookings = new ArrayList<FlightBooking>();
    private static List<Flight> lFlights = new ArrayList<Flight>();
    
    @WebMethod(operationName="makeFlightBooking")
    @WebResult(name="result")
    public Flight addFlightBooking(@WebParam(name="customerName") String name, @WebParam(name="flightDestination") String destination){
        for(int i = 0; i < lFlights.size(); i++)
                if(lFlights.get(i).getDestination().equals(destination)){
                        //We have trip to book
                        Flight flight = lFlights.get(i);
                        if(flight.getOccupied() < flight.getCapacity()){
                                //flight has capacity, create booking
                                FlightBooking newBooking = new FlightBooking(lastBookingId,
                                                                             flight.getId(),
                                                                             name,
                                                                             destination);
                                lastBookingId++;
                                flight.setOccupied(flight.getOccupied()+1); // increment occupied status
                                lBookings.add(newBooking);
                                System.out.println(newBooking.toString());
                                System.out.println(flight);
                                return flight;
                        }
                        //not enough capacity
                        continue;
                }
        System.out.println("Nothing");
        return null;
    }
    
    @WebMethod(operationName="addFlight")
    @WebResult(name="result")    
    public int addFlight(Flight flight){
        for(int i = 0; i < lFlights.size(); i++)
                if(flight.getId() == lFlights.get(i).getId())
                        return 1;
        lFlights.add(flight);
        return 0;
    }
}
