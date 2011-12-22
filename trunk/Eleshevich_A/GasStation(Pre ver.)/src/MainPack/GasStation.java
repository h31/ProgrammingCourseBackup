package MainPack;

import Services.AddService;
import Services.GasType;
import Services.Service;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Andrew
 */
public class GasStation {
    
    Sum expence;
    BankSystem bank;
    FileSystem fsys;
    History history;
    ConstantDataBase base;
    
    /**
     * @param args В аргументах коммандной строки, задаются имена файлов:
     * файл для загрузки типов бензина, доп услуг и цен на них
     * файл для загрузки бензоколонок
     * файл для сохранения/загрузки покупок
     * файл для сохранения/загрузки истории изменения цен
     * файл для симуляции банковской базы данных
     */
    public static void main(String[] args) {
        String root = "src/Files/";
        String servname = root + "ConstData.xml";
        String fillname = root + "RecordsBase.xml";
        String purchname = root + "PurchaseData.xml";
        String histname = root + "BankData.xml";
        List<GasType> gastypes = new ArrayList<GasType>();
        List<AddService> services = new ArrayList<AddService>();
        List<FillingSt> fstations = new ArrayList<FillingSt>();
        try{
        FileSystem fsystem = new FileSystem(servname, fillname, purchname, histname);
        fsystem.loadConstData(gastypes, services, fstations);
        ConstantDataBase base = new ConstantDataBase();
        base.addGasTypes(gastypes);
        base.addServices(services);
        base.addFsations(fstations);
        for(GasType gt: gastypes){
            System.out.println(gt.getName() + " " + gt.getCost());
        }
        for(AddService sv: services){
            System.out.println(sv.getName() + " " + sv.getCost());
        }
        for(FillingSt st: fstations){
            System.out.println("№" + st.getNumber() + " GasTypes:");
            for(GasType gt: st.getGasTypes()){
                System.out.println(gt.getName() + " " + gt.getCost());
            }
        }
        List<Record> records = new ArrayList<Record>();
        DataBase lastDataBase;
        lastDataBase = fsystem.loadRecords(records);
        History hist = new History();
        hist.addRecords(records);
        System.out.println("Records");
        for(Record rc: hist.records){
            System.out.println(rc.getDate());
            for(GasType gt: rc.getDataBase().getGasTypes()){
                System.out.println(gt.getName() + " " + gt.getCost() + " " + gt.getID());
            }
            for(AddService sv: rc.getDataBase().getServices()){
                System.out.println(sv.getName() + " " + sv.getCost() + " " + sv.getID());
            }
        }
        System.out.println("lastDataBase");
        for(GasType gt: lastDataBase.getGasTypes()){
                System.out.println(gt.getName() + " " + gt.getCost() + " " + gt.getID());
        }
        for(AddService sv: lastDataBase.getServices()){
            System.out.println(sv.getName() + " " + sv.getCost() + " " + sv.getID());
        }
        System.out.println("Purchases");
        List<Purchase> purchases = new ArrayList<Purchase>();
        fsystem.loadPurchases(purchases, base, hist);
        for(Purchase pur: purchases){
            System.out.println(pur.getDate());
            System.out.println(pur.getPayment().toString());
            for(Service sv: pur.getServices()){
                System.out.println(sv.toString());
            }
        }
        }catch(FileException e){System.out.println(e.getMessage()); System.exit(1);}
    }
}
