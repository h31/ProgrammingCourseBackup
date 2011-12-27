package DataHandlers;

import DataBases.DataBase;
import Histories.History;
import DataBases.NotFoundException;
import Payments.Payment;
import Histories.Purchase;
import Sums.Sum;
import Services.AddService;
import Services.Gas;
import Services.GasType;
import Services.Service;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;
import Payments.ByCard;
import Payments.ByMoney;
import Payments.PaymentException;

/**
 * @author Andrew
 */
public class PurchasesDataHandler extends DefaultHandler{
    List<Purchase> purchases;
    DataBase base;
    History hist;
    Date tdate;
    Payment tpay;
    boolean inAddsIDs;
    List<Service> services;
    
    public PurchasesDataHandler(DataBase base, History hist){
        this.base = base;
        this.hist = hist;
    }
    @Override
    public void startDocument(){
        purchases = new LinkedList<Purchase>();
    }
    @Override
    public void startElement(String uri, String name, String qname, Attributes attrs){
        if(qname.equals(Tags.pur)){
            tdate = new Date(Long.parseLong(attrs.getValue("date")));
            services = new LinkedList<Service>();
        }else if(qname.equals(Tags.gas)){
            int ID = Integer.parseInt(attrs.getValue("ID"));
            int amount = Integer.parseInt(attrs.getValue("amount"));
            try{
                Gas tgas;
                if(tdate.after(hist.lastRecordDate())){
                    tgas = new Gas(base.getGasType(ID), amount);
                }else {
                    try{
                        GasType gt = hist.getActualGasType(tdate, ID);
                        tgas = new Gas(gt, amount);
                    }catch(NotFoundException e){
                        tgas = new Gas(base.getGasType(ID), amount);
                    }
                }
                services.add(tgas);
            }catch(NotFoundException e){}
        }else if(qname.equals(Tags.srvids)){
            inAddsIDs = true;
        }else if(qname.equals(Tags.pbank)){
            Sum tsum = new Sum(0,0);
            for(Service serv: services){
                tsum = tsum.add(serv.getCost());
            }
            tpay = new ByCard(attrs.getValue("cnumber"), tsum);
        }else if(qname.equals(Tags.pmoney)){
            StringTokenizer st = new StringTokenizer(attrs.getType("paid"), ".");
            Sum paid = new Sum(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            Sum tsum = new Sum(0,0);
            for(Service serv: services){
                tsum = tsum.add(serv.getCost());
            }
            try{
            tpay = new ByMoney(paid, tsum);
            }catch(PaymentException e){System.out.println(e.getMessage());}
        }
    }
    
    @Override
    public void characters(char[] buf, int offset, int len){
        if(inAddsIDs){
            String str = new String(buf, offset, len);
            StringTokenizer st = new StringTokenizer(str);
            while(st.hasMoreTokens()){
                int ID = Integer.parseInt(st.nextToken());
                try{
                    AddService tserv;
                    if(tdate.after(hist.lastRecordDate())){
                        tserv = base.getAddService(ID);
                    }else {
                        try{
                            tserv = hist.getActualAddService(tdate, ID);
                        }catch(NotFoundException e){
                            tserv = base.getAddService(ID);
                        }
                    }
                    services.add(tserv);
                }catch(NotFoundException e){}
            }
            inAddsIDs = false;
        }
    }
    
    @Override
    public void endElement(String uri, String name, String qname){
        if(qname.equals(Tags.pur)){
            purchases.add(new Purchase(services, tpay, tdate));
            services = null;
        }
    }
    public List<Purchase> getLoadedPurchases(){
        return purchases;
    }
}
