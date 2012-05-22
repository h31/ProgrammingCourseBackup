package Items;

import java.awt.Image;

/**
 * @author Andrew
 */
public abstract class Item {
    Image img;
    String name;
    int type;
    int useType;
    String descr = "";
    
    public static final int ARMOR = 1;
    public static final int WEAPON = 2;
    public static final int POTION = 3;
    
    public static final int WIELDABLE = 1;
    public static final int PUTABLE = 2;
    public static final int USABLE = 3;
    
    Item(String name, Image img, int type, int utype){
        this.name = name;
        this.img = img;
        this.type = type;
        useType = utype;
    }
    
    public int getType(){
        return type;
    }
    public int getUseType(){
        return useType;
    }
    public Image getImg(){
        return img;
    }
    public String getName(){
        return name;
    }
    public String getDescr(){
        return descr;
    }
}
