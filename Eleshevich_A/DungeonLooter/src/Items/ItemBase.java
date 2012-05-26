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
        Effect eff2 = new Effect(CreatChar.STRENGTH, 5, true);
        Buff buff2 = new Buff(new Effect[] {eff2}, 30);
        items.add(new Weapon("Модный меч", Toolkit.getDefaultToolkit().createImage("Data/Sword2.gif"),
                4, WeaponType.SWORD, "Не знаю насчёт силы, но выглядит этот меч классно"));
        items.add(new Weapon("Железный меч", Toolkit.getDefaultToolkit().createImage("Data/IronSword.gif"),
                3, WeaponType.SWORD, "Это обычный железный меч, ну хоть не деревянный"));
        items.add(new Weapon("Деревянный меч", Toolkit.getDefaultToolkit().createImage("Data/WoodSword.gif"),
                2, WeaponType.SWORD, "Без комментариев..."));
        items.add(new BodyArmor("Штаны", Toolkit.getDefaultToolkit().createImage("Data/LeatherPants.gif"),
                1, PlayerSlot.LEGS, ArmorClass.LIGHT, "Ну что тут скажешь... это штаны"));
        items.add(new Potion("Зелье здоровья", Toolkit.getDefaultToolkit().createImage("Data/PotionRed.gif"),
                buff1, "Восстанавливает 10 едениц здоровья"));
        items.add(new Potion("Зелье силы", Toolkit.getDefaultToolkit().createImage("Data/PotionYellow.gif"),
                buff2, "Увеличивает силу на 5 на 30 ходов"));
        items.add(new BodyArmor("Железный шлем", Toolkit.getDefaultToolkit().createImage("Data/IronHelmet1.gif"),
                2, PlayerSlot.HEAD, ArmorClass.HEAVY, "Железный шлем, он такой... железный"));
        items.add(new Shield("Деревянный щит", Toolkit.getDefaultToolkit().createImage("Data/WoodShield1.gif"),
                1, ArmorClass.LIGHT, "Это конечно не стена, но всё же хоть что то будет между вами и врагом"));
        items.add(new BodyArmor("Железная броня", Toolkit.getDefaultToolkit().createImage("Data/IronArmor2.gif"),
                3, PlayerSlot.BODY, ArmorClass.HEAVY, "Эта броня очень прочная, я бы даже сказал слишком прочная"));
        items.add(new BodyArmor("Железные поножи", Toolkit.getDefaultToolkit().createImage("Data/IronGreaves.gif"),
                3, PlayerSlot.LEGS, ArmorClass.HEAVY, "Это как железная броня, только на ноги"));
        items.add(new Shield("Железный щит", Toolkit.getDefaultToolkit().createImage("Data/IronShield1.gif"),
                2, ArmorClass.HEAVY, "С таким щитом вам ничего не страшно... разве что только у врага будет\nоружие, больше чем этот щит"));
    }
    static public Item getItemID(int ID){
        try{
            return items.get(ID).clone();
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    static public Item getItemName(String name){
        for(Item item: items)
            if(item.getName().equalsIgnoreCase(name))
                return item.clone();
        return null;
    }
    static public Item getItemRandom(){
        int sel = ((int)(Math.random()*10000))%items.size();
        return items.get(sel).clone();
    }

    public static Item getArtifact() {
        return artifact;
    }
    public static boolean isArtifact(Item item){
        return item.equals(artifact);
    }
}
