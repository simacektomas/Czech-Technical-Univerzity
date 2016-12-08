package entities;

import java.util.Date;

public class FlightBooking {
	
	private int id;
	private String passenger;
	private Date departure;
	private Date arrival;
	private String dairport;
	private String aairport;
	
	FlightBooking(){}
	FlightBooking(int id, String passenger, Date departure, Date arrival, String dairport, String aairport){
		this.setId(id);
		this.setPassenger(passenger);
		this.setDeparture(departure);
		this.setArrival(arrival);
		this.setDairport(dairport);
		this.setAairport(aairport);
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getPassenger() {
		return passenger;
	}
	public void setPassenger(String passenger) {
		this.passenger = passenger;
	}
	public Date getDeparture() {
		return departure;
	}
	public void setDeparture(Date departure) {
		this.departure = departure;
	}
	public Date getArrival() {
		return arrival;
	}
	public void setArrival(Date arrival) {
		this.arrival = arrival;
	}
	public String getDairport() {
		return dairport;
	}
	public void setDairport(String dairport) {
		this.dairport = dairport;
	}
	public String getAairport() {
		return aairport;
	}
	public void setAairport(String aairport) {
		this.aairport = aairport;
	}
}
