package Creatures;

import java.awt.Toolkit;
import java.util.ArrayList;

/**
 * @author Andrew
 */
public class Bestiary{
    private static ArrayList<Monster> monsters = new ArrayList<Monster>();
    
    public static void setBestiaryDefault(){
        Toolkit tlk = Toolkit.getDefaultToolkit();
        monsters.add(new Monster("Маленький паук", tlk.createImage("Data/Spider1.gif"), 9, 3, 0, 4, 8, 4, 0,
                5, "Маленьки ловкий паучок, не представляет серьёзной опасности", 1));
        monsters.add(new Monster("Красная фигня", tlk.createImage("Data/Monster1.gif"), 14, 4, 1, 6, 4, 3, 0,
                6, "Довольно опасный монстр, сильный, но не очень ловкий,\nобладает не самым лучшим зрением", 2));
    }
    
    static public Monster getMonsterID(int ID){
        try{
            return monsters.get(ID - 1).clone();
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    static public Monster getMonsterName(String name){
        for(Monster monster: monsters){
            if(monster.getName().equalsIgnoreCase(name))
                return monster.clone();
        }
        return null;
    }
    static public Monster getMonsterRandom(){
        int sel = ((int)(Math.random()*10000))%monsters.size();
        return monsters.get(sel).clone();
    }
}
