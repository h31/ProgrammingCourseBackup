package Items;

import Constants.ArmorClass;
import Constants.ItemType;
import Constants.UseType;
import java.awt.Image;

/**
 * @author Andrew
 */
public abstract class Armor extends Item{
    int defence;
    ArmorType atype;
    ArmorClass aclass;
    
    public Armor(String name, Image img, int def, ArmorType atype, ArmorClass aclass, String descr){
        super(name, img, ItemType.ARMOR, UseType.PUTABLE, descr);
        if(atype.equals(ArmorType.SHIELD))
            utype = UseType.WIELDABLE;   //это всё конечно не хорошо, но... более логично чем тянуть utype дальше
        defence = def;
        this.atype = atype;
        this.aclass = aclass;
    }
    
    public ArmorType getArmType(){
        return atype;
    }
    public int getDefence(){
        return defence;
    }
    public ArmorClass getArmClass(){
        return aclass;
    }
}
