package Items;

import Constants.ArmorClass;
import Constants.WeaponType;
import Creatures.Monster;
import Constants.PlayerSlot;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.ArrayList;

/**
 * @author Andrew
 */
public class ItemBase {
    static ArrayList<Item> items = new ArrayList<Item>();
    
    static public void setBaseDefault(){
        Image sword1 = Toolkit.getDefaultToolkit().createImage("Data/Sword2.gif");
        Image sword2 = Toolkit.getDefaultToolkit().createImage("Data/IronSword.gif");
        Image pants = Toolkit.getDefaultToolkit().createImage("Data/LeatherPants.gif");
        Image sword3 = Toolkit.getDefaultToolkit().createImage("Data/WoodSword.gif");
        items.add(new Weapon("Модный меч", sword1, 4, WeaponType.SWORD, "Не знаю насчёт силы, но выглядит этот меч классно"));
        items.add(new Weapon("Железный меч", sword2, 3, WeaponType.SWORD, "Это обычный железный меч, ну хоть не деревянный"));
        items.add(new Weapon("Деревянный меч", sword3, 2, WeaponType.SWORD, "Без комментариев..."));
        items.add(new BodyArmor("Штаны", pants, 1, PlayerSlot.LEGS, ArmorClass.LIGHT, "Ну что тут скажешь... это штаны"));
    }
    static public Item getItemID(int ID){
        try{
            return items.get(ID);
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    static public Item getItemName(String name){
        for(Item item: items){
            if(item.getName().equalsIgnoreCase(name))
                return item;
        }
        return null;
    }
    static public Item getItemRandom(){
        int sel = ((int)(Math.random()*10000))%items.size();
        return items.get(sel);
    }
}
