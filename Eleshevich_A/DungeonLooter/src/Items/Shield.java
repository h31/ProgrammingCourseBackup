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
public class Shield extends Armor{
    public Shield(String name, Image img, int def){
        super(name, img, def, Armor.SHIELD);
    }
}
