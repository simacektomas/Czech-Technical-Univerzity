package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

import enums.Currency;

public interface CurrencyConverter extends Remote{
	double convert(Currency from, Currency to, double amount) throws RemoteException;
}
