package Dungeon;

import Creatures.Monster;
import Creatures.Player;
import Items.Armor;
import Items.BodyArmor;
import Items.Weapon;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.File;
import java.util.ArrayDeque;

/**
 * @author Andrew
 */
public class DungeonGenerator {
    public static Dungeon generateDungeon(String pname){
        Player player = new Player(pname, 20, 0, 10, 10, 4);
        ArrayDeque<Monster> monsters = new ArrayDeque<Monster>();
        Cell[][] field = new Cell[500][500];
        int by = 150;
        for(int x = 100; x <= 110; x++)
            field[by][x] = new Cell(Cell.WALL);
        int bx = 100;
        for(int y = 151; y <= 160; y++)
            field[y][bx] = new Cell(Cell.WALL);
        bx = 110;
        for(int y = 151; y <= 160; y++)
            field[y][bx] = new Cell(Cell.WALL);
        by = 161;
        for(int x = 100; x <= 110; x++)
            field[by][x] = new Cell(Cell.WALL);
        for(int y = 151; y <= 160; y++){
            for(int x = 101; x <= 109; x++){
                field[y][x] = new Cell(Cell.FLOOR);
            }
        }
        player.move(new Position(105, 155));
        try{
            Image sword1 = Toolkit.getDefaultToolkit().createImage("Data/Sword2.gif");
            Image sword2 = Toolkit.getDefaultToolkit().createImage("Data/IronSword.gif");
            Image pants = Toolkit.getDefaultToolkit().createImage("Data/LeatherPants.gif");
            System.out.println("Point 1");
            player.inventoryPut(new Weapon("Мега меч", sword1, 4, Weapon.SWORD));
            System.out.println("Point 2");
            player.wieldHand(new Weapon("Железный меч", sword2, 3, Weapon.SWORD), Player.RIGHT_HAND);
            System.out.println("Point 3");
            player.putOn(new BodyArmor("Штаны", pants, 1, Player.LEGS));
            System.out.println("Point 4");
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        Monster m1 = new Monster("Паукан", 8, 5, 1, 2, 10, 4);
        m1.move(new Position(107, 158));
        monsters.add(m1);
        return new Dungeon(field, player, monsters);
    }
    public static Dungeon loadDungeon(File file, Player player){
        return null;
    }
}
