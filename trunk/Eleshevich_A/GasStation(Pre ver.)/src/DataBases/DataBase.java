package DataBases;

import Services.AddService;
import Services.GasType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * @author Andrew
 */
public class DataBase{
    List<GasType> gastypes;
    List<AddService> services;
    
    public DataBase(){
        gastypes = new ArrayList<GasType>();
        services = new ArrayList<AddService>();
    }
    public DataBase(Collection<GasType> gastypes, Collection<AddService> services){
        this.gastypes = new ArrayList<GasType>();
        this.services = new ArrayList<AddService>();
        this.gastypes.addAll(gastypes);
        this.services.addAll(services);
    }
        //возможно нужно делать проверку на повторяемость идентификаторов
    public void add(GasType gastype){
        try{
            getGasType(gastype.getID());
        }catch(NotFoundException e){
            gastypes.add(gastype);
        }
    }
    public void add(AddService service){
        try{
            getAddService(service.getID());
        }catch(NotFoundException e){
            services.add(service);
        }
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
    public AddService getAddService(int ID) throws NotFoundException{
        for(AddService sv: services){
            if(sv.getID() == ID)
                return sv;
        }
        throw new NotFoundException();
    }
    public GasType findGasType(String name) throws NotFoundException{
        for(GasType gt: gastypes){
            if(gt.getName().equals(name))
                return gt;
        }
        throw new NotFoundException();
    }
    public AddService findAddService(String name) throws NotFoundException{
        for(AddService srv: services){
            if(srv.getName().equals(name))
                return srv;
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
