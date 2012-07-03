package Items;

import Constants.ArmorType;
import Constants.ArmorClass;
import Constants.PlayerSlot;
import java.awt.Image;

/**
 *
 * @author Andrew
 */
public class BodyArmor extends Armor{
    PlayerSlot slotType;
    
    public BodyArmor(String name, Image img, int def, PlayerSlot stype, ArmorClass aclass, String descr, int ID){
        super(name, img, def, ArmorType.BODY_ARMOR, aclass, descr, ID);
        slotType = stype;
    }
    public PlayerSlot getSlotType(){
        return slotType;
    }
    @Override
    public BodyArmor clone(){
        return new BodyArmor(name, img, defence, slotType, aclass, descr, ID);
    }
}
