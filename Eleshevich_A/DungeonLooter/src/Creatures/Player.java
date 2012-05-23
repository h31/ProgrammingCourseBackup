package Creatures;

import Constants.CreatChar;
import Constants.ItemType;
import Constants.UseType;
import Constants.PlayerSlot;
import Items.*;
import java.awt.Toolkit;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Andrew
 */
public class Player extends Creature{
    Armor headArmor;
    Armor bodyArmor;
    Armor legArmor;
    Item rightHand;
    Item leftHand;
    int level;
    int XP;
    int hrcount = 0;    //в принципе лучше просто жизнь хранить на пару порядков больше, а использовать поделив
    
    Item[] inventory = new Item[10];    //можно задать в конструкторе
    ItemStack itemsFloor;   //может не стак, а просто массив
    
    //public static final int LEFT_HAND = 4;
    //public static final int RIGHT_HAND = 3;
    //public static final int BODY = 2;
    //public static final int HEAD = 1;
    //public static final int LEGS = 5;
    
    public Player(String name, int maxhealth, int defence, int strength, int dexterity, int hregen, int sightradius){
        super(name, Toolkit.getDefaultToolkit().createImage("Data/player.gif"), maxhealth, defence,
                strength, dexterity, hregen, sightradius);
        level = 1;
        XP = 0;
    }
    
    public Armor putOn(BodyArmor armor) throws InvalidArmorTypeException{
        Armor oldArmor;
        switch(armor.getSlotType()){
            case HEAD:{
                oldArmor = headArmor;
                headArmor = armor;
                break;
            }
            case BODY:{
                oldArmor = bodyArmor;
                headArmor = armor;
                break;
            }
            case LEGS:{
                oldArmor = legArmor;
                legArmor = armor;
                break;
            }
            default: throw new InvalidArmorTypeException();
        }
        int oldDef;
        if(oldArmor == null)
            oldDef = 0;
        else
            oldDef = oldArmor.getDefence();
        defence += armor.getDefence() - oldDef;
        return oldArmor;
    }
    public int getXP(){
        return XP;
    }
    public int getLevel(){
        return level;
    }
    public int getXPcap(){
        return 1 + level*10;
    }
    public boolean levelUP(CreatChar pchar){
        if(levelUPready()){
            switch(pchar){
                case MAXHEALTH: maxhealth += 2;
                case STRENGTH: strength += 1;
                case DEXTERITY: dexterity += 1;
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
        if(item.getUseType() != UseType.WIELDABLE)
            return null;
        Item oldItem = null;
        switch(hand){
            case RIGHT_HAND: oldItem = rightHand; rightHand = item; break;
            case LEFT_HAND: oldItem = leftHand; leftHand = item; break;
        }
        return oldItem;
    }
    
    public Item inventoryGet(int num){
        return inventory[num];
    }
    
    public void inventoryPut(Item item) throws InventoryFullException{
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
        
    }
    @Override
    public void passTurn(){
        if(health < maxhealth){
            hrcount ++;
            if(hrcount >= hregen){
                hrcount = 0;
                health++;
            }
        }
    }
    @Override
    public Damage getDamage(){
        int damage = 0;
        if(rightHand != null)
            if(rightHand.getType() == ItemType.WEAPON)
                damage += ((Weapon)rightHand).getDamage();
        if(leftHand != null)
            if(leftHand.getType() == ItemType.WEAPON)
                damage += ((Weapon)leftHand).getDamage();
        return new Damage(damage, strength, dexterity);
    }
    
    public void setItemsFloor(ItemStack istack){
        itemsFloor = istack;
    }
    
    public ItemStack getItemsFloor(){
        return itemsFloor;
    }
    public void dropToFloor(Item item){ //может сразу индекс, хотя вообще лучше просто itemsfloor хранить не тут
        if(itemsFloor == null)  //всё равно по ходу данж нужно будет в PlayerPanel передавать
            itemsFloor = new ItemStack(pos);
        itemsFloor.itemPut(item);
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