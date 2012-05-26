/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Items;

import Constants.ArmorClass;
import java.awt.Image;

/**
 *
 * @author Andrew
 */
public class Shield extends Armor{
    public Shield(String name, Image img, int def, ArmorClass aclass, String descr){
        super(name, img, def, ArmorType.SHIELD, aclass, descr);
    }
    @Override
    public Shield clone(){
        return new Shield(name, img, defence, aclass, descr);
    }
}
