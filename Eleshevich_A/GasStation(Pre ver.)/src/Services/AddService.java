/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Services;

import MainPack.Sum;

/**
 *
 * @author Andrew
 */
public class AddService extends Service{
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
}
