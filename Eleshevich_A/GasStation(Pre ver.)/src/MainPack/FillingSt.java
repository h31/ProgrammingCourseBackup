package MainPack;

/**
 * @author Andrew
 */

import Services.GasType;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class FillingSt {
    int number;
    ArrayList<GasType> GasTypes;
    
    public FillingSt(int number, Collection<GasType> types){
        this.number = number;
        GasTypes = new ArrayList<GasType>();
        GasTypes.addAll(types);
    }
    
    public int getNumber(){
        return number;
    }
    
    public List<GasType> getGasTypes(){
        return GasTypes;
    }
}
