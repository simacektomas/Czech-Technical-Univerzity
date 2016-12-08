package flightserviceclient;

public class TravelAgencyFlightsProxy implements flightserviceclient.TravelAgencyFlights {
  private String _endpoint = null;
  private flightserviceclient.TravelAgencyFlights travelAgencyFlights = null;
  
  public TravelAgencyFlightsProxy() {
    _initTravelAgencyFlightsProxy();
  }
  
  public TravelAgencyFlightsProxy(String endpoint) {
    _endpoint = endpoint;
    _initTravelAgencyFlightsProxy();
  }
  
  private void _initTravelAgencyFlightsProxy() {
    try {
      travelAgencyFlights = (new flightserviceclient.TravelAgencyFlightsServiceLocator()).getTravelAgencyFlightsPort();
      if (travelAgencyFlights != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)travelAgencyFlights)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)travelAgencyFlights)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (travelAgencyFlights != null)
      ((javax.xml.rpc.Stub)travelAgencyFlights)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public flightserviceclient.TravelAgencyFlights getTravelAgencyFlights() {
    if (travelAgencyFlights == null)
      _initTravelAgencyFlightsProxy();
    return travelAgencyFlights;
  }
  
  public int addFlight(flightserviceclient.Flight arg0) throws java.rmi.RemoteException{
    if (travelAgencyFlights == null)
      _initTravelAgencyFlightsProxy();
    return travelAgencyFlights.addFlight(arg0);
  }
  
  public flightserviceclient.Flight addFlightBooking(flightserviceclient.Booking arg0) throws java.rmi.RemoteException{
    if (travelAgencyFlights == null)
      _initTravelAgencyFlightsProxy();
    return travelAgencyFlights.addFlightBooking(arg0);
  }
  
  
}