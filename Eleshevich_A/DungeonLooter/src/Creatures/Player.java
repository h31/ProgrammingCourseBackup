package Creatures;

import Constants.CreatChar;
import Constants.ItemType;
import Constants.UseType;
import Constants.PlayerSlot;
import Dungeon.DefaultTimeSpace;
import Dungeon.Dungeon;
import Dungeon.TimeSpace;
import GUI.DefaultMessager;
import GUI.Messager;
import Items.*;
import java.awt.Toolkit;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Andrew
 */
public class Player extends Creature{
    TimeSpace dungeon = new DefaultTimeSpace();    //может потом какой нибудь интерфейс, пока так
    Messager mess = new DefaultMessager();
    Armor headArmor;
    Armor bodyArmor;
    Armor legArmor;
    Item rightHand;
    Item leftHand;
    int level;
    int XP;    //в принципе лучше просто жизнь хранить на пару порядков больше, а использовать поделив
    
    Item[] inventory = new Item[10];    //можно задать в конструкторе
    ItemStack itemsFloor;   //может не стак, а просто массив
    
    public Player(String name, int maxhealth, int defence, int strength, int dexterity, int hregen, int sightradius){
        super(name, Toolkit.getDefaultToolkit().createImage("Data/player.gif"), maxhealth, defence,
                strength, dexterity, hregen, sightradius);
        level = 1;
        XP = 0;
    }
    
    public void setDungeon(Dungeon dungeon){
        this.dungeon = dungeon;
    }
    public void setMessager(Messager mess){
        this.mess = mess;
    }
    public BodyArmor putOn(BodyArmor armor) throws InvalidArmorTypeException{
        Item oldArmor = takeOff(armor.getSlotType());
        switch(armor.getSlotType()){
            case HEAD: headArmor = armor; break;
            case BODY: bodyArmor = armor; break;
            case LEGS: legArmor = armor; break;
            default: throw new InvalidArmorTypeException();
        }
        defence += armor.getDefence();
        dungeon.passTurn();
        return (BodyArmor)oldArmor;
    }
    public int getXP(){
        return XP;
    }
    public int getLevel(){
        return level;
    }
    public int getXPcap(){
        return level*8 + (int)((8/3d)*(level-1));
    }
    public void addXP(int val){
        XP += val;
    }
    public boolean levelUP(CreatChar pchar){
        if(levelUPready()){
            switch(pchar){
                case MAXHEALTH: maxhealth += 2; break;
                case STRENGTH: strength += 1; break;
                case DEXTERITY: dexterity += 1; break;
            }
            level++;
            return true;
        }
        else
            return false;
    }
    public boolean levelUPready(){
        return XP >= getXPcap();
    }
    public Item wieldHand(Item item, PlayerSlot hand){    //может придумать название получше, пересчёт дамага, а если не только дамаг???
        if(!item.getUseType().equals(UseType.WIELDABLE))
            return null;
        Item oldItem = takeOff(hand);
        switch(hand){
            case RIGHT_HAND: rightHand = item; break;
            case LEFT_HAND: leftHand = item; break;
        }
        if(item.isArmor())
            defence += ((Armor)item).getDefence();
        mess.print("Вы берёте в руку " + item.getName());   //надо уточнить в какую
        dungeon.passTurn();
        return oldItem;
    }
    
    public Item inventoryGet(int num){
        return inventory[num];
    }
    public boolean inventoryIsFull(){
        boolean res = true;
        for(Item item: inventory)
            if(item == null)
                res = false;
        return res;
    }
    
    public void inventoryPut(Item item) throws InventoryFullException{
        if(item == null)
            return;
        for(int x = 0; x < inventory.length; x++)
            if(inventory[x] == null){
                inventory[x] = item;
                return;
            }
        throw new InventoryFullException();
    }
    
    public Item inventoryTake(int num){
        Item item = inventory[num];
        inventory[num] = null;
        return item;
    }
    public void pickUpFloor(int number) throws InventoryFullException{
        inventoryPut(itemsFloor.itemGet(number));
        itemsFloor.itemTake(number);
        dungeon.passTurn();
    }
    public void dropFloor(int number){
        if(itemsFloor == null)
            itemsFloor = new ItemStack(pos);
        itemsFloor.itemPut(inventoryTake(number));
        dungeon.passTurn();
    }
    public Item takeOff(PlayerSlot slotNum){
        Item item;
        switch(slotNum){
            case LEFT_HAND: item = leftHand; leftHand = null; break;
            case RIGHT_HAND: item = rightHand; rightHand = null; break;
            case BODY: item = bodyArmor; bodyArmor = null; break;
            case HEAD: item = headArmor; headArmor = null; break;
            case LEGS: item = legArmor; legArmor = null; break;
            default: item = null;   //может нужно исключение
        }
        if(item != null){
            if(item.getType().equals(ItemType.ARMOR))
                defence -= ((Armor)item).getDefence();
            mess.print("Вы убираете в инвентарь " + item.getName());    //надоу точнить - снимаете или убираете из руки
            dungeon.passTurn();
        }
        return item;
    }
    
    public Item getEquippedItem(PlayerSlot slotNum){
        switch(slotNum){
            case LEFT_HAND: return leftHand;
            case RIGHT_HAND: return rightHand;
            case BODY: return bodyArmor;
            case HEAD: return headArmor;
            case LEGS: return legArmor;
            default: return null;
        }
    }
    
    public void use(Usable item){
        buffs.add(item.use());
        dungeon.passTurn();
    }
    @Override
    public Damage getDamage(){
        int damage = 0;
        if(rightHand != null)
            if(rightHand.isWeapon())
                damage += ((Weapon)rightHand).getDamage();
        if(leftHand != null)
            if(leftHand.isWeapon())
                damage += ((Weapon)leftHand).getDamage();
        damage += (int)(strength/5d);
        return new Damage(damage, strength, dexterity);
    }
    
    public void setItemsFloor(ItemStack istack){
        itemsFloor = istack;
    }
    
    public ItemStack getItemsFloor(){
        return itemsFloor;
    }
    public boolean haveArtifact(){
        boolean getArt = false;
        for(Item item: inventory)
            if(item != null)
                if(ItemBase.isArtifact(item)){
                    getArt = true;
                    break;
                }
        return getArt;
    }
    @Override
    public boolean isPlayer(){
        return true;
    }
}

class InvalidArmorTypeException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Неверный тип брони";
    }
}

class UnequipabbleItemException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Unequipabble Item Error";
    }
}

class UnusableItemException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Item is unusable";
    }
}