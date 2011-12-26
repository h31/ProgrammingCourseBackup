package Payments;

import Sums.Sum;

/**
 * @author Andrew
 */
public abstract class Payment{
    Sum sum;
    public Payment(Sum sum){
        this.sum = sum;
    }
    public Sum getSum(){
        return sum;
    }
    public abstract String GetType();
}

class MoneyException extends PaymentException{
    @Override
    public String getMessage(){
        return "Нехватает денег для оплаты";
    }
}