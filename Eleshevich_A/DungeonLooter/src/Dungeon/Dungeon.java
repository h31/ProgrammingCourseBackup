package Dungeon;

import Creatures.Creature;
import Creatures.Monster;
import Creatures.Player;
import GUI.Messager;
import GUI.SimpleMessager;
import GUI.Updatable;
import Items.Item;
import Items.ItemStack;
import java.util.ArrayDeque;
import java.util.Deque;
import javax.swing.JOptionPane;

/**
 * @author Andrew
 */
public class Dungeon {
    Player player;
    ArrayDeque<Monster> monsters;
    ArrayDeque<ItemStack> ItemStacks;
    Cell[][] field;
    
    Updatable DScreen;
    Updatable PScreen;
    Messager message;
    
    public static final int UP = 1;
    public static final int LEFT = 2;
    public static final int RIGHT = 3;
    public static final int DOWN = 4;
    
    Dungeon(Cell[][] field, Player player, ArrayDeque<Monster> monsters){
        this.field = field;
        this.player = player;
        this.monsters = monsters;
        ItemStacks = new ArrayDeque<ItemStack>();
        playerSightRenew(player.getPos(), player.getPos());
    }
    
    public void addScreens(Updatable DungeonScreen, Updatable PlayerScreen, Messager MessageScreen){
        DScreen = DungeonScreen;
        PScreen = PlayerScreen;
        message = MessageScreen;
    }
    
    public Player getPlayer(){
        return player;
    }
    public Cell[][] getField(){
        return field;
    }
    public Cell getCell(Position pos){
        return field[pos.y][pos.x];
    }
    public ArrayDeque<Monster> getMonsters(){
        return monsters;
    }
    public void movePlayer(int direction){
        Position oldPos = player.getPos();
        if(moveCreature(player, direction)){
            passTurn();
            playerSightRenew(oldPos, player.getPos());  //может вызывать при passTurn
            playerItemFloorRenew();
        }
    }
    public boolean moveCreature(Creature creat, int direction){
        try{
            Position target = new Position(creat.getPos()); //переделать со switch
            if(direction == UP){
                target.y--;
            }else if(direction == LEFT){
                target.x--;
            }else if(direction == RIGHT){
                target.x++;
            }else if(direction == DOWN){
                target.y++;
            }
            try{
                if(player.getPos().equals(target))
                    attack(creat, player);
                else
                    attack(creat, findMonster(target));
            }catch(NotFoundException nfex){
                if(field[target.y][target.x] == null)   //тут тоже попробовать объединить
                    return false;
                if(field[target.y][target.x].getType() == Cell.WALL)
                    return false;
                else{
                    creat.move(target);    //можно с проверкой на то, что двигаемое существо - игрок пересчитать зону видимости здесь
                }
            }
            return true;
        }catch(IndexOutOfBoundsException ioex){
            return false;
        }
    }
    public void passTurn(){
        generateMonsters();
        for(Monster monster: monsters)
            monster.AIturn(this);
        PScreen.update();   //возможно не надо обновлять каждый ход
        DScreen.update();
    }
    public Deque<Position> calcVision(Creature creat){ return calcVision(creat.getPos(), creat.getSightRad()); }
    public Deque<Position> calcVision(Position pos, int vrad){
        ArrayDeque<Position> res = new ArrayDeque<Position>();
        int yu, yd, trad = vrad;
        for(yu = yd = pos.y; yd-yu <= vrad*2; yu--, yd++, trad--){
            for(int x = pos.x - trad; x <= pos.x + trad; x++){
                if(field[yu][x] != null)
                    res.add(new Position(x, yu));
                if(field[yd][x] != null && yu != yd)
                    res.add(new Position(x, yd));
            }
        }
        return res;
    }
    public Monster findMonster(Position pos) throws NotFoundException{
        for(Monster monster: monsters){
            if(monster.getPos().equals(pos))
                return monster;
        }
        throw new NotFoundException();
    }
    void playerSightRenew(Position oldPos, Position newPos){
        for(Position pos: calcVision(oldPos, player.getSightRad()))
            field[pos.y][pos.x].setStatus(Cell.INVISIBLE);
        for(Position pos: calcVision(newPos, player.getSightRad()))
            field[pos.y][pos.x].setStatus(Cell.VISIBLE);
    }
    void attack(Creature ac, Creature dc){
        int adam = dc.attack(ac.getDamage());
        message.print(ac.getName() + " атаковал " + dc.getName() + " и нанёс " + adam + " урона");
        if(dc.getHealth() <= 0){
            if(dc == player){   //здесь надо по другому(вызвать ф-цию main panel, которая выведет сообение и завершит работу)
                JOptionPane.showMessageDialog(null, "Игра окончена!");
                System.exit(0);
            }else{
                message.print(ac.getName() + " убил " + dc.getName());
                monsters.remove((Monster)dc);   //проверить будет ли работать без преобразования типов
            }
        }
    }
    public Deque<ItemStack> getItemStacks(){
        return ItemStacks;
    }
    void generateMonsters(){
        
    }
    void playerItemFloorRenew(){    //вкрутить поиск itemstck по коорд
        if(player.getItemsFloor() != null && !ItemStacks.contains(player.getItemsFloor())){
            ItemStacks.add(player.getItemsFloor());
        }
        for(ItemStack istack: ItemStacks){
            if(istack.getPos().equals(player.getPos())){
                player.setItemsFloor(istack);
                return;
            }
        }
        player.setItemsFloor(null);
    }
}

class NotFoundException extends Exception{
    
}