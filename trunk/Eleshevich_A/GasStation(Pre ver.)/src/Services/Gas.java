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
    public void addGas(int val){
        amount += val;
    }
    @Override
    public String toString(){
        return type.getName() + " (" + type.price + " за литр) " + amount + " литров, стоимость: " + getCost().toFullString();
    }
    @Override
    public Gas clone(){
        return new Gas(type, amount);
    }
    @Override
    public boolean equalType(Service serv2){
        if(serv2.getClass().equals(this.getClass())){
            return type.name.equals(((Gas)serv2).type.name) && type.price.equals(((Gas)serv2).type.price);
        }else
            return false;
    }
}
