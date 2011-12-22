package MainPack;

import DataHandlers.*;
import Services.AddService;
import Services.GasType;
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
    
    public DataBase loadRecords(Collection<Record> records) throws FileException{    //предусмотреть выбрасывание исключения дальше
        try{
        RecordsDataHandler rhandler = new RecordsDataHandler();
        SAXParserFactory fact = SAXParserFactory.newInstance();
        fact.setNamespaceAware(true);
        fact.setValidating(true);
        SAXParser saxParser = fact.newSAXParser();
        saxParser.setProperty(JAXP_SCHEMA_LANGUAGE, W3C_XML_SCHEMA);
        saxParser.parse(FRecordsData, rhandler);
        records.addAll(rhandler.getLoadedRecords());
        return rhandler.getlastDataBase();
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
}

class FileException extends Exception{
    enum ftype { constant, records, purchases, bank }
    enum error { exist, can_read, can_write, correct }
    
    ftype ft;
    error err;
    String what(){
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