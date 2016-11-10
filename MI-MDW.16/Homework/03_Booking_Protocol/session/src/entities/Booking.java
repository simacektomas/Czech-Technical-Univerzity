package entities;

import enums.Status;

public class Booking {
	private String trip;
	private String name;
	private Status status;
	
	public Booking(String name, String trip){		
		this.trip = trip;
		this.name = name;
		this.status = Status.NEW;
	}
	
	public String getTrip() {
		return trip;
	}
	public void setTrip(String trip) {
		this.trip = trip;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Status getStatus() {
		return status;
	}
	public void setStatus(Status status) {
		this.status = status;
	}
	public void created() {
		this.status = Status.PAYMENT;
	}	
	public void paid() {
		this.status = Status.COMPLETED;
	}
		

}
