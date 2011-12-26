package DataHandlers;

import DataBases.DataBase;
import Histories.Record;
import Sums.Sum;
import Services.AddService;
import Services.GasType;
import Sums.InvalidFormatException;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;

/**
 * @author Andrew
 */
public class RecordsDataHandler extends DefaultHandler{
    List<Record> records;
    DataBase lastDataBase;
    DataBase rDataBase;
    long rdate;
    boolean inRecord;
    Sum expence;
    
    public RecordsDataHandler(DataBase lastDataBase){
        this.lastDataBase = lastDataBase;
    }
    
    @Override
    public void startDocument(){
        records = new LinkedList<Record>();
        inRecord = false;
    }
    
    @Override
    public void startElement(String uri, String name, String qname, Attributes attrs){
        if(qname.equals(Tags.rec)){
            inRecord = true;
            rDataBase = new DataBase();
            rdate = Long.parseLong(attrs.getValue("date"));
        }else if(qname.equals(Tags.gt) || qname.equals(Tags.srv)){
            try{
                Sum tsum = Sum.parseSum(attrs.getValue("price"));
                int tID = Integer.parseInt(attrs.getValue("ID"));
                if(inRecord){
                    if(qname.equals(Tags.gt)){
                        rDataBase.add(new GasType(attrs.getValue("name"), tsum, tID));
                    }else if(qname.equals(Tags.srv)){
                        rDataBase.add(new AddService(attrs.getValue("name"), tsum, tID));
                    }
                }else{
                    if(qname.equals(Tags.gt)){
                        lastDataBase.add(new GasType(attrs.getValue("name"), tsum, tID));
                    }else if(qname.equals(Tags.srv)){
                        lastDataBase.add(new AddService(attrs.getValue("name"), tsum, tID));
                    }
                }
            }catch(InvalidFormatException e){}
        }else if(qname.equals(Tags.exp)){
            try{
                expence = Sum.parseSum(attrs.getValue("sum"));
            }catch(InvalidFormatException e){System.out.println(e.getMessage());}
        }
    }
    
    @Override
    public void endElement(String uri, String name, String qname){
        if(qname.equals(Tags.rec)){
            records.add(new Record(new Date(rdate), rDataBase));
            rDataBase = null;
            inRecord = false;
        }
    }
    public List<Record> getLoadedRecords(){
        return records;
    }
    public DataBase getlastDataBase(){
        return lastDataBase;
    }
    public Sum getExpence(){
        return expence;
    }
}