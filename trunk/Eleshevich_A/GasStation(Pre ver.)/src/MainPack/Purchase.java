package MainPack;

/**
 * @author Andrew
 */

import Payments.Payment;
import Services.Service;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;

public class Purchase {
    List<Service> services;
    Payment payment;
    Date date;
    
    public Purchase(Collection<Service> services, Payment payment){
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
}