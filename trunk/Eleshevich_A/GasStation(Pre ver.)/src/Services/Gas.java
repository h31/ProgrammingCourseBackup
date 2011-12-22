package Services;

import MainPack.Sum;

/**
 * @author Andrew
 */
public class Gas extends Service{
    GasType type;
    int amount;
    
    @Override
    public Sum getCost(){
        return type.price.mult(amount);
    }
    
    @Override
    public String getName(){
        return type.name;
    }
    
    public Gas(GasType type, int amount){
        this.type = type;
        this.amount = amount;
    }
}
