package enums;

public enum Currency {
	EUR (1, 1.08931, 0.876360),
	USD (0.918068, 1, 0.804558),
	GPB (1.14108, 1.24292, 1);
	
	private final double eur;
	private final double usd;
	private final double gpb;
	
	Currency(double eur, double usd, double gpb) {
		this.eur = eur;
		this.usd = usd;
		this.gpb = gpb;
	}
	
	public double getEur( double amount ) {
		return amount*this.eur;
	}

	public double getUsd( double amount ) {
		return amount*this.usd;
	}

	public double getGpb( double amount ) {
		return amount*this.gpb;
	}
}
