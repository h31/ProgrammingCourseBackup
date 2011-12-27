package MainPack;

import Histories.*;
import DataBases.*;
import BankSystems.*;
import Sums.Sum;
import Payments.*;
import Services.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NavigableSet;

/**
 * @author Andrew
 */
public class GasStation {
    
    static Sum expence;
    static BankSystem bank;
    static FileSystem fsystem;
    static History history;
    static ConstantDataBase base;
    static BufferedReader in;
    static PrintStream out;
    static DateFormat df;
    
    /**
     * @param args В аргументах коммандной строки, задаются имена файлов:
     * файл для загрузки типов бензина, доп услуг и цен на них и бензоколонок
     * файл для сохранения/загрузки записей об изменении цен и последней базы данных
     * файл для сохранения/загрузки покупок
     * файл для симуляции банковской базы данных
     */
    public static void main(String[] args) {
        try{
            String fconst, fhist, fpurch, fbank;
            if(args.length < 4) fbank = "src/Files/BankData.xml";
            else fbank = args[3];
            if(args.length < 3) fpurch = "src/Files/PurchaseData.xml";
            else fpurch = args[2];
            if(args.length < 2) fhist = "src/Files/RecordsBase.xml";
            else fhist = args[1];
            if(args.length < 1) fconst = "src/Files/ConstData.xml";
            else fconst = args[0];
            fsystem = new FileSystem(fconst, fhist, fpurch, fbank);
            expence = new Sum(0, 0);
            base = new ConstantDataBase();
            history = new History();
            bank = new BankSystem();
            in = new BufferedReader(new InputStreamReader(System.in, "Cp1251"));
            df = DateFormat.getDateTimeInstance(DateFormat.SHORT, DateFormat.SHORT);
            out = System.out;
            LoadData();
            mainMenu();
            //tempMenu();
            fsystem.saveBankData(bank.getAccounts());
            fsystem.saveRecords(history.getRecords(), base, expence);
            fsystem.savePurchases(history.getPurchases());
        }catch(Exception e){System.out.println(e.getMessage());}
    }
    static void LoadData() throws FileException{
        List<GasType> gtypes = new ArrayList<GasType>();
        List<AddService> services = new ArrayList<AddService>();
        List<FillingSt> fstations = new ArrayList<FillingSt>();
        fsystem.loadConstData(gtypes, services, fstations);
        base.addGasTypes(gtypes);
        base.addServices(services);
        base.addFsations(fstations);
        List<Record> records = new ArrayList<Record>();
        DataBase lDataBase = new DataBase();
        expence = fsystem.loadRecords(records, lDataBase);
        history.addRecords(records);
        history.createRecords(lDataBase, base);
        List<Purchase> purchases = new ArrayList<Purchase>();
        fsystem.loadPurchases(purchases, base, history);
        history.addPrchases(purchases);
        List<Account> accounts = new ArrayList<Account>();
        fsystem.loadAccounts(accounts);
        bank.addAccounts(accounts);
    }
    static void mainMenu(){
        boolean flag = true;
        while(flag){
            out.println("Главное меню\n");
            out.println("1) Оформить покупку");
            out.println("2) Просмотр истории");
            out.println("3) Завершить работу");
            try{
                switch(enterInt()){
                    case 1: createPurchMenu(); break;
                    case 2: historyMenu(); break;
                    case 3: flag = false;
                }
            }catch(Exception e){}
        } 
    }
    static void createPurchMenu(){
        out.println("Оформление покупки\n");
        List<Service> services = new LinkedList<Service>();
        boolean flag = true;
        Sum sum = new Sum(0, 0);
        while(flag){
            out.println("Добаление услуги");
            out.println("1) Приобретение бензина");
            out.println("2) Приобретение дополнительной услуги");
            out.println("3) Завершить добавление услуг");
            out.println("4) Отменить создание покупки");
            out.println("\nОбщая стоимость: " + sum);
            try{
                switch(enterInt()){
                    case 1: Gas gas = buyGasMenu(); sum = sum.add(gas.getCost()); services.add(gas); break;
                    case 2: AddService srv = selectAddServMenu(base.getServices()); sum = sum.add(srv.getCost()); services.add(srv); break;
                    case 3: flag = false; break;
                    case 4: return;
                }
            }catch(Exception e){}
        }
        try{
            history.addPurchase(new Purchase(services, makePaymentMenu(sum)));
            out.println("Покупка была успешно создана");
        }catch(WasNotSelectedException e){return;}
        catch(PaymentException pe){out.println(pe.getMessage());}
    }
    static Gas buyGasMenu() throws WasNotSelectedException{
        out.println("Покупка бензина");
        GasType gt = selectGasTypeMenu(selectFStationMenu().getGasTypes());
        out.print("Введите желаемое количество бензина: ");
        Gas gas = new Gas(gt, enterInt());
        out.println("Результат выбора:");
        out.println(gas.toString());
        out.println("\nПодтвердить выбор? да/нет");
        boolean flag = true;
        while(flag){
            try{
                String select = in.readLine();
                if(select.equalsIgnoreCase("да"))
                    return gas;
                else if(select.equalsIgnoreCase("нет"))
                    flag = false;
            }catch(IOException e){}
        }
        throw new WasNotSelectedException();
    }
    static AddService selectAddServMenu(List<AddService> services) throws WasNotSelectedException{
        out.println("Выберите доп. услугу");
        int num = 1;
        for(AddService srv: services){
            out.println(num++ + ") " + srv.toString());
        }
        out.println("\n" + num + ") Вернуться назад");
        while(true){
            int sel = enterInt();
            if(sel == num)
                throw new WasNotSelectedException();
            try{
                return services.get(sel - 1);
            }catch(IndexOutOfBoundsException ixe){out.println("Элемента с таким номером нет");}
            catch(Exception e){}
        }
    }
    static int enterInt(){
        while(true){
            try{
                return Integer.parseInt(in.readLine());
            }catch(Exception e){out.println("Некорректный ввод данных, попробуйте ещё");}
        }
    }
    static Sum enterSum(){
        while(true){
            try{
                return Sum.parseSum(in.readLine());
            }catch(Exception e){out.println("Некорректный ввод данных, попробуйте ещё");}
        }
    }
    static GasType selectGasTypeMenu(List<GasType> gtypes) throws WasNotSelectedException{
        out.println("Выберите тип бензина");
        int num = 1;
        for(GasType gt: gtypes){
            out.println(num++ + ") " + gt.toString());
        }
        out.println("\n" + num + ") Вернуться назад");
        while(true){
            int sel = enterInt();
            if(sel == num)
                throw new WasNotSelectedException();
            try{
                return gtypes.get(sel - 1);
            }catch(IndexOutOfBoundsException ixe){out.println("Элемента с таким номером нет");}
            catch(Exception e){}
        }
    }
    static Payment makePaymentMenu(Sum sum) throws WasNotSelectedException{
        out.println("К оплате: " + sum);
        out.println("Выберите способ оплаты: ");
        boolean flag = true;
        while(flag){
            out.println("1) Оплата наличными");
            out.println("2) Оплата банковской картой");
            out.println("3) Вернуться назад");
            try{
                switch(enterInt()){
                    case 1: { ByMoney pay = payMoneyMenu(sum); expence = expence.add(sum); return pay; }
                    case 2: { ByCard pay = payBankMenu(sum); expence = expence.add(sum); return pay; }
                    case 3: flag = false;
                }
            }catch(Exception e){}
        }
        throw new WasNotSelectedException();
    }
    static ByMoney payMoneyMenu(Sum sum) throws WasNotSelectedException{
         while(true){
             try{
                 out.print("Введите заплаченную сумму: ");
                 ByMoney pay = new ByMoney(enterSum(), sum);
                 out.println("Заплачено: " + pay.getPaid());
                 out.println("Сдача: " + pay.getPaid().sub(sum));
                 return pay;
             }catch(PaymentException e){out.println(e.getMessage());}
         }
    }
    static ByCard payBankMenu(Sum sum) throws WasNotSelectedException{
        while(true){
             try{
                 out.print("Введите номер банковской карты: ");
                 ByCard pay = new ByCard(bank, in.readLine(), sum);
                 out.println("Транзакция прошла успешно, со счёта снято: " + sum);
                 return pay;
             }catch(PaymentException e){out.println(e.getMessage());}
             catch(IOException e){}
         }
    }
    static FillingSt selectFStationMenu(){
        out.print("Введите номер колонки: ");
        while(true){
            int sel = enterInt();
            try{
                return base.getFStation(sel);
            }catch(NotFoundException e){out.println("Колонки с таким номером не существует");}
        }
    }
    static void historyMenu(){
        boolean flag = true;
        while(flag){
            out.println("Меню истори\n");
            out.println("1) Просмотреть список всех покупок по датам");
            out.println("2) Просмотреть покупки за промежуток времени");
            out.println("3) Просмотреть список всех записей по датам");
            out.println("4) Просмотреть записи за промежуток времени");
            out.println("5) Просмотреть выручку за промежуток времени");
            out.println("6) Просмотреть количество денег в кассе");
            out.println("7) Вернуться назад");
            try{
                switch(enterInt()){
                    case 1: PurchasesDateListMenu(history.getPurchases()); break;
                    case 2: PurchasesPeriodListMenu(); break;
                    case 3: RecordsDateListMenu(history.getRecords()); break;
                    case 4: RecordsPeriodListMenu(); break;
                    case 5: selectExpencePeriodMenu(); break;
                    case 6: showExpenceMenu(); break;
                    case 7: flag = false;
                }
            }catch(Exception e){}
        } 
    }
    static void showFullPurchList(){
        out.println("Full Purchases List");
        for(Purchase pur: history.getPurchases()){
            out.println("\nPurchase " + df.format(pur.getDate()));
            out.println("Services");
            for(Service srv: pur.getServices()){
                out.println("\t" + srv);
            }
            out.println("Общая стоимость: " + pur.getPayment().getSum());
            out.println("Оплата " + pur.getPayment());
        }
    }
    static void showFullRecordList(){
        
    }
    static void RecordsDateListMenu(NavigableSet<Record> records){
        Record[] recs  = records.toArray(new Record[0]);
        while(true){
            out.println("Список всех записей\n");
            int num = 1;
            for(Record rec: recs){
                out.println(num++ + ") " + df.format(rec.getDate()));
            }
            out.println("\n" + num + ") Вернуться назад");
            int sel = enterInt();
            if(sel == num)
                return;
            try{
                 RecordWorkMenu(recs[sel - 1]);
            }catch(IndexOutOfBoundsException ixe){out.println("Элемента с таким номером нет");}
            catch(Exception e){}
        }
    }
    static void PurchasesDateListMenu(NavigableSet<Purchase> purchases){
        Purchase[] purchs  = purchases.toArray(new Purchase[0]);
        while(true){
            out.println("Список всех покупок\n");
            int num = 1;
            for(Purchase purch: purchs){
                out.println(num++ + ") " + df.format(purch.getDate()) + " общая сумма: " + purch.getTotalVal().toFullString());
            }
            out.println("\n" + num + ") Вернуться назад");
            int sel = enterInt();
            if(sel == num)
                return;
            try{
                Purchase pur = purchs[sel - 1];
                out.println("\nПокупка " + df.format(pur.getDate()));
                out.println("Услуги");
                for(Service srv: pur.getServices()){
                    out.println("\t" + srv);
                }
                out.println("Общая стоимость: " + pur.getPayment().getSum());
                out.println("Оплата " + pur.getPayment());
                out.println("\nНажмите enter чтобы продролжить");
                in.read();
            }catch(IndexOutOfBoundsException ixe){out.println("Элемента с таким номером нет");}
            catch(Exception e){out.println(e.getMessage());}
        }
    }
    static void RecordWorkMenu(Record rec){
        boolean flag = true;
        while(flag){
            out.println("Запись\n");
            out.println("Дата: " + df.format(rec.getDate()));
            if(!rec.getDataBase().getGasTypes().isEmpty()){
                out.println("Виды бензина");
                for(GasType gt: rec.getDataBase().getGasTypes())
                    out.println(gt.toString());
            }
            if(!rec.getDataBase().getServices().isEmpty()){
                out.println("\nДоп. услуги");
                for(AddService srv: rec.getDataBase().getServices())
                    out.println(srv.toString());
            }
            out.println("1) Просмотреть историю изменения цен типа бензина");
            out.println("2) Просмотреть историю изменения цен доп. услуги");
            out.println("3) Вернуться назад");
            try{
                switch(enterInt()){
                    case 1: priceChangeHistoryMenu(selectGasTypeMenu(rec.getDataBase().getGasTypes())); break;
                    case 2: priceChangeHistoryMenu(selectAddServMenu(rec.getDataBase().getServices())); break;
                    case 3: flag = false;
                }
            }catch(Exception e){}
        }
    }
    static void priceChangeHistoryMenu(GasType gt){
        try{
            out.println("История изменения цены на " + gt.getName());
            for(Record rec: history.getRecords()){
                try{
                    GasType gt2 = rec.getDataBase().findGasType(gt.getName());
                    out.println(df.format(rec.getDate()) + " - " + gt2.getCost().toFullString());
                }catch(NotFoundException e){}
            }
            try{
                GasType gt2 = base.findGasType(gt.getName());
                out.println("Сейчас - " + gt2.getCost().toFullString());
                }catch(NotFoundException e){}
            out.println("Нажмите enter чтобы продолжить");
            in.read();
        }catch(Exception e){}
    }
    static void priceChangeHistoryMenu(AddService srv){
        try{
            out.println("История изменения цены за услугу: " + srv.getName());
            for(Record rec: history.getRecords()){
                try{
                    AddService srv2 = rec.getDataBase().findAddService(srv.getName());
                    out.println(df.format(rec.getDate()) + " - " + srv2.getCost().toFullString());
                }catch(NotFoundException e){}
            }
            try{
                AddService srv2 = base.findAddService(srv.getName());
                out.println("Сейчас - " + srv2.getCost().toFullString());
                }catch(NotFoundException e){}
            out.println("Нажмите enter чтобы продолжить");
            in.read();
        }catch(Exception e){}
    }
    static void tempMenu(){
        try{
        History hist = new History();
        GasType gt = base.getGasType(1);
        Calendar cal = Calendar.getInstance();
        cal.set(2011, 7, 5);
        Date dt1 = cal.getTime();
        cal.set(2011, 7, 6);
        Date dt2 = cal.getTime();
        cal.set(2011, 7, 10);
        Date dt3 = cal.getTime();
        cal.set(2011, 7, 15);
        Date dt4 = cal.getTime();
        cal.set(2011, 7, 20);
        Date dt5 = cal.getTime();
        hist.addRecord(dt1, gt);
        hist.addRecord(dt3, gt);
        hist.addRecord(dt4, gt);
        NavigableSet<Record> recs = hist.getRecords(dt2, dt5);
        out.println("Records");
        for(Record rec: recs){
            out.println(df.format(rec.getDate()));
        }
        }catch(Exception e){out.println(e.getMessage());}
    }
    static void showExpenceMenu(){
        out.println("Денег в кассе: " + expence);
        try{
            out.println("Нажмите enter чтобы продолжить");
            in.read();
        }catch(IOException e){}
    }
    static void RecordsPeriodListMenu(){
        boolean flag = true;
        while(flag){
            try{
                out.println("Введите промежуток времени (в формате дд.мм.гг ч:м):\nc ");
                Date date1 = enterDate();
                out.print("по ");
                Date date2 = enterDate();
                RecordsDateListMenu(history.getRecords(date1, date2));
            }catch(NotFoundException e){}
            out.println("\nПовторить запрос? да/нет");
            boolean flag2 = true;
            while(flag2){
                try{
                    String select = in.readLine();
                    if(select.equalsIgnoreCase("да"))
                        flag2 = false;
                    else if(select.equalsIgnoreCase("нет")){
                        flag2 = false;
                        flag = false;
                    }
                }catch(IOException e){}
            }
        }
    }
    static void PurchasesPeriodListMenu(){
        boolean flag = true;
        while(flag){
            try{
                out.println("Введите промежуток времени (в формате дд.мм.гг ч:м):\nc ");
                Date date1 = enterDate();
                out.print("по ");
                Date date2 = enterDate();
                PurchasesDateListMenu(history.getPurchases(date1, date2));
            }catch(NotFoundException e){}
            out.println("\nПовторить запрос? да/нет");
            boolean flag2 = true;
            while(flag2){
                try{
                    String select = in.readLine();
                    if(select.equalsIgnoreCase("да"))
                        flag2 = false;
                    else if(select.equalsIgnoreCase("нет")){
                        flag2 = false;
                        flag = false;
                    }
                }catch(IOException e){}
            }
        }
    }
    static void selectExpencePeriodMenu(){
        boolean flag = true;
        while(flag){
            try{
                out.println("Введите промежуток времени (в формате дд.мм.гг ч:м):\nc ");
                Date date1 = enterDate();
                out.print("по ");
                Date date2 = enterDate();
                ExpencePeriod(history.getPurchases(date1, date2));
            }catch(NotFoundException e){}
            out.println("\nПовторить запрос? да/нет");
            boolean flag2 = true;
            while(flag2){
                try{
                    String select = in.readLine();
                    if(select.equalsIgnoreCase("да"))
                        flag2 = false;
                    else if(select.equalsIgnoreCase("нет")){
                        flag2 = false;
                        flag = false;
                    }
                }catch(IOException e){}
            }
        }
    }
    static void ExpencePeriod(NavigableSet<Purchase> purchases){
        out.print("C " + df.format(purchases.first().getDate()) + " по " + df.format(purchases.last().getDate()));
        out.println(" было приобретено:\n");
        LinkedList<Service> servs = new LinkedList<Service>();
        for(Purchase pur: purchases)
            servs.addAll(pur.getServices());
        LinkedList<Pair> entries  = new LinkedList<Pair>();
        boolean flag = true;
        int count1 = 0;
        while(true){
            int count2 = 0;
            Iterator<Service> itt = servs.iterator();
            Service srv;
            while(itt.hasNext() && count1 > count2){
                itt.next();
                count2++;
            }
            if(!itt.hasNext())
                break;
            srv = itt.next();
            Pair pair;
            if(srv.getClass().getName().equals("Services.AddService")){
                pair = new Pair(srv, 1);
            }else
                pair = new Pair(((Gas)srv).clone(), 1);
            while(itt.hasNext()){
                Service srv2 = itt.next();
                if(srv.equalType(srv2))
                {
                    if(srv.getClass().getName().equals("Services.AddService")){
                        pair.num++;
                    }else
                        ((Gas)pair.srv).addGas(((Gas)srv2).getAmount());
                    itt.remove();
                }
            }
            entries.add(pair);
            count1++;
        }
        for(Pair pair: entries){
            if(pair.srv.getClass().getName().equals("Services.AddService")){
                AddService srv = (AddService)pair.srv;
                out.println(srv.getName() + " X " + pair.num + " общей стоимостью: " + srv.getCost().mult(pair.num).toFullString());
            }
            else{
                Gas gas = (Gas)pair.srv;
                out.println(gas.toString());
            }
        }
    }
    static Date enterDate(){
        while(true){
            try{
                return df.parse(in.readLine());
            }catch(Exception e){out.println("Некорректный ввод данных, попробуйте ещё");}
        }
    }
}
class Pair{
    Pair(Service srv, int num){
        this.srv = srv;
        this.num = num;
    }
    Service srv;
    int num;
}

class WasNotSelectedException extends Exception{
    
}