package Items;

import Creatures.Effects.Effect;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Potion extends Item implements Usable{
    Effect effect;
    boolean used = false;
    
    Potion(String name, Image img){
        super(name, img, Item.POTION, Item.USABLE);
    }
    
    @Override
    public Effect getEffect(){
        return effect;
    }
    public Effect use(){
        used = true;
        return effect;
    }
    @Override
    public boolean isUsed(){
        return used;
    }
}
