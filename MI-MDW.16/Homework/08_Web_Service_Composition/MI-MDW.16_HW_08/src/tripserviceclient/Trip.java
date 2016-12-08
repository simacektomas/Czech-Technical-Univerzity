/**
 * Trip.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package tripserviceclient;

public class Trip  implements java.io.Serializable {

	private int capacity;

    private java.lang.String destination;

    private int id;

    private java.lang.String instructor;

    private int occupied;

    public Trip() {
    }

    public Trip(
           int capacity,
           java.lang.String destination,
           int id,
           java.lang.String instructor,
           int occupied) {
           this.capacity = capacity;
           this.destination = destination;
           this.id = id;
           this.instructor = instructor;
           this.occupied = occupied;
    }


    /**
     * Gets the capacity value for this Trip.
     * 
     * @return capacity
     */
    public int getCapacity() {
        return capacity;
    }


    /**
     * Sets the capacity value for this Trip.
     * 
     * @param capacity
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }


    /**
     * Gets the destination value for this Trip.
     * 
     * @return destination
     */
    public java.lang.String getDestination() {
        return destination;
    }


    /**
     * Sets the destination value for this Trip.
     * 
     * @param destination
     */
    public void setDestination(java.lang.String destination) {
        this.destination = destination;
    }


    /**
     * Gets the id value for this Trip.
     * 
     * @return id
     */
    public int getId() {
        return id;
    }


    /**
     * Sets the id value for this Trip.
     * 
     * @param id
     */
    public void setId(int id) {
        this.id = id;
    }


    /**
     * Gets the instructor value for this Trip.
     * 
     * @return instructor
     */
    public java.lang.String getInstructor() {
        return instructor;
    }


    /**
     * Sets the instructor value for this Trip.
     * 
     * @param instructor
     */
    public void setInstructor(java.lang.String instructor) {
        this.instructor = instructor;
    }


    /**
     * Gets the occupied value for this Trip.
     * 
     * @return occupied
     */
    public int getOccupied() {
        return occupied;
    }


    /**
     * Sets the occupied value for this Trip.
     * 
     * @param occupied
     */
    public void setOccupied(int occupied) {
        this.occupied = occupied;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof Trip)) return false;
        Trip other = (Trip) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            this.capacity == other.getCapacity() &&
            ((this.destination==null && other.getDestination()==null) || 
             (this.destination!=null &&
              this.destination.equals(other.getDestination()))) &&
            this.id == other.getId() &&
            ((this.instructor==null && other.getInstructor()==null) || 
             (this.instructor!=null &&
              this.instructor.equals(other.getInstructor()))) &&
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
        _hashCode += getCapacity();
        if (getDestination() != null) {
            _hashCode += getDestination().hashCode();
        }
        _hashCode += getId();
        if (getInstructor() != null) {
            _hashCode += getInstructor().hashCode();
        }
        _hashCode += getOccupied();
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(Trip.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://tripservice/", "trip"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("capacity");
        elemField.setXmlName(new javax.xml.namespace.QName("", "capacity"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "int"));
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
        elemField.setFieldName("instructor");
        elemField.setXmlName(new javax.xml.namespace.QName("", "instructor"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setMinOccurs(0);
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
		return "Trip [capacity=" + capacity + ", destination=" + destination + ", id=" + id + ", instructor="
				+ instructor + ", occupied=" + occupied + "]";
	}
    
    

}
