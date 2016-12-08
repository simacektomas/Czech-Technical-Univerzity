/**
 * Flight.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package flightserviceclient;

public class Flight  implements java.io.Serializable {
    private java.lang.String aairport;

    private int capacity;

    private java.lang.String dairport;

    private java.lang.String destination;

    private int id;

    private int occupied;

    public Flight() {
    }

    public Flight(
           java.lang.String aairport,
           int capacity,
           java.lang.String dairport,
           java.lang.String destination,
           int id,
           int occupied) {
           this.aairport = aairport;
           this.capacity = capacity;
           this.dairport = dairport;
           this.destination = destination;
           this.id = id;
           this.occupied = occupied;
    }


    /**
     * Gets the aairport value for this Flight.
     * 
     * @return aairport
     */
    public java.lang.String getAairport() {
        return aairport;
    }


    /**
     * Sets the aairport value for this Flight.
     * 
     * @param aairport
     */
    public void setAairport(java.lang.String aairport) {
        this.aairport = aairport;
    }


    /**
     * Gets the capacity value for this Flight.
     * 
     * @return capacity
     */
    public int getCapacity() {
        return capacity;
    }


    /**
     * Sets the capacity value for this Flight.
     * 
     * @param capacity
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }


    /**
     * Gets the dairport value for this Flight.
     * 
     * @return dairport
     */
    public java.lang.String getDairport() {
        return dairport;
    }


    /**
     * Sets the dairport value for this Flight.
     * 
     * @param dairport
     */
    public void setDairport(java.lang.String dairport) {
        this.dairport = dairport;
    }


    /**
     * Gets the destination value for this Flight.
     * 
     * @return destination
     */
    public java.lang.String getDestination() {
        return destination;
    }


    /**
     * Sets the destination value for this Flight.
     * 
     * @param destination
     */
    public void setDestination(java.lang.String destination) {
        this.destination = destination;
    }


    /**
     * Gets the id value for this Flight.
     * 
     * @return id
     */
    public int getId() {
        return id;
    }


    /**
     * Sets the id value for this Flight.
     * 
     * @param id
     */
    public void setId(int id) {
        this.id = id;
    }


    /**
     * Gets the occupied value for this Flight.
     * 
     * @return occupied
     */
    public int getOccupied() {
        return occupied;
    }


    /**
     * Sets the occupied value for this Flight.
     * 
     * @param occupied
     */
    public void setOccupied(int occupied) {
        this.occupied = occupied;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof Flight)) return false;
        Flight other = (Flight) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.aairport==null && other.getAairport()==null) || 
             (this.aairport!=null &&
              this.aairport.equals(other.getAairport()))) &&
            this.capacity == other.getCapacity() &&
            ((this.dairport==null && other.getDairport()==null) || 
             (this.dairport!=null &&
              this.dairport.equals(other.getDairport()))) &&
            ((this.destination==null && other.getDestination()==null) || 
             (this.destination!=null &&
              this.destination.equals(other.getDestination()))) &&
            this.id == other.getId() &&
            this.occupied == other.getOccupied();
        __equalsCalc = null;
        return _equals;
    }

    private boolean __hashCodeCalc = false;
    public synchronized int hashCode() {
        if (__hashCodeCalc) {
            return 0;
        }
        __hashCodeCalc = true;
        int _hashCode = 1;
        if (getAairport() != null) {
            _hashCode += getAairport().hashCode();
        }
        _hashCode += getCapacity();
        if (getDairport() != null) {
            _hashCode += getDairport().hashCode();
        }
        if (getDestination() != null) {
            _hashCode += getDestination().hashCode();
        }
        _hashCode += getId();
        _hashCode += getOccupied();
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(Flight.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://flightservice/", "flight"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("aairport");
        elemField.setXmlName(new javax.xml.namespace.QName("", "aairport"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setMinOccurs(0);
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("capacity");
        elemField.setXmlName(new javax.xml.namespace.QName("", "capacity"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "int"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("dairport");
        elemField.setXmlName(new javax.xml.namespace.QName("", "dairport"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setMinOccurs(0);
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("destination");
        elemField.setXmlName(new javax.xml.namespace.QName("", "destination"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setMinOccurs(0);
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("id");
        elemField.setXmlName(new javax.xml.namespace.QName("", "id"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "int"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("occupied");
        elemField.setXmlName(new javax.xml.namespace.QName("", "occupied"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "int"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
    }

    /**
     * Return type metadata object
     */
    public static org.apache.axis.description.TypeDesc getTypeDesc() {
        return typeDesc;
    }

    /**
     * Get Custom Serializer
     */
    public static org.apache.axis.encoding.Serializer getSerializer(
           java.lang.String mechType, 
           java.lang.Class _javaType,  
           javax.xml.namespace.QName _xmlType) {
        return 
          new  org.apache.axis.encoding.ser.BeanSerializer(
            _javaType, _xmlType, typeDesc);
    }

    /**
     * Get Custom Deserializer
     */
    public static org.apache.axis.encoding.Deserializer getDeserializer(
           java.lang.String mechType, 
           java.lang.Class _javaType,  
           javax.xml.namespace.QName _xmlType) {
        return 
          new  org.apache.axis.encoding.ser.BeanDeserializer(
            _javaType, _xmlType, typeDesc);
    }

	@Override
	public String toString() {
		return "Flight [aairport=" + aairport + ", capacity=" + capacity + ", dairport=" + dairport + ", destination="
				+ destination + ", id=" + id + ", occupied=" + occupied + "]";
	}
    
    

}
