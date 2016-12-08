/**
 * TravelAgencyFlightsServiceLocator.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package flightserviceclient;

public class TravelAgencyFlightsServiceLocator extends org.apache.axis.client.Service implements flightserviceclient.TravelAgencyFlightsService {

    public TravelAgencyFlightsServiceLocator() {
    }


    public TravelAgencyFlightsServiceLocator(org.apache.axis.EngineConfiguration config) {
        super(config);
    }

    public TravelAgencyFlightsServiceLocator(java.lang.String wsdlLoc, javax.xml.namespace.QName sName) throws javax.xml.rpc.ServiceException {
        super(wsdlLoc, sName);
    }

    // Use to get a proxy class for TravelAgencyFlightsPort
    private java.lang.String TravelAgencyFlightsPort_address = "http://0.0.0.0:7001/MI-MDW.16_HW_08/TravelAgencyFlightsService";

    public java.lang.String getTravelAgencyFlightsPortAddress() {
        return TravelAgencyFlightsPort_address;
    }

    // The WSDD service name defaults to the port name.
    private java.lang.String TravelAgencyFlightsPortWSDDServiceName = "TravelAgencyFlightsPort";

    public java.lang.String getTravelAgencyFlightsPortWSDDServiceName() {
        return TravelAgencyFlightsPortWSDDServiceName;
    }

    public void setTravelAgencyFlightsPortWSDDServiceName(java.lang.String name) {
        TravelAgencyFlightsPortWSDDServiceName = name;
    }

    public flightserviceclient.TravelAgencyFlights getTravelAgencyFlightsPort() throws javax.xml.rpc.ServiceException {
       java.net.URL endpoint;
        try {
            endpoint = new java.net.URL(TravelAgencyFlightsPort_address);
        }
        catch (java.net.MalformedURLException e) {
            throw new javax.xml.rpc.ServiceException(e);
        }
        return getTravelAgencyFlightsPort(endpoint);
    }

    public flightserviceclient.TravelAgencyFlights getTravelAgencyFlightsPort(java.net.URL portAddress) throws javax.xml.rpc.ServiceException {
        try {
            flightserviceclient.TravelAgencyFlightsPortBindingStub _stub = new flightserviceclient.TravelAgencyFlightsPortBindingStub(portAddress, this);
            _stub.setPortName(getTravelAgencyFlightsPortWSDDServiceName());
            return _stub;
        }
        catch (org.apache.axis.AxisFault e) {
            return null;
        }
    }

    public void setTravelAgencyFlightsPortEndpointAddress(java.lang.String address) {
        TravelAgencyFlightsPort_address = address;
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        try {
            if (flightserviceclient.TravelAgencyFlights.class.isAssignableFrom(serviceEndpointInterface)) {
                flightserviceclient.TravelAgencyFlightsPortBindingStub _stub = new flightserviceclient.TravelAgencyFlightsPortBindingStub(new java.net.URL(TravelAgencyFlightsPort_address), this);
                _stub.setPortName(getTravelAgencyFlightsPortWSDDServiceName());
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
        if ("TravelAgencyFlightsPort".equals(inputPortName)) {
            return getTravelAgencyFlightsPort();
        }
        else  {
            java.rmi.Remote _stub = getPort(serviceEndpointInterface);
            ((org.apache.axis.client.Stub) _stub).setPortName(portName);
            return _stub;
        }
    }

    public javax.xml.namespace.QName getServiceName() {
        return new javax.xml.namespace.QName("http://flightservice/", "TravelAgencyFlightsService");
    }

    private java.util.HashSet ports = null;

    public java.util.Iterator getPorts() {
        if (ports == null) {
            ports = new java.util.HashSet();
            ports.add(new javax.xml.namespace.QName("http://flightservice/", "TravelAgencyFlightsPort"));
        }
        return ports.iterator();
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(java.lang.String portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        
if ("TravelAgencyFlightsPort".equals(portName)) {
            setTravelAgencyFlightsPortEndpointAddress(address);
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
