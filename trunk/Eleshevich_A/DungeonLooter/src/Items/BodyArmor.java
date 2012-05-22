/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Items;

import java.awt.Image;

/**
 *
 * @author Andrew
 */
public class BodyArmor extends Armor{
    int slotType;
    
    public BodyArmor(String name, Image img, int def, int stype){
        super(name, img, def, Armor.BODY_ARMOR);
        slotType = stype;
    }
    public int getSlotType(){
        return slotType;
    }
}
