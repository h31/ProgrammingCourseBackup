package DataHandlers;

import MainPack.FillingSt;
import MainPack.Sum;
import Services.AddService;
import Services.GasType;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;

/**
 * @author Andrew
 */
public class ConstDataHandler extends DefaultHandler{
    List<GasType> gastypes;
    List<AddService> services;
    List<FillingSt> fstations;
    boolean inStation;
    int Stnumber;
    List<GasType> Stgtypes;
    
    @Override
    public void startDocument(){
        gastypes = new LinkedList<GasType>();
        services = new LinkedList<AddService>();
        fstations = new LinkedList<FillingSt>();
        Stgtypes = new LinkedList<GasType>();
        inStation = false;
    }
    
    @Override   //и вообще тут надо всё почистить возмоно ID может быть не задан
    public void startElement(String uri, String name, String qname, Attributes attrs){                 //может нужна проверка на оставшееся кол-во слов
        if(qname.equals("GasType") || qname.equals("Service")){
        StringTokenizer st = new StringTokenizer(attrs.getValue("price"), ".");
        Sum tsum = new Sum(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        int x = Integer.parseInt(attrs.getValue("ID"));
        if(qname.equals("GasType"))
            gastypes.add(new GasType(attrs.getValue("name"), tsum, Integer.parseInt(attrs.getValue("ID"))));
        else if(qname.equals("Service"))
            services.add(new AddService(attrs.getValue("name"), tsum, Integer.parseInt(attrs.getValue("ID"))));
        }else if(qname.equals("FillingSt")){
            Stnumber = Integer.parseInt(attrs.getValue("number"));
        }else if(qname.equals("FuelTypesIDs"))
            inStation = true;
    }
    
    @Override
    public void characters(char[] buf, int offset, int len){
        if(inStation){
            String str = new String(buf, offset, len);
            StringTokenizer st = new StringTokenizer(str);
            while(st.hasMoreTokens()){  //Возможно нужен другой алгоритм поиска, но тогда будет лучше передавать всю базу
                int ID = Integer.parseInt(st.nextToken());
                for(GasType gt: gastypes){
                    if(gt.getID() == ID)
                        Stgtypes.add(gt);
                }
            }
            inStation = false;
        }
    }
    
    @Override
    public void endElement(String uri, String name, String qname){
        if(qname.equals("FillingSt")){
            fstations.add(new FillingSt(Stnumber, Stgtypes));
            Stgtypes.clear();
        }
    }
    public List<GasType> getLoadedGasTypes(){
        return gastypes;
    }
    public List<AddService> getLoadedServices(){
        return services;
    }
    public List<FillingSt> getLoadedStations(){
        return fstations;
    }
}