package MainPack;

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
    NavigableSet<Record> records;
    List<Purchase> purchases; 
    
    History(){
        records = new TreeSet<Record>(new RecCompare());
        purchases = new LinkedList<Purchase>();
    }
    
    void addRecord(Date date, GasType gtype){
        try{
        find(date).getDataBase().add(gtype);
        }catch(NotFoundException e){
            Record record = new Record(date);
            record.getDataBase().add(gtype);
            records.add(record);
        }
    }
    void addRecord(Date date, AddService service){
        try{
        find(date).getDataBase().add(service);
        }catch(NotFoundException e){
            Record record = new Record(date);
            record.getDataBase().add(service);
            records.add(record);
        }
    }
    void addRecords(Collection<Record> records){    //может нужно доработать метод(отсутствует проверка, потенциально)
        this.records.addAll(records);               //можно занести что угодно
    }
    
    Record find(Date date) throws NotFoundException{
        for(Record rd: records)
            if(rd.getDate().equals(date))
                return rd;
        throw new NotFoundException();
    }
    void createRecords(DataBase lastDBase, ConstantDataBase cdata){
        
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