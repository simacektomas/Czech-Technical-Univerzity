package servers;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;

import enums.Currency;
import interfaces.CurrencyConverter;

public class RMIServer extends UnicastRemoteObject implements CurrencyConverter {

	protected RMIServer() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	private static final long serialVersionUID = 1L;

	@Override
	public double convert(Currency from, Currency to, double amount) throws RemoteException {
		// TODO Auto-generated method stub
		double convert;
		switch(to) {
			case EUR:
				convert = from.getEur(amount);
				break;
			case USD:
				convert = from.getUsd(amount);
				break;
			case GPB:
				convert = from.getGpb(amount);
				break;
			default:
				convert = Double.NaN;
				break;
		}
		return convert;		
	}
	public static void main(String[] args) {
        try {                      
            LocateRegistry.createRegistry(1099);
 
            RMIServer server = new RMIServer();
            Naming.rebind("//0.0.0.0/Hello", server);
 
            System.out.println("Server started...");
 
        } catch (Exception e) {
            System.out.println("Error: " + e.getLocalizedMessage());
        }
 
    }

}
