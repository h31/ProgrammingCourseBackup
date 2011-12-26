package BankSystems;

import Sums.Sum;

/**
 * @author Andrew
 */
public class Account{
    String ClientName;
    String CardNumber;
    Sum CashAmount;
    
    public Account(String name, String number, Sum amount){
        ClientName = name;
        CardNumber = number;
        CashAmount = amount;
    }
    
    public String getName(){
        return ClientName;
    }
    public String getNumber(){
        return CardNumber;
    }
    public Sum getCash(){
        return CashAmount;
    }
}
