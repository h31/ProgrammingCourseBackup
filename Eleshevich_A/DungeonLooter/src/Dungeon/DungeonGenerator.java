package Dungeon;

import Constants.CellStatus;
import Constants.CellType;
import Creatures.Bestiary;
import Creatures.Monster;
import Creatures.Player;
import Constants.PlayerSlot;
import Constants.StairType;
import Items.Armor;
import Items.BodyArmor;
import Items.ItemBase;
import Items.Weapon;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

/**
 * @author Andrew
 */
public class DungeonGenerator {
//    public static Dungeon generateDungeon(String pname){
//        Player player = new Player(pname, 20, 0, 10, 10, 4, 4);
//        ArrayDeque<Monster> monsters1 = new ArrayDeque<Monster>();
//        Cell[][] floor1 = new Cell[500][500];
//        int by = 150;
//        for(int x = 100; x <= 110; x++)
//            floor1[by][x] = new Wall();
//        int bx = 100;
//        for(int y = 151; y <= 160; y++)
//            floor1[y][bx] = new Wall();
//        bx = 110;
//        for(int y = 151; y <= 160; y++)
//            floor1[y][bx] = new Wall();
//        by = 161;
//        for(int x = 100; x <= 110; x++)
//            floor1[by][x] = new Wall();
//        for(int y = 151; y <= 160; y++){
//            for(int x = 101; x <= 109; x++){
//                floor1[y][x] = new Floor();
//            }
//        }
//        player.move(new Position(105, 155));
//        try{    //переписать с использованием ItemBase
//            player.inventoryPut(ItemBase.getItemID(0));
//            player.wieldHand(ItemBase.getItemID(1), PlayerSlot.RIGHT_HAND);
//            player.putOn((BodyArmor)ItemBase.getItemID(3));
//        }catch(Exception ex){
//            System.out.println(ex.getMessage());
//        }
//        Monster m1 = Bestiary.getMonsterID(0);
//        m1.move(new Position(107, 158));
//        monsters1.add(m1);
//        Cell[][][] field = new Cell[1][][];
//        field[0] = floor1;
//        ArrayDeque[] monsters = new ArrayDeque[1];
//        monsters[0] = monsters1;
//        return new Dungeon(field, player, monsters);
//    }
    public static Dungeon loadDungeon(String pname) throws LoadingException{
        try{
            Player player = new Player(pname, 20, 0, 7, 6, 4, 4);
            player.wieldHand(ItemBase.getItemName("Деревянный меч"), PlayerSlot.RIGHT_HAND);
            player.wieldHand(ItemBase.getItemName("Деревянный щит"), PlayerSlot.LEFT_HAND);
            player.putOn((BodyArmor)ItemBase.getItemName("Штаны"));
            player.inventoryPut(ItemBase.getItemName("Зелье здоровья"));
            player.inventoryPut(ItemBase.getItemName("Зелье силы"));
            player.inventoryPut(ItemBase.getItemName("Железный шлем"));
            player.inventoryPut(ItemBase.getItemName("Железная броня"));
            player.inventoryPut(ItemBase.getItemName("Железные поножи"));
            player.inventoryPut(ItemBase.getItemName("Железный щит"));
            Position apos = null;
            String mainDir = "Map/";
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(mainDir+"data.txt")));
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayDeque<File> floorFiles = new ArrayDeque<File>();
            while(st.hasMoreTokens())
                floorFiles.add(new File(mainDir + st.nextToken()));
            int levels = floorFiles.size();
            Cell[][][] field = new Cell[levels][][];
            ArrayDeque[] monsters = new ArrayDeque[levels];
            for(int level = 0; level < levels; level++){
                BufferedReader lbr = new BufferedReader(new InputStreamReader(new FileInputStream(floorFiles.pollFirst())));
                ArrayDeque<String> lines = new ArrayDeque<String>();
                boolean end = false;
                while(!end){
                    String tstr = lbr.readLine();
                    if(tstr == null)
                        end = true;
                    else
                        lines.add(tstr);
                }
                int ySize, xSize;
                ySize = lines.size();
                xSize = 0;
                for(String tstr: lines)
                    if(tstr.length() > xSize)
                        xSize = tstr.length();
                ArrayDeque<Monster> tmonsters = new ArrayDeque<Monster>();
                Cell[][] floor = new Cell[ySize][xSize];
                for(int y = 0; y < ySize; y++){
                    char[] line = lines.pollFirst().toCharArray();
                    for(int x = 0; x < line.length; x++){
                        switch(line[x]){
                            case '#': floor[y][x] = new Wall(); break;
                            case '.': floor[y][x] = new Floor(); break;
                            case 'M': floor[y][x] = new Floor();
                                Monster m = Bestiary.getMonsterRandom();
                                m.move(new Position(x, y));
                                tmonsters.add(m);
                                break;
                            case 'A':{
                                if(level != levels - 1)
                                    throw new LoadingException("Артефакт должен быть на последнем уровне");
                                else if(apos != null)
                                    throw new LoadingException("Артефакт должен быть один");
                                else{
                                    floor[y][x] = new Floor();
                                    apos = new Position(x, y);
                                }
                                break;
                            }
                            case 'D': floor[y][x] = new Door((int)(Math.random()*100)%4 + 1); break;
                            case 'd': floor[y][x] = new Stair(StairType.STAIR_DOWN); break;
                            case 'u': floor[y][x] = new Stair(StairType.STAIR_UP); break;
                        }
                    }
                }
                field[level] = floor;
                monsters[level] = tmonsters;
            }
            Position spos = findStair(field[0], StairType.STAIR_UP);
            ((Stair)field[0][spos.y][spos.x]).changeSType(StairType.STAIR_OUT);
            player.move(spos);
            for(int l = 0; l < levels; l++){
                if(l != levels-1){
                    Position std1 = findStair(field[l], StairType.STAIR_DOWN);
                    ((Stair)field[l][std1.y][std1.x]).setTarget(findStair(field[l+1], StairType.STAIR_UP));
                }
                if(l != 0){
                    Position std2 = findStair(field[l], StairType.STAIR_UP);
                    ((Stair)field[l][std2.y][std2.x]).setTarget(findStair(field[l-1], StairType.STAIR_DOWN));
                }
            }
            return new Dungeon(field, player, monsters, apos);
        }catch(Exception ex){
            throw new LoadingException("По этой причине: " + ex.toString());
        }
    }
    static Position findStair(Cell[][] floor, StairType stype) throws ExcessStairsException, StairNotFoundException{
        Position res = null;
        boolean found = false;
        for(int y = 0; y < floor.length; y++){
            for(int x = 0; x < floor[y].length; x++){
                if(floor[y][x] != null)
                    if(floor[y][x].getType().equals(CellType.STAIR)){
                        Stair st = (Stair)floor[y][x];
                        if(st.getSType().equals(stype)){
                            if(!found){
                                res = new Position(x, y);
                                found = true;
                            }else
                                throw new ExcessStairsException();
                        }
                    }
            }
        }
        if(found)
            return res;
        else
            throw new StairNotFoundException();
    }
}

class ExcessStairsException extends Exception{
    
}

class StairNotFoundException extends Exception{
    
}