/**
 * TravelAgencyTripsServiceLocator.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package tripserviceclient;

public class TravelAgencyTripsServiceLocator extends org.apache.axis.client.Service implements tripserviceclient.TravelAgencyTripsService {

    public TravelAgencyTripsServiceLocator() {
    }


    public TravelAgencyTripsServiceLocator(org.apache.axis.EngineConfiguration config) {
        super(config);
    }

    public TravelAgencyTripsServiceLocator(java.lang.String wsdlLoc, javax.xml.namespace.QName sName) throws javax.xml.rpc.ServiceException {
        super(wsdlLoc, sName);
    }

    // Use to get a proxy class for TravelAgencyTripsPort
    private java.lang.String TravelAgencyTripsPort_address = "http://0.0.0.0:7001/MI-MDW.16_HW_08/TravelAgencyTripsService";

    public java.lang.String getTravelAgencyTripsPortAddress() {
        return TravelAgencyTripsPort_address;
    }

    // The WSDD service name defaults to the port name.
    private java.lang.String TravelAgencyTripsPortWSDDServiceName = "TravelAgencyTripsPort";

    public java.lang.String getTravelAgencyTripsPortWSDDServiceName() {
        return TravelAgencyTripsPortWSDDServiceName;
    }

    public void setTravelAgencyTripsPortWSDDServiceName(java.lang.String name) {
        TravelAgencyTripsPortWSDDServiceName = name;
    }

    public tripserviceclient.TravelAgencyTrips getTravelAgencyTripsPort() throws javax.xml.rpc.ServiceException {
       java.net.URL endpoint;
        try {
            endpoint = new java.net.URL(TravelAgencyTripsPort_address);
        }
        catch (java.net.MalformedURLException e) {
            throw new javax.xml.rpc.ServiceException(e);
        }
        return getTravelAgencyTripsPort(endpoint);
    }

    public tripserviceclient.TravelAgencyTrips getTravelAgencyTripsPort(java.net.URL portAddress) throws javax.xml.rpc.ServiceException {
        try {
            tripserviceclient.TravelAgencyTripsPortBindingStub _stub = new tripserviceclient.TravelAgencyTripsPortBindingStub(portAddress, this);
            _stub.setPortName(getTravelAgencyTripsPortWSDDServiceName());
            return _stub;
        }
        catch (org.apache.axis.AxisFault e) {
            return null;
        }
    }

    public void setTravelAgencyTripsPortEndpointAddress(java.lang.String address) {
        TravelAgencyTripsPort_address = address;
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        try {
            if (tripserviceclient.TravelAgencyTrips.class.isAssignableFrom(serviceEndpointInterface)) {
                tripserviceclient.TravelAgencyTripsPortBindingStub _stub = new tripserviceclient.TravelAgencyTripsPortBindingStub(new java.net.URL(TravelAgencyTripsPort_address), this);
                _stub.setPortName(getTravelAgencyTripsPortWSDDServiceName());
                return _stub;
            }
        }
        catch (java.lang.Throwable t) {
            throw new javax.xml.rpc.ServiceException(t);
        }
        throw new javax.xml.rpc.ServiceException("There is no stub implementation for the interface:  " + (serviceEndpointInterface == null ? "null" : serviceEndpointInterface.getName()));
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(javax.xml.namespace.QName portName, Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        if (portName == null) {
            return getPort(serviceEndpointInterface);
        }
        java.lang.String inputPortName = portName.getLocalPart();
        if ("TravelAgencyTripsPort".equals(inputPortName)) {
            return getTravelAgencyTripsPort();
        }
        else  {
            java.rmi.Remote _stub = getPort(serviceEndpointInterface);
            ((org.apache.axis.client.Stub) _stub).setPortName(portName);
            return _stub;
        }
    }

    public javax.xml.namespace.QName getServiceName() {
        return new javax.xml.namespace.QName("http://tripservice/", "TravelAgencyTripsService");
    }

    private java.util.HashSet ports = null;

    public java.util.Iterator getPorts() {
        if (ports == null) {
            ports = new java.util.HashSet();
            ports.add(new javax.xml.namespace.QName("http://tripservice/", "TravelAgencyTripsPort"));
        }
        return ports.iterator();
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(java.lang.String portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        
if ("TravelAgencyTripsPort".equals(portName)) {
            setTravelAgencyTripsPortEndpointAddress(address);
        }
        else 
{ // Unknown Port Name
            throw new javax.xml.rpc.ServiceException(" Cannot set Endpoint Address for Unknown Port" + portName);
        }
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(javax.xml.namespace.QName portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        setEndpointAddress(portName.getLocalPart(), address);
    }

}
