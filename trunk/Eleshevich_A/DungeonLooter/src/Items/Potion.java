package Items;

import Constants.ItemType;
import Constants.UseType;
import Creatures.Buff;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Potion extends Item implements Usable{
    Buff buff;
    boolean used = false;
    
    Potion(String name, Image img, Buff buff, String descr, int ID){
        super(name, img, ItemType.POTION, UseType.USABLE, descr, ID);
        this.buff = buff;
    }
    
    @Override
    public Buff getBuff(){
        return buff;
    }
    @Override
    public Buff use(){
        used = true;
        return buff.clone();
    }
    @Override
    public boolean isUsed(){
        return used;
    }
    @Override
    public Potion clone(){
        return new Potion(name, img, buff.clone(), descr, ID);
    }
}
