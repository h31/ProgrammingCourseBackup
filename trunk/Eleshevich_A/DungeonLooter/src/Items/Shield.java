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
    int block;
    
    public Shield(String name, Image img, int def, int block, ArmorClass aclass, String descr){
        super(name, img, def, ArmorType.SHIELD, aclass, descr);
    }
    public int getBlock(){
        return block;
    }
    @Override
    public Shield clone(){
        return new Shield(name, img, defence, block, aclass, descr);
    }
}
