/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Services;

import Sums.Sum;

/**
 *
 * @author Andrew
 */
public class AddService extends Service implements IServiceType{
    String name;
    Sum price;
    int identifier;
    
    @Override
    public Sum getCost(){
        return price;
    }
    
    @Override
    public String getName(){
        return name;
    }
    public int getID(){
        return identifier;
    }
    
    public AddService(String name, Sum price, int ID){
        this.name = name;
        this.price = price;
        identifier = ID;
    }
    @Override
    public String toString(){
        return name + ", стоимость " + price;
    }
}
