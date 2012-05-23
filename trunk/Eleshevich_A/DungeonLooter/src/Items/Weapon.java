package Items;

import Constants.ItemType;
import Constants.WeaponType;
import Constants.UseType;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Weapon extends Item{
    int damage;
    WeaponType wtype;
    
    public Weapon(String name, Image img, int damage, WeaponType wtype, String descr){
        super(name, img, ItemType.WEAPON, UseType.WIELDABLE, descr);
        this.damage = damage;
        this.wtype = wtype;
    }
    
    public int getDamage(){ return damage; }
    public WeaponType getWtype(){ return wtype; }
    @Override
    public Weapon clone(){
        return new Weapon(this.name, this.img, this.damage, this.wtype, this.descr);
    }
}
