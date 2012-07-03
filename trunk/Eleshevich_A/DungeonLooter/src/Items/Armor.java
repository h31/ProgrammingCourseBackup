package Items;

import Constants.ArmorType;
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
    
    public Armor(String name, Image img, int def, ArmorType atype, ArmorClass aclass, String descr, int ID){
        super(name, img, ItemType.ARMOR, UseType.PUTABLE, descr, ID);
        if(atype.equals(ArmorType.SHIELD))
            utype = UseType.WIELDABLE;
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
    @Override
    public boolean isArmor(){
        return true;
    }
}
