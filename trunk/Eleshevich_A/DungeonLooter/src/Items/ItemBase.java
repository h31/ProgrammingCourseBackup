package Items;

import Constants.ArmorClass;
import Constants.CreatChar;
import Constants.WeaponType;
import Creatures.Monster;
import Constants.PlayerSlot;
import Creatures.Buff;
import Creatures.Effect;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.ArrayList;

/**
 * @author Andrew
 */
public class ItemBase {
    static ArrayList<Item> items = new ArrayList<Item>();
    static final Item artifact = new MiscItem("Артефакт",
            Toolkit.getDefaultToolkit().createImage("Data/HornHelmet.gif"),
            "Он тебе очень нужен... он вообще всем нужен");
    
    static public void setBaseDefault(){
        Effect eff1 = new Effect(CreatChar.HEALTH, 10, false);
        Buff buff1 = new Buff(new Effect[] {eff1}, 1);
        items.add(new Weapon("Модный меч", Toolkit.getDefaultToolkit().createImage("Data/Sword2.gif"),
                4, WeaponType.SWORD, "Не знаю насчёт силы, но выглядит этот меч классно"));
        items.add(new Weapon("Железный меч", Toolkit.getDefaultToolkit().createImage("Data/IronSword.gif"),
                3, WeaponType.SWORD, "Это обычный железный меч, ну хоть не деревянный"));
        items.add(new Weapon("Деревянный меч", Toolkit.getDefaultToolkit().createImage("Data/WoodSword.gif"),
                2, WeaponType.SWORD, "Без комментариев..."));
        items.add(new BodyArmor("Штаны", Toolkit.getDefaultToolkit().createImage("Data/LeatherPants.gif"),
                1, PlayerSlot.LEGS, ArmorClass.LIGHT, "Ну что тут скажешь... это штаны"));
        items.add(new Potion("Зелье здоровья", Toolkit.getDefaultToolkit().createImage("Data/BottleRed.gif"),
                buff1, "Восстанавливает 10 едениц здоровья"));
    }
    static public Item getItemID(int ID){
        try{
            return items.get(ID);
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    static public Item getItemName(String name){
        for(Item item: items)
            if(item.getName().equalsIgnoreCase(name))
                return item;
        return null;
    }
    static public Item getItemRandom(){
        int sel = ((int)(Math.random()*10000))%items.size();
        return items.get(sel);
    }

    public static Item getArtifact() {
        return artifact;
    }
    public static boolean isArtifact(Item item){
        return item.equals(artifact);
    }
}
