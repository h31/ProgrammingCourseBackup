package Items;

import Constants.ItemType;
import Constants.UseType;
import java.awt.Image;

/**
 * @author Andrew
 */
public abstract class Item {
    Image img;
    String name;
    ItemType type;
    UseType utype;
    String descr;
    
    Item(String name, Image img, ItemType type, UseType utype, String descr){
        this.name = name;
        this.img = img;
        this.type = type;
        this.utype = utype;
        this.descr = descr;
    }
    
    public ItemType getType(){ return type; }
    public UseType getUseType(){ return utype; }
    public Image getImg(){ return img; }
    public String getName(){ return name; }
    public String getDescr(){ return descr; }
    public boolean isArmor(){ return false; }
    public boolean isWeapon(){ return false; }
    @Override
    abstract public Item clone();
}
