package Payments;

import MainPack.Sum;

/**
 * @author Andrew
 */
public abstract class Payment{
    Sum sum;
    Payment(Sum sum){
        this.sum = sum;
    }
    abstract String GetType();
}

class MoneyException extends PaymentException{
    @Override
    public String getMessage(){
        return "Нехватает денег для оплаты";
    }
}