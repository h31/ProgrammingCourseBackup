package Items;

import java.awt.Image;

/**
 * @author Andrew
 */
public class Weapon extends Item{
    int damage;
    int weaponType;
    
    public static final int SWORD = 1;
    public static final int MACE = 2;
    public static final int STAFF = 3;
    
    public Weapon(String name, Image img, int damage, int wtype){
        super(name, img, Item.WEAPON, Item.WIELDABLE);
        this.damage = damage;
        weaponType = wtype;
    }
    
    public int getDamage(){ return damage; }
    public int getWtype(){ return weaponType; }
}
