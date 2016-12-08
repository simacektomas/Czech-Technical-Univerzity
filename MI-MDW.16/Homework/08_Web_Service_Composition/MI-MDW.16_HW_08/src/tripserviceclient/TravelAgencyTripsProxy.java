package tripserviceclient;

public class TravelAgencyTripsProxy implements tripserviceclient.TravelAgencyTrips {
  private String _endpoint = null;
  private tripserviceclient.TravelAgencyTrips travelAgencyTrips = null;
  
  public TravelAgencyTripsProxy() {
    _initTravelAgencyTripsProxy();
  }
  
  public TravelAgencyTripsProxy(String endpoint) {
    _endpoint = endpoint;
    _initTravelAgencyTripsProxy();
  }
  
  private void _initTravelAgencyTripsProxy() {
    try {
      travelAgencyTrips = (new tripserviceclient.TravelAgencyTripsServiceLocator()).getTravelAgencyTripsPort();
      if (travelAgencyTrips != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)travelAgencyTrips)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)travelAgencyTrips)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (travelAgencyTrips != null)
      ((javax.xml.rpc.Stub)travelAgencyTrips)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public tripserviceclient.TravelAgencyTrips getTravelAgencyTrips() {
    if (travelAgencyTrips == null)
      _initTravelAgencyTripsProxy();
    return travelAgencyTrips;
  }
  
  public int addTrip(tripserviceclient.Trip arg0) throws java.rmi.RemoteException{
    if (travelAgencyTrips == null)
      _initTravelAgencyTripsProxy();
    return travelAgencyTrips.addTrip(arg0);
  }
  
  public tripserviceclient.Trip addTripBooking(tripserviceclient.Booking arg0) throws java.rmi.RemoteException{
    if (travelAgencyTrips == null)
      _initTravelAgencyTripsProxy();
    return travelAgencyTrips.addTripBooking(arg0);
  }
  
  
}