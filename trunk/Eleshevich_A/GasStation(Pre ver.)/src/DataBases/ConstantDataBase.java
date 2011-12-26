package DataBases;

import MainPack.FillingSt;
import Services.AddService;
import Services.GasType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * @author Andrew
 */
public class ConstantDataBase extends DataBase{
    List<FillingSt> fstations;
    public ConstantDataBase(){ //доп конструкторы чтобы сразу инициализировать с коллекциями
        super();
        fstations = new ArrayList<FillingSt>();
    }
    public ConstantDataBase(Collection<GasType> gastypes, Collection<AddService> services, Collection<FillingSt> fstations){
        super(gastypes, services);
        this.fstations = new ArrayList<FillingSt>();
        this.fstations.addAll(fstations);
    }
    public void add(FillingSt fstation){
        fstations.add(fstation);
    }
    public void addFsations(Collection<FillingSt> fstations){
        this.fstations.addAll(fstations);
    }
    public List<FillingSt> getFStations(){
        return fstations;
    }
    public FillingSt getFStation(int number) throws NotFoundException{
        for(FillingSt fst: fstations){
            if(fst.getNumber() == number)
                return fst;
        }
        throw new NotFoundException();
    }
}
