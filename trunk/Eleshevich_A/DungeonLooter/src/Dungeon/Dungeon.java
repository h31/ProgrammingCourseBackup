package Dungeon;

import Constants.CellType;
import Constants.CellStatus;
import Constants.PlayerSlot;
import Constants.StairType;
import Creatures.Creature;
import Creatures.Monster;
import Creatures.Player;
import GUI.Messager;
import GUI.Updatable;
import Items.BodyArmor;
import Items.Item;
import Items.ItemBase;
import Items.ItemStack;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import javax.swing.JOptionPane;

/**
 * @author Andrew
 */
public class Dungeon {
    Player player;
    ArrayDeque<Monster>[] monsters;
    ArrayDeque<ItemStack>[] itemStacks;
    Cell[][][] field;
    int currLevel;
    int counter = 0;
    int levelsNum;
    
    Updatable DScreen;
    Updatable PScreen;
    Messager mess;
    
    Dungeon(Cell[][][] field, Player player, ArrayDeque<Monster>[] monsters, Position apos){
        currLevel = 1;
        this.field = field;
        levelsNum = field.length;
        this.player = player;
        player.setDungeon(this);
        this.monsters = monsters;
        itemStacks = new ArrayDeque[levelsNum];
        for(int x = 0; x < itemStacks.length; x++)
            itemStacks[x] = new ArrayDeque<ItemStack>();
        playerSightSet(player.getPos());
        ItemStack tstack = new ItemStack(apos);
        tstack.itemPut(ItemBase.getArtifact());
        itemStacks[levelsNum-1].add(tstack);
    }
    
    public void addScreens(Updatable DungeonScreen, Updatable PlayerScreen, Messager MessageScreen){
        DScreen = DungeonScreen;
        PScreen = PlayerScreen;
        mess = MessageScreen;
        player.setMessager(mess);
    }
    
    public Player getPlayer(){
        return player;
    }
    private Cell[][] getField(){
        return field[currLevel - 1];
    }
    public Cell getCell(Position pos){
        return getCell(pos.x, pos.y);
    }
    public Cell getCell(int x, int y){
        if(y < 0 || y >= getField().length)
            return null;
        else if(x < 0 || x >= getField()[y].length)
            return null;
        return getField()[y][x];
    }
    public ArrayDeque<Monster> getMonsters(){
        return monsters[currLevel - 1];
    }
    public void movePlayer(Direction dir){
        Position oldPos = player.getPos();
        if(moveCreature(player, dir)){
            passTurn();
            playerSightRenew(oldPos, player.getPos());  //может вызывать при passTurn
        }
    }
    public void playerCloseDoor(Direction dir){
        Position tpos = player.getPos().getNewPos(dir);
        if(!getCell(tpos).getType().equals(CellType.DOOR)){
            mess.print("Там нет никакой двери");
        }else{
            Door door = (Door)getCell(tpos);
            if(door.isClosed())
                mess.print("Эта дверь и так закрыта");
            else{
                if(door.tryClose())
                    mess.print("Вы закрыли дверь");
                else
                    mess.print("Вы пытаетессь закрыть дверь, но она не поддаётся");
                passTurn();
            }
        }
    }
    public void playerUseStair(){
        Cell cell = getCell(player.getPos());
        if(!cell.getType().equals(CellType.STAIR))
            mess.print("Тут нет никакой лестницы");
        else{
            Stair stair = (Stair)cell;
            if(stair.getSType().equals(StairType.STAIR_OUT)){
                if(player.haveArtifact()){     //надо бы этот диалог куда то в другое место поместить
                    JOptionPane.showMessageDialog(null, "Поздравляю!!! Вы прошли игру!!!");
                    System.exit(1);
                }else
                    mess.print("Вам ещё рано уходить, вы ещё не раздобыли артефакт");
            }else{
                playerSightUnset(player.getPos());
                if(stair.getSType().equals(StairType.STAIR_UP))
                    currLevel--;
                else
                    currLevel++;
                player.move(stair.getTarget());
                playerSightSet(player.getPos());
                DScreen.update();
            }
        }
    }
    public boolean moveCreature(Creature creat, Direction dir){
        try{
            Position target = creat.getPos().getNewPos(dir); //переделать со switch
            try{
                if(!creat.isPlayer() && player.getPos().equals(target))
                    closeCombat(creat, player);
                else
                    closeCombat(creat, findMonster(target));
            }catch(NotFoundException nfex){ //может спервва Cell получить а потом мучить, а то по 20 раз вызывать...
                if(getCell(target) == null)   //тут тоже попробовать объединить
                    return false;
                if(getCell(target).isSolid()){
                    if(getCell(target).getType().equals(CellType.DOOR) && creat.isPlayer()){
                        ((Door)getCell(target)).tryOpen();
                        return true;
                    }else
                        return false;
                }
                else
                    creat.move(target);    //можно с проверкой на то, что двигаемое существо - игрок пересчитать зону видимости здесь
            }
            return true;
        }catch(IndexOutOfBoundsException ioex){
            return false;
        }
    }
    public void passTurn(){
        generateMonsters();
        player.passTurn();
        itemFloorRenew();
        for(Monster monster: getMonsters()){
            monster.passTurn();
            monster.AIturn(this);
        }
        System.out.println("Прошёл ход №" + counter);
        counter++;
        PScreen.update();   //возможно не надо обновлять каждый ход
        DScreen.update();
    }
    public Deque<Position> calcVision(Creature creat){ return calcVision(creat.getPos(), creat.getSightRad()); }
    public Deque<Position> calcVision(Position pos, int vrad){
        ArrayDeque<Position> res = new ArrayDeque<Position>();
        int yu, yd, trad = vrad;
        for(yu = yd = pos.y; yd-yu <= vrad*2; yu--, yd++, trad--){
            for(int x = pos.x - trad; x <= pos.x + trad; x++){
                if(getCell(x, yu) != null)
                    res.add(new Position(x, yu));
                if(getCell(x, yd) != null && yu != yd)
                    res.add(new Position(x, yd));
            }
        }
        return res;
    }
    public Monster findMonster(Position pos) throws NotFoundException{
        for(Monster monster: getMonsters()){
            if(monster.getPos().equals(pos))
                return monster;
        }
        throw new NotFoundException();
    }
    void playerSightRenew(Position oldPos, Position newPos){
        playerSightUnset(oldPos);
        playerSightSet(newPos);
    }
    void playerSightUnset(Position pos){
        for(Position tpos: calcVision(pos, player.getSightRad()))
            getField()[tpos.y][tpos.x].setStatus(CellStatus.INVISIBLE);
    }
    void playerSightSet(Position pos){
        for(Position tpos: calcVision(pos, player.getSightRad())){
            getField()[tpos.y][tpos.x].setStatus(CellStatus.VISIBLE);
        }
    }
    void closeCombat(Creature ac, Creature dc){
        int adam = dc.takeDamage(ac.getDamage());
        String message = ac.getName() + " атаковал " + dc.getName();
        if(adam >= 0)
            message += " и нанёс " + adam + " урона";
        else
            message += ", но " + dc.getName() + " увернулся";
        mess.print(message);
        if(dc.getHealth() <= 0){
            if(dc.isPlayer()){   //здесь надо по другому(вызвать ф-цию main panel, которая выведет сообение и завершит работу)
                JOptionPane.showMessageDialog(null, "Игра окончена!");
                System.exit(0);
            }else{
                Monster dm = (Monster)dc;
                mess.print(ac.getName() + " убил " + dm.getName());
                player.addXP(dm.getXPreward());
                Item[] drop = dm.getDrop();
                if(drop != null){
                    try{
                        findItemStack(dm.getPos()).itemsPut(drop);
                    }catch(Exception ex){
                        ItemStack istack = new ItemStack(dm.getPos());
                        istack.itemsPut(drop);
                        getItemStacks().add(istack);
                    }
                }
                getMonsters().remove((Monster)dc);   //проверить будет ли работать без преобразования типов
            }
        }
    }
    public Deque<ItemStack> getItemStacks(){
        return itemStacks[currLevel - 1];
    }
    void generateMonsters(){
        
    }
    ItemStack findItemStack(Position pos) throws NotFoundException{
        for(ItemStack istack: getItemStacks()){
            if(istack.getPos().equals(pos))
                return istack;
        }
        throw new NotFoundException();
    }
    void itemFloorRenew(){    //вкрутить поиск itemstck по коорд
        if(player.getItemsFloor() != null && !getItemStacks().contains(player.getItemsFloor())){
            getItemStacks().add(player.getItemsFloor());
        }
        player.setItemsFloor(null);
        Iterator<ItemStack> itt = getItemStacks().iterator();
        while(itt.hasNext()){    //итератор, чтобы по ходу удалять (проверить без него)
            ItemStack istack = itt.next();
            if(istack.isEmpty())
                itt.remove();
            else
                if(istack.getPos().equals(player.getPos()))
                    player.setItemsFloor(istack);
        }
    }
}

class NotFoundException extends Exception{
    
}