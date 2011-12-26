package Services;

import Sums.Sum;

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
    
    public GasType getType(){
        return type;
    }
    
    public int getAmount(){
        return amount;
    }
    
    public Gas(GasType type, int amount){
        this.type = type;
        this.amount = amount;
    }
    @Override
    public String toString(){
        return type.getName() + " (" + type.price + " за литр) " + amount + " литров, стоимость: " + getCost();
    }
}
