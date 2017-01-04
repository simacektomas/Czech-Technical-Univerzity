package mi.mdw.service.general;

import javax.jws.*;

@WebService(name="GeneralBookingWS")
public class GeneralBookingWS {
 
    @WebMethod(operationName="makeBooking")
    @WebResult(name="result")
    public String makeBooking(@WebParam(name="type") String type, @WebParam(name="name") String name, @WebParam(name="destination") String destination){
        return null;
    }
}