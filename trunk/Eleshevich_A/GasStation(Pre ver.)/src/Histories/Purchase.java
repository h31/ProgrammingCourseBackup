package Histories;

/**
 * @author Andrew
 */

import Payments.Payment;
import Payments.PaymentException;
import Services.Service;
import Sums.Sum;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;

public class Purchase {
    List<Service> services;
    Payment payment;
    Date date;
    
    public Purchase(Collection<Service> services, Payment payment) throws InvalidPaymentException{
        Sum sum = new Sum(0, 0);
        for(Service srv: services)
            sum = sum.add(srv.getCost());
        if(!sum.equals(payment.getSum()))
            throw new InvalidPaymentException();
        this.services = new ArrayList<Service>();
        this.services.addAll(services);
        this.payment = payment;
        date = new Date();
    }
    public Purchase(Collection<Service> services, Payment payment, Date date){
        this.services = new ArrayList<Service>();
        this.services.addAll(services);
        this.payment = payment;
        this.date = date;
    }
    public Date getDate(){
        return date;
    }
    public Payment getPayment(){
        return payment;
    }
    public List<Service> getServices(){
        return services;
    }
    class InvalidPaymentException extends PaymentException{
        @Override
        public String getMessage(){
            return "Платёж не соответствует стоимости покупки";
        }
    }
}