package Services;

import Sums.Sum;

/**
 *
 * @author Andrew
 */
public class GasType{
    String name;
    Sum price;
    int identifier;
    
    public GasType(String name, Sum price, int ID){
        this.name = name;
        this.price = price;
        identifier = ID;
    }
    public String getName(){
        return name;
    }
    public Sum getCost(){
        return price;
    }
    public int getID(){
        return identifier;
    }
    @Override
    public String toString(){
        return name + ", цена за литр: " + price;
    }
}
