package Items;

import Constants.ItemType;
import Constants.UseType;
import Constants.WeaponType;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Weapon extends Item{
    int damage;
    WeaponType wtype;
    
    public Weapon(String name, Image img, int damage, WeaponType wtype, String descr, int ID){
        super(name, img, ItemType.WEAPON, UseType.WIELDABLE, descr, ID);
        this.damage = damage;
        this.wtype = wtype;
    }
    
    public int getDamage(){ return damage; }
    public WeaponType getWtype(){ return wtype; }
    @Override
    public Weapon clone(){
        return new Weapon(name, img, damage, wtype, descr, ID);
    }
    @Override
    public boolean isWeapon(){
        return true;
    }
}
