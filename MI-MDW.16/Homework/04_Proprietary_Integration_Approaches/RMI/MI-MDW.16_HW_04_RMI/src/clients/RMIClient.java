package clients;

import java.rmi.Naming;

import enums.Currency;
import interfaces.CurrencyConverter;

public class RMIClient {
	public static void main(String[] args) throws Exception{
        CurrencyConverter client = (CurrencyConverter)Naming.lookup("//localhost/Currency");
        // No need to Currency have to implemets Serializable because only double come from server.
        double amount = 200, result;
        // EUR to GPB
        result = client.convert(Currency.EUR, Currency.GPB, amount);
        System.out.println("Conversion from " + amount + " EUR to " + result + " GPB");
        // EUR to USD
        amount = 150;
        result = client.convert(Currency.EUR, Currency.USD, amount);
        System.out.println("Conversion from " + amount + " EUR to " + result + " USD");
        // EUR to EUR
        amount = 100;
        result = client.convert(Currency.EUR, Currency.EUR, amount);
        System.out.println("Conversion from " + amount + " EUR to " + result + " EUR");
        
        // USD to GPB
        amount = 200;
        result = client.convert(Currency.USD, Currency.GPB, amount);
        System.out.println("Conversion from " + amount + " USD to " + result + " GPB");
        // USD to USD
        amount = 150;
        result = client.convert(Currency.USD, Currency.EUR, amount);
        System.out.println("Conversion from " + amount + " USD to " + result + " EUR");
        // USD to EUR
        amount = 100;
        result = client.convert(Currency.USD, Currency.USD, amount);
        System.out.println("Conversion from " + amount + " USD to " + result + " USD");
        
        // GPB to GPB
        amount = 200;
        result = client.convert(Currency.GPB, Currency.GPB, amount);
        System.out.println("Conversion from " + amount + " GPB to " + result + " GPB");
        // GPB to USD
        amount = 150;
        result = client.convert(Currency.GPB, Currency.USD, amount);
        System.out.println("Conversion from " + amount + " GPB to " + result + " USD");
        // GPB to EUR
        amount = 100;
        result = client.convert(Currency.GPB, Currency.EUR, amount);
        System.out.println("Conversion from " + amount + " GPB to " + result + " EUR");
        
    }
}
