package Items;

import Constants.ItemType;
import Constants.UseType;
import java.awt.Image;

/**
 * @author Andrew
 */
public class MiscItem extends Item{
    MiscItem(String name, Image img, String descr){
        super(name, img, ItemType.MISC, UseType.NONE, descr);
    }

    @Override
    public Item clone() {
        return this;
    }
}
