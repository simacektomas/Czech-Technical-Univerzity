package messages;

import java.io.Serializable;

public class Booking implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int tripId;
	private String name;
	
	public Booking(int tripId, String name) {
		this.setTripId(tripId);
		this.setName(name);
	}
	public int getTripId() {
		return tripId;
	}
	public void setTripId(int tripId) {
		this.tripId = tripId;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String toString() {
		return "TripId: " + this.tripId + ", Name: " + this.name;
	}

}
