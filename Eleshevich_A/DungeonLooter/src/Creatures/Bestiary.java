package Creatures;

import Items.Item;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.ArrayList;

/**
 * @author Andrew
 */
public class Bestiary{
    private static ArrayList<Monster> monsters = new ArrayList<Monster>();
    
    public static void setBestiaryDefault(){
        Image img1 = Toolkit.getDefaultToolkit().createImage("Data/Spider1.gif");
        Image img2 = Toolkit.getDefaultToolkit().createImage("Data/Monster1.gif");
        monsters.add(new Monster("Маленький паук", img1, 9, 3, 0, 4, 8, 4, 0, 5, "Маленьки ловкий паучок, не представляет серьёзной опасности"));
        monsters.add(new Monster("Красная фигня", img2, 14, 4, 1, 6, 4, 3, 0, 10, "Довольно опасный монстр, сильный, но не очень ловкий,\nобладает не самым лучшим зрением"));
    }
    
    static public Monster getMonsterID(int ID){
        try{
            return monsters.get(ID);
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    static public Monster getMonsterName(String name){
        for(Monster monster: monsters){
            if(monster.getName().equalsIgnoreCase(name))
                return monster;
        }
        return null;
    }
    static public Monster getMonsterRandom(){
        int sel = ((int)(Math.random()*10000))%monsters.size();
        return monsters.get(sel).clone();
    }
}
