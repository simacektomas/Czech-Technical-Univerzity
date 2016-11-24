package services;

public class Service {
	private String address;
	private boolean healthy;
	
	public Service(String address){
		this.setAddress(address);
		this.setHealthy(true);
	}

	public boolean isHealthy() {
		return healthy;
	}

	public void setHealthy(boolean healthy) {
		this.healthy = healthy;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}
	
	public String toString() {
		return "Service: " + this.address + "\nHealth: " + this.healthy + "\n"; 
	}
	
	
	
}
