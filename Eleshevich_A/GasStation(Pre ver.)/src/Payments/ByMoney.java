package Payments;

import MainPack.Sum;

/**
 * @author Andrew
 */
public class ByMoney extends Payment{
    Sum paid;
    
    @Override
    String GetType(){
    return "Наличными";
    }
    
    public ByMoney(Sum paid, Sum sum) throws PaymentException{
        super(sum);
        if(this.sum.greater(paid))
            throw new MoneyException();
        this.paid = paid;
    }
    @Override
    public String toString(){
        return GetType() + " " + paid;
    }
}
