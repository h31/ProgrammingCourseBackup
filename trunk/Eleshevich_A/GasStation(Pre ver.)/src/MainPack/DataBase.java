package MainPack;

import Services.AddService;
import Services.GasType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * @author Andrew
 */
public class DataBase {
    List<GasType> gastypes;
    List<AddService> services;
    
    public DataBase(){
        gastypes = new ArrayList<GasType>();
        services = new ArrayList<AddService>();
    }
        //возможно нужно делать проверку на повторяемость идентификаторов
    public void add(GasType gastype){
        gastypes.add(gastype);
    }
    public void add(AddService service){
        services.add(service);
    }
    
    public void addGasTypes(Collection<GasType> gastypes){
        this.gastypes.addAll(gastypes);
    }
    public void addServices(Collection<AddService> services){
        this.services.addAll(services);
    }
    
    public GasType getGasType(int ID) throws NotFoundException{
        for(GasType gt: gastypes){
            if(gt.getID() == ID)
                return gt;
        }
        throw new NotFoundException();
    }
    public AddService getAddSevice(int ID) throws NotFoundException{
        for(AddService sv: services){
            if(sv.getID() == ID)
                return sv;
        }
        throw new NotFoundException();
    }
    
    public List<GasType> getGasTypes(){
        return gastypes;
    }
    public List<AddService> getServices(){
        return services;
    }
}
