package Items;

import Constants.ItemType;
import Constants.UseType;
import java.awt.Image;

/**
 * @author Andrew
 */
public class MiscItem extends Item{
    MiscItem(String name, Image img, String descr, int ID){
        super(name, img, ItemType.MISC, UseType.NONE, descr, ID);
    }

    @Override
    public Item clone() {
        return new MiscItem(name, img, descr, ID);
    }
}
