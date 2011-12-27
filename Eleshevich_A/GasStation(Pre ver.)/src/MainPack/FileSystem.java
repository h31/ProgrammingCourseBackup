package MainPack;

import Histories.Purchase;
import Histories.History;
import Histories.Record;
import DataBases.DataBase;
import BankSystems.Account;
import DataHandlers.*;
import Payments.ByCard;
import Payments.ByMoney;
import Services.*;
import Sums.Sum;
import java.io.*;
import java.util.Collection;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.SAXNotRecognizedException;
/**
 * @author Andrew
 */
public class FileSystem {
    File FConstData;
    File FRecordsData;
    File FPurchasesData;
    File FBankData;
    
    static final String JAXP_SCHEMA_LANGUAGE = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
    static final String W3C_XML_SCHEMA = "http://www.w3.org/2001/XMLSchema";
        //мы в какие то файлы ещё будем писать возможно нужно подправить проверки
    FileSystem(String const_name, String record_name, String purch_name, String bank_name) throws FileException{
        FConstData = new File(const_name);
        if(!FConstData.isFile())
            throw new FileException(FileException.ftype.constant, FileException.error.exist);
        if(!FConstData.canRead())
            throw new FileException(FileException.ftype.constant, FileException.error.can_read);
        FRecordsData = new File(record_name);
        if(!FRecordsData.isFile())
            throw new FileException(FileException.ftype.records, FileException.error.exist);
        if(!FRecordsData.canRead())
            throw new FileException(FileException.ftype.records, FileException.error.can_read);
        FPurchasesData = new File(purch_name);
        if(!FPurchasesData.isFile())
            throw new FileException(FileException.ftype.purchases, FileException.error.exist);
        if(!FPurchasesData.canRead())
            throw new FileException(FileException.ftype.purchases, FileException.error.can_read);
        if(!FPurchasesData.canWrite())
            throw new FileException(FileException.ftype.purchases, FileException.error.can_write);
        FBankData = new File(bank_name);
        if(!FBankData.isFile())
            throw new FileException(FileException.ftype.bank, FileException.error.exist);
        if(!FBankData.canRead())
            throw new FileException(FileException.ftype.bank, FileException.error.can_read);
        if(!FBankData.canWrite())
            throw new FileException(FileException.ftype.bank, FileException.error.can_write);
    }
    
    public void loadConstData(Collection<GasType> gastypes, Collection<AddService> services,
            Collection<FillingSt> fstations){
        try{
        ConstDataHandler chandler = new ConstDataHandler();
        SAXParserFactory fact = SAXParserFactory.newInstance();
        fact.setNamespaceAware(true);
        fact.setValidating(true);
        SAXParser saxParser = fact.newSAXParser();
        saxParser.setProperty(JAXP_SCHEMA_LANGUAGE, W3C_XML_SCHEMA);
        saxParser.parse(FConstData, chandler);
        gastypes.addAll(chandler.getLoadedGasTypes());
        services.addAll(chandler.getLoadedServices());
        fstations.addAll(chandler.getLoadedStations());
        }catch(SAXNotRecognizedException e){
            System.err.println("Неизестное свойство: " + JAXP_SCHEMA_LANGUAGE);
        }catch(Exception e){
            System.err.println(e.getMessage());
        }
    }    
    public Sum loadRecords(Collection<Record> records, DataBase lastDataBase) throws FileException{    //предусмотреть выбрасывание исключения дальше
        try{
        RecordsDataHandler rhandler = new RecordsDataHandler(lastDataBase);
        SAXParserFactory fact = SAXParserFactory.newInstance();
        fact.setNamespaceAware(true);
        fact.setValidating(true);
        SAXParser saxParser = fact.newSAXParser();
        saxParser.setProperty(JAXP_SCHEMA_LANGUAGE, W3C_XML_SCHEMA);
        saxParser.parse(FRecordsData, rhandler);
        records.addAll(rhandler.getLoadedRecords());
        return rhandler.getExpence();
        }catch(SAXNotRecognizedException e){
            System.err.println("Неизестное свойство: " + JAXP_SCHEMA_LANGUAGE);
        }catch(Exception e){
            System.err.println(e.getMessage());
        }
        throw new FileException(FileException.ftype.records, FileException.error.correct);
    }
    public void loadPurchases(Collection<Purchase> purchases, DataBase base, History hist) throws FileException{
        try{
        PurchasesDataHandler phandler = new PurchasesDataHandler(base, hist);
        SAXParserFactory fact = SAXParserFactory.newInstance();
        fact.setNamespaceAware(true);
        fact.setValidating(true);
        SAXParser saxParser = fact.newSAXParser();
        saxParser.setProperty(JAXP_SCHEMA_LANGUAGE, W3C_XML_SCHEMA);
        saxParser.parse(FPurchasesData, phandler);
        purchases.addAll(phandler.getLoadedPurchases());
        }catch(SAXNotRecognizedException e){
            System.err.println("Неизестное свойство: " + JAXP_SCHEMA_LANGUAGE);
        }catch(Exception e){
            System.err.println(e.getMessage());
        }
    }
    public void loadAccounts(Collection<Account> accounts) throws FileException{
        try{
        BankDataHandler bhandler = new BankDataHandler();
        SAXParserFactory fact = SAXParserFactory.newInstance();
        fact.setNamespaceAware(true);
        fact.setValidating(true);
        SAXParser saxParser = fact.newSAXParser();
        saxParser.setProperty(JAXP_SCHEMA_LANGUAGE, W3C_XML_SCHEMA);
        saxParser.parse(FBankData, bhandler);
        accounts.addAll(bhandler.getLoadedAccounts());
        }catch(SAXNotRecognizedException e){
            System.err.println("Неизестное свойство: " + JAXP_SCHEMA_LANGUAGE);
        }catch(Exception e){
            System.err.println(e.getMessage());
        }
    }
    public void savePurchases(Collection<Purchase> purchases){
        try{
            BufferedWriter dos = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FPurchasesData)));
            dos.write(Tags.pref + "\n");
            dos.write("<" + Tags.purdatbs + " " + Tags.mainattrs + Tags.purchschema + "\">\n");
            for(Purchase purch: purchases){
                dos.write("<" + Tags.pur +" date=\"" + purch.getDate().getTime() + "\">\n");
                dos.write("<" + Tags.gaslst + ">\n");
                for(Service serv: purch.getServices()){
                    if(serv.getClass().getName().equals("Services.Gas")){
                        dos.write("<" + Tags.gas + " ID=\"" + ((Gas)serv).getType().getID() + "\" amount=\"" + ((Gas)serv).getAmount() + "\" />\n");
                    }
                }
                dos.write("</" + Tags.gaslst + ">\n");
                dos.write("<" + Tags.srvids + ">\n");
                for(Service serv: purch.getServices()){
                    if(serv.getClass().getName().equals("Services.AddService")){
                        dos.write(((AddService)serv).getID() + " ");
                    }
                }
                dos.write("\n</" + Tags.srvids + ">\n");
                if(purch.getPayment().getClass().getName().equals("Payments.ByCard")){
                    dos.write("<" + Tags.pbank + " cnumber=\"" + ((ByCard)purch.getPayment()).getCardNumber() + "\" />\n");
                }else if(purch.getPayment().getClass().getName().equals("Payments.ByMoney")){
                    dos.write("<" + Tags.pmoney + " paid=\"" + ((ByMoney)purch.getPayment()).getPaid() + "\" />\n");
                }
                dos.write("</" + Tags.pur + ">\n");
            }
            dos.write("</" + Tags.purdatbs + ">");
            dos.close();
        }catch(IOException e){}
    }
    public void saveRecords(Collection<Record> records, DataBase lastDataBase, Sum expence){
        try{
            BufferedWriter dos = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FRecordsData)));
            dos.write(Tags.pref + "\n");
            dos.write("<" + Tags.hist + " " + Tags.mainattrs + Tags.recschema + "\">\n");
            dos.write("<" + Tags.reclst + ">\n");
            for(Record rec: records){
                dos.write("<" + Tags.rec + " date=\"" + rec.getDate().getTime() + "\">\n");
                dos.write("<" + Tags.gtlst + ">\n");
                for(GasType gt: rec.getDataBase().getGasTypes()){
                    dos.write("<" + Tags.gt + " name=\"" + gt.getName() + "\" price=\"" + gt.getCost() + "\" ID=\"" + gt.getID() + "\" />\n");
                }
                dos.write("</" + Tags.gtlst + ">\n");
                dos.write("<" + Tags.srvlst + ">\n");
                for(AddService srv: rec.getDataBase().getServices()){
                    dos.write("<" + Tags.srv + " name=\"" + srv.getName() + "\" price=\"" + srv.getCost() + "\" ID=\"" + srv.getID() + "\" />\n");
                }
                dos.write("</" + Tags.srvlst + ">\n");
                dos.write("</" + Tags.rec + ">\n");
            }
            dos.write("</" + Tags.reclst + ">\n");
            dos.write("<" + Tags.lastdatbs + ">\n");
            dos.write("<" + Tags.gtlst + ">\n");
            for(GasType gt: lastDataBase.getGasTypes()){
                dos.write("<" + Tags.gt + " name=\"" + gt.getName() + "\" price=\"" + gt.getCost() + "\" ID=\"" + gt.getID() + "\" />\n");
            }
            dos.write("</" + Tags.gtlst + ">\n");
            dos.write("<" + Tags.srvlst + ">\n");
            for(AddService srv: lastDataBase.getServices()){
                dos.write("<" + Tags.srv + " name=\"" + srv.getName() + "\" price=\"" + srv.getCost() + "\" ID=\"" + srv.getID() + "\" />\n");
            }
            dos.write("</" + Tags.srvlst + ">\n");
            dos.write("</" + Tags.lastdatbs + ">\n");
            dos.write("<" + Tags.exp + " sum=\"" + expence + "\" />\n");
            dos.write("</" + Tags.hist + ">");
            dos.close();
        }catch(IOException e){System.out.println(e.getMessage());}
    }
    public void saveBankData(Collection<Account> accounts){
        try{
            BufferedWriter dos = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(FBankData)));
            dos.write(Tags.pref + "\n");
            dos.write("<" + Tags.clbs + " " + Tags.mainattrs + Tags.bankschema + "\">\n");
            for(Account acc: accounts){
                dos.write("<" + Tags.acc + " name=\"" + acc.getName() + "\" cash=\"" + acc.getCash() + "\" number=\"" + acc.getNumber() + "\" />\n");
            }
            dos.write("</" + Tags.clbs + ">");
            dos.close();
        }catch(IOException e){}
    }
}

class FileException extends Exception{
    enum ftype { constant, records, purchases, bank }
    enum error { exist, can_read, can_write, correct }
    
    ftype ft;
    error err;
    @Override
    public String getMessage(){
        String result = "";
        switch(err){
            case exist: result += "Невозможно найти файл"; break;
            case can_read: result += "Невозможно прочесть данные из файла"; break;
            case can_write: result += "Невозможно записать данные в файл"; break;
            case correct: result += "Некорректный формат входного файла"; break;
        }
        switch(ft){
            case constant: result += " - база данных: виды бензина, услуги, цены, колонки"; break;
            case records: result += " для записи/чтения истории цен"; break;
            case purchases: result += " для записи/чтения покупок"; break;
            case bank: result += " - база банковских данных"; break;
        }
        return result;
    }
    
    FileException(ftype ft, error err){
        this.ft = ft;
        this.err = err;
    }
}