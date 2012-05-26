package Items;

import Constants.ItemType;
import Constants.UseType;
import Creatures.Buff;
import Creatures.Effect;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Potion extends Item implements Usable{
    Buff buff;
    boolean used = false;
    
    Potion(String name, Image img, Buff buff, String descr){
        super(name, img, ItemType.POTION, UseType.USABLE, descr);
        this.buff = buff;
    }
    
    @Override
    public Buff getBuff(){
        return buff;
    }
    @Override
    public Buff use(){
        used = true;
        return buff;
    }
    @Override
    public boolean isUsed(){
        return used;
    }
    @Override
    public Potion clone(){
        return new Potion(name, img, buff, descr);
    }
}
