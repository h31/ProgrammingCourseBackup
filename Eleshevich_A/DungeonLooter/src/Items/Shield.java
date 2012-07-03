package Items;

import Constants.ArmorClass;
import Constants.ArmorType;
import java.awt.Image;

/**
 *
 * @author Andrew
 */
public class Shield extends Armor{
    public Shield(String name, Image img, int def, ArmorClass aclass, String descr, int ID){
        super(name, img, def, ArmorType.SHIELD, aclass, descr, ID);
    }
    @Override
    public Shield clone(){
        return new Shield(name, img, defence, aclass, descr, ID);
    }
}