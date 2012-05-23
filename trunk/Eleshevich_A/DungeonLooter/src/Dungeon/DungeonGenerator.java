package Dungeon;

import Constants.CellType;
import Creatures.Bestiary;
import Creatures.Monster;
import Creatures.Player;
import Constants.PlayerSlot;
import Items.Armor;
import Items.BodyArmor;
import Items.ItemBase;
import Items.Weapon;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.*;
import java.util.ArrayDeque;

/**
 * @author Andrew
 */
public class DungeonGenerator {
    public static Dungeon generateDungeon(String pname){
        Player player = new Player(pname, 20, 0, 10, 10, 6, 4);
        ArrayDeque<Monster> monsters = new ArrayDeque<Monster>();
        Cell[][] field = new Cell[500][500];
        int by = 150;
        for(int x = 100; x <= 110; x++)
            field[by][x] = new Cell(CellType.WALL);
        int bx = 100;
        for(int y = 151; y <= 160; y++)
            field[y][bx] = new Cell(CellType.WALL);
        bx = 110;
        for(int y = 151; y <= 160; y++)
            field[y][bx] = new Cell(CellType.WALL);
        by = 161;
        for(int x = 100; x <= 110; x++)
            field[by][x] = new Cell(CellType.WALL);
        for(int y = 151; y <= 160; y++){
            for(int x = 101; x <= 109; x++){
                field[y][x] = new Cell(CellType.FLOOR);
            }
        }
        player.move(new Position(105, 155));
        try{    //переписать с использованием ItemBase
            player.inventoryPut(ItemBase.getItemID(0));
            player.wieldHand(ItemBase.getItemID(1), PlayerSlot.RIGHT_HAND);
            player.putOn((BodyArmor)ItemBase.getItemID(3));
        }catch(Exception ex){
            System.out.println(ex.getMessage());
        }
        Monster m1 = Bestiary.getMonsterID(0);
        m1.move(new Position(107, 158));
        monsters.add(m1);
        return new Dungeon(field, player, monsters);
    }
    public static Dungeon loadDungeon(File file, Player player) throws LoadingException{
        try{
            Cell[][] field = new Cell[500][500];
            ArrayDeque<Monster> monsters = new ArrayDeque<Monster>();
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
            for(int y = 0; y < 500; y++){
                String line = br.readLine();
                for(int x = 0; x < 500; x++){
                    switch(line.charAt(x)){
                        case '#': field[y][x] = new Cell(CellType.WALL); break;
                        case '.': field[y][x] = new Cell(CellType.FLOOR); break;
                        case 'M': field[y][x] = new Cell(CellType.FLOOR);
                            Monster m = Bestiary.getMonsterRandom();
                            break;
                        case '@': field[y][x] = new Cell(CellType.FLOOR);
                            player.move(new Position(x, y));
                            break;
                    }
                }
            }
            return new Dungeon(field, player, monsters);
        }catch(IOException ioex){
            throw new LoadingException("Не удалось открыть файл");
        }
    }
}
