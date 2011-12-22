package Payments;

import MainPack.BankSystem;
import MainPack.Sum;

/**
 * @author Andrew
 */
public class ByCard extends Payment{
    String CardNumber;
    
    @Override
    String GetType(){
        return "Банковской картой";
    }
    
    public ByCard(BankSystem Bank, String CardNumber, Sum sum) throws PaymentException{
        super(sum);
        Bank.MkPayment(CardNumber, this.sum);
        this.CardNumber = CardNumber;
    }
    
    public ByCard(String CardNumber, Sum sum){
        super(sum);
        this.CardNumber = CardNumber;
    }
    @Override
    public String toString(){
        return GetType() + " " + CardNumber;
    }
}
