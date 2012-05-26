/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Items;

import Constants.ArmorClass;
import Constants.PlayerSlot;
import java.awt.Image;

/**
 *
 * @author Andrew
 */
public class BodyArmor extends Armor{
    PlayerSlot slotType;
    
    public BodyArmor(String name, Image img, int def, PlayerSlot stype, ArmorClass aclass, String descr){
        super(name, img, def, ArmorType.BODY_ARMOR, aclass, descr);
        slotType = stype;
    }
    public PlayerSlot getSlotType(){
        return slotType;
    }
    @Override
    public BodyArmor clone(){
        return new BodyArmor(name, img, defence, slotType, aclass, descr);
    }
}
