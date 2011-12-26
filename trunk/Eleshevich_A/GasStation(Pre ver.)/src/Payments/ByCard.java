package Payments;

import BankSystems.BankSystem;
import Sums.Sum;

/**
 * @author Andrew
 */
public class ByCard extends Payment{
    String CardNumber;
    
    @Override
    public String GetType(){
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
    public String getCardNumber(){
        return CardNumber;
    }
    @Override
    public String toString(){
        return GetType() + " номер карты: " + CardNumber;
    }
}
