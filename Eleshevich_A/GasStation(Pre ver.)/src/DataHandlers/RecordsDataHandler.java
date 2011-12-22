package DataHandlers;

import MainPack.DataBase;
import MainPack.Record;
import MainPack.Sum;
import Services.AddService;
import Services.GasType;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
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
    
    @Override
    public void startDocument(){
        records = new LinkedList<Record>();
        lastDataBase = new DataBase();
        inRecord = false;
    }
    
    @Override
    public void startElement(String uri, String name, String qname, Attributes attrs){
        if(qname.equals("Record")){
            inRecord = true;
            rDataBase = new DataBase();
            rdate = Long.parseLong(attrs.getValue("date"));
        }else if(qname.equals("GasType") || qname.equals("Service")){
            StringTokenizer st = new StringTokenizer(attrs.getValue("price"), ".");
            Sum tsum = new Sum(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            int tID = Integer.parseInt(attrs.getValue("ID"));
            if(inRecord){
                if(qname.equals("GasType")){
                    rDataBase.add(new GasType(attrs.getValue("name"), tsum, tID));
                }else if(qname.equals("Service")){
                    rDataBase.add(new AddService(attrs.getValue("name"), tsum, tID));
                }
            }else{
                if(qname.equals("GasType")){
                    lastDataBase.add(new GasType(attrs.getValue("name"), tsum, tID));
                }else if(qname.equals("Service")){
                    lastDataBase.add(new AddService(attrs.getValue("name"), tsum, tID));
                }
            }
        }
    }
    
    @Override
    public void endElement(String uri, String name, String qname){
        if(qname.equals("Record")){
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
}