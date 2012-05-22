package Items;

import java.awt.Image;

/**
 * @author Andrew
 */
public abstract class Armor extends Item{
    int defence;
    int armorType;
    
    public static final int BODY_ARMOR = 1;
    public static final int SHIELD = 2;
    
    public Armor(String name, Image img, int def, int atype){
        super(name, img, Item.ARMOR, Item.PUTABLE);
        if(atype == SHIELD)
            useType = Item.WIELDABLE;   //это всё конечно не хорошо, но... более логично чем тянуть utype дальше
        defence = def;
        armorType = atype;
    }
    
    public int getArmType(){
        return armorType;
    }
    public int getDefence(){
        return defence;
    }
}
