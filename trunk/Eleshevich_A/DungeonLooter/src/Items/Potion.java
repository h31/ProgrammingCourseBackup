package Items;

import Constants.ItemType;
import Constants.UseType;
import Creatures.Effects.Effect;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Potion extends Item implements Usable{
    Effect effect;
    boolean used = false;
    
    Potion(String name, Image img, String descr){
        super(name, img, ItemType.POTION, UseType.USABLE, descr);
    }
    
    @Override
    public Effect getEffect(){
        return effect;
    }
    @Override
    public Effect use(){
        used = true;
        return effect;
    }
    @Override
    public boolean isUsed(){
        return used;
    }
    @Override
    public Potion clone(){
        return new Potion(this.name, this.img, this.descr);
    }
}
