package Payments;

import Sums.Sum;

/**
 * @author Andrew
 */
public class ByMoney extends Payment{
    Sum paid;
    
    @Override
    public String GetType(){
    return "Наличными";
    }
    
    public ByMoney(Sum paid, Sum sum) throws PaymentException{
        super(sum);
        if(this.sum.greater(paid))
            throw new MoneyException();
        this.paid = paid;
    }
    public Sum getPaid(){
        return paid;
    }
    @Override
    public String toString(){
        return GetType() + " Заплачено: " + paid;
    }
}
