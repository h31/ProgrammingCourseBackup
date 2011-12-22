package MainPack;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * @author Andrew
 */
public class ConstantDataBase extends DataBase{
    List<FillingSt> fstations;
    ConstantDataBase(){ //доп конструкторы чтобы сразу инициализировать с коллекциями
        super();
        fstations = new ArrayList<FillingSt>();
    }
    void add(FillingSt fstation){
        fstations.add(fstation);
    }
    void addFsations(Collection<FillingSt> fstations){
        this.fstations.addAll(fstations);
    }
    List<FillingSt> getFStations(){
        return fstations;
    }
}
