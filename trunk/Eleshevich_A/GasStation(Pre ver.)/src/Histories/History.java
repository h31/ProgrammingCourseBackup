package Histories;

import DataBases.NotFoundException;
import DataBases.ConstantDataBase;
import DataBases.DataBase;
import Services.AddService;
import Services.GasType;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NavigableSet;
import java.util.TreeSet;

/**
 * @author Andrew
 */
public class History {
    TreeSet<Record> records;
    List<Purchase> purchases; 
    
    public History(){
        records = new TreeSet<Record>(new RecCompare());
        purchases = new LinkedList<Purchase>();
    }
    
    public void addPurchase(Purchase purch){
        purchases.add(purch);
    }
    public void addPrchases(Collection<Purchase> purchases){
        this.purchases.addAll(purchases);
    }
    public void addRecord(Date date, GasType gtype){
        try{
        find(date).getDataBase().add(gtype);
        }catch(NotFoundException e){
            Record record = new Record(date);
            record.getDataBase().add(gtype);
            records.add(record);
        }
    }
    public void addRecord(Date date, AddService service){
        try{
        find(date).getDataBase().add(service);
        }catch(NotFoundException e){
            Record record = new Record(date);
            record.getDataBase().add(service);
            records.add(record);
        }
    }
    public NavigableSet<Record> getRecords(){
        return records;
    }
    public List<Purchase> getPurchases(){
        return purchases;
    }
    public void addRecords(Collection<Record> records){    //может нужно доработать метод(отсутствует проверка, потенциально)
        this.records.addAll(records);               //можно занести что угодно
    }
    
    public Record find(Date date) throws NotFoundException{
        for(Record rd: records)
            if(rd.getDate().equals(date))
                return rd;
        throw new NotFoundException();
    }
    public NavigableSet<Record> getRecords(Date dt1, Date dt2) throws NotFoundException{
        NavigableSet set = records.subSet(new Record(dt1), true, new Record(dt2), true);
        if(set.isEmpty())
            throw new NotFoundException();
        return set;
    }
    public void createRecords(DataBase lastDBase, ConstantDataBase cdata){
        DataBase rbase = new DataBase();
        Date date = new Date(System.currentTimeMillis());
        for(GasType gt: lastDBase.getGasTypes()){
            try{
                GasType gt2 = cdata.getGasType(gt.getID());
                if(!gt.getName().equals(gt2.getName()) || !gt.getCost().equals(gt2.getCost())){
                    rbase.add(gt);
                }
            }catch(NotFoundException e){
                rbase.add(gt);
            }
        }
        for(AddService srv: lastDBase.getServices()){
            try{
                AddService srv2 = cdata.getAddSevice(srv.getID());
                if(!srv.getName().equals(srv2.getName()) || !srv.getCost().equals(srv2.getCost())){
                    rbase.add(srv);
                }
            }catch(NotFoundException e){
                rbase.add(srv);
            }
        }
        if(!rbase.getGasTypes().isEmpty() || !rbase.getServices().isEmpty())
            records.add(new Record(date, rbase));
    }
    public Date lastDate(){
        return Collections.max(records, new RecCompare()).getDate();
    }
    public GasType getActualGasType(Date date, int ID) throws NotFoundException{
        Record trec = records.higher(new Record(date));
        Iterator<Record> itt = records.tailSet(trec).iterator();
        while(!itt.hasNext()){
            try{
                return itt.next().getDataBase().getGasType(ID);
            }catch(NotFoundException e){}
        }
        throw new NotFoundException();
    }
    public AddService getActualAddService(Date date, int ID) throws NotFoundException{
        Record trec = records.higher(new Record(date));
        Iterator<Record> itt = records.tailSet(trec).iterator();
        while(!itt.hasNext()){
            try{
                return itt.next().getDataBase().getAddSevice(ID);
            }catch(NotFoundException e){}
        }
        throw new NotFoundException();
    }
    class RecCompare implements Comparator{
        @Override
        public int compare(Object obj1, Object obj2){
            Record rec1 = (Record)obj1;
            Record rec2 = (Record)obj2;
            return rec1.getDate().compareTo(rec2.getDate());
        }
    }
}