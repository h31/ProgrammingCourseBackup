package GUI;

import Constants.*;
import Creatures.Player;
import Creatures.PlayerException;
import Dungeon.Dungeon;
import Items.BodyArmor;
import Items.Item;
import Items.Usable;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class PlayerPanel extends JPanel implements Updatable{
    Player player;    
    ArrayDeque<ItemSlot> slots;
    Point[] invTxt;
    
    PlayerPanel(Player player){
        invTxt = new Point[2];
        this.player = player;
        setSlots(294, 710, 170, 36, 10);
        this.addMouseListener(new SlotMouseAdapter(slots, this));
    }
    
    @Override
    public void paint(Graphics g){
        int width = getWidth();
        int height = getHeight();
        setSlotItems();
        g.setColor(Color.lightGray);
        g.fillRect(0, 0, width, height);
        g.setColor(Color.BLACK);
        g.setFont(new Font("Lucid", Font.PLAIN, 13));
        FontMetrics fm = g.getFontMetrics();
        int x, y;
        x = 10;
        y = 16;
        g.drawString(player.getName(), x, y);
        y += fm.getHeight();
        g.drawString("Уровень: " + player.getLevel(), x, y);
        y += fm.getHeight();
        g.drawString("Здоровье: " + player.getHealth() + " / " + player.getMaxHealth(), x, y);
        y += fm.getHeight();
        g.drawString("Опыт: " + player.getXP() + "/" + player.getXPcap(), x, y);
        y += fm.getHeight();
        g.drawString("Защита: " + player.getDefence(), x, y);
        y += fm.getHeight();
        g.drawString("Сила: " + player.getStrength(), x, y);
        y += fm.getHeight();
        g.drawString("Ловкость: " + player.getDexterity(), x, y);
        y += fm.getHeight();
        g.drawString("Регенерация: " + player.getHealthRegen(), x, y);
        g.drawString("Инвентарь", invTxt[0].x, invTxt[0].y);
        g.drawString("Лежит на полу", invTxt[1].x, invTxt[1].y);
        for(ItemSlot is: slots)
            is.drawSlot(g, this);
    }
    @Override
    public void update(){
        if(player.levelUPready()){
            int res = SimpleDialog.levelUpDialog(player.getLevel() + 1, this);
            switch(res){
                case 0: player.levelUP(CreatChar.MAXHEALTH); break;
                case 1: player.levelUP(CreatChar.STRENGTH); break;
                case 2: player.levelUP(CreatChar.DEXTERITY); break;
            }
        }
        repaint();
    }
    void setSlots(int width, int height, int startline, int tileSize, int space){
        slots = new ArrayDeque<ItemSlot>();
        ItemSlot.setSize(tileSize);
        int x ,y;
        int bigSpace = 40;
        y = startline;
        x = width/2 - tileSize/2;
        slots.add(new ItemSlot(new Point(x, y), 1, SlotType.EQUIPPED));
        y += tileSize + space;
        slots.add(new ItemSlot(new Point(x, y), 2, SlotType.EQUIPPED));
        slots.add(new ItemSlot(new Point(x - tileSize - space, y), 3, SlotType.EQUIPPED));
        slots.add(new ItemSlot(new Point(x + tileSize + space, y), 4, SlotType.EQUIPPED));
        y += tileSize + space;
        slots.add(new ItemSlot(new Point(x, y), 5, SlotType.EQUIPPED));
        int bx = width/2 - (tileSize*5 + space*4)/2;
        y += tileSize + bigSpace;
        invTxt[0] = new Point(bx, y - 5);
        for(int b = 0; b < 2; b++){
            x = bx;
            for(int f = 0; f < 5; f++){
                slots.add(new ItemSlot(new Point(x, y), f + b*5, SlotType.INVENTORY));
                x += tileSize + space;
            }
            y += tileSize + space;
        }
        y += (bigSpace - space);
        invTxt[1] = new Point(bx, y - 5);
        for(int b = 0; b < 2; b++){
            x = bx;
            for(int f = 0; f < 5; f++){
                slots.add(new ItemSlot(new Point(x, y), f + b*5, SlotType.FLOOR));
                x += tileSize + space;
            }
            y += tileSize + space;
        }
    }
    
    void setSlotItems(){
        Iterator<ItemSlot> itt = slots.iterator();
        for(int x = 1; x < 6; x++)
            try{
                itt.next().setItem(player.getEquippedItem(PlayerSlot.getSlot(x)));
            }catch(InvalidConstantException icex){ System.err.println(icex.getMessage()); }
        for(int x = 0; x < 10; x++)
            itt.next().setItem(player.inventoryGet(x));
        if(player.getItemsFloor() != null)
            for(int x = 0; x < 10; x++)
                itt.next().setItem(player.getItemsFloor().itemGet(x));
        else
            for(int x = 0; x < 10; x++)
                itt.next().setItem(null);
    }
    
    void itemSelected(int number, SlotType slotType){
        try{
            Item item;
            switch(slotType){
                case EQUIPPED: item = player.getEquippedItem(PlayerSlot.getSlot(number)); break;
                case INVENTORY: item = player.inventoryGet(number); break;
                case FLOOR: item = player.getItemsFloor().itemGet(number); break;
                default: return;
            }
            if(SimpleDialog.dialogItem(item, slotType, this) != 1)
                return;
            if(item.getUseType().equals(UseType.NONE))
                return;
            switch(slotType){
                case EQUIPPED: player.inventoryPut(player.takeOff(PlayerSlot.getSlot(number))); return;
                case INVENTORY: player.inventoryTake(number); break;
                case FLOOR: player.getItemsFloor().itemTake(number); break;
            }
            switch(item.getUseType()){
                case PUTABLE: player.inventoryPut(player.putOn((BodyArmor)item)); break;
                case WIELDABLE: player.inventoryPut(player.wieldHand(item, SimpleDialog.handDialog(this))); break;
                case USABLE: player.use((Usable)item); break;
            }
            boolean putback = false;
            if(item.getUseType().equals(UseType.USABLE))
                if(!((Usable)item).isUsed())
                    putback = true;
            if(putback)
                putback(item, number, slotType);
        }catch(PlayerException pex){
            JOptionPane.showMessageDialog(this, pex.getDialogMessage(), "Ошибка", JOptionPane.ERROR_MESSAGE);
        }catch(Exception ex){
            System.err.println(ex.getMessage());
        }
    }
    boolean putback(Item item, int number, SlotType stype){
        try{
            switch(stype){
                case EQUIPPED:{
                    switch(item.getUseType()){
                        case PUTABLE: player.putOn((BodyArmor)item); break;
                        case WIELDABLE: player.wieldHand(item, PlayerSlot.getSlot(number)); break;
                    }
                    break;
                }
                case INVENTORY: player.inventoryPut(item); break;
                case FLOOR: player.getItemsFloor().itemPut(item); break;
            }
            return true;
        }catch(Exception ex){
            System.out.println("Putback error: " + ex.getMessage());
            return false;
        }
    }
    void itemRClicked(int number, SlotType slotType){
        try{
            switch(slotType){
                case EQUIPPED: player.inventoryPut(player.takeOff(PlayerSlot.getSlot(number))); break;
                case FLOOR: player.pickUpFloor(number); break;
                case INVENTORY: player.dropInvFloor(number); break;
            }
        }catch(PlayerException pex){
            JOptionPane.showMessageDialog(this, pex.getDialogMessage(), "Ошибка", JOptionPane.ERROR_MESSAGE);
        }catch(Exception ex){
            System.err.println(ex.getMessage());
        }
    }
}

class SlotMouseAdapter extends MouseAdapter{
    Deque<ItemSlot> slots;
    PlayerPanel panel;
    
    SlotMouseAdapter(Deque<ItemSlot> slots, PlayerPanel panel){
        this.slots = slots;
        this.panel = panel;
    }
    
    @Override
    public void mouseClicked(MouseEvent e){
        for(ItemSlot slot: slots){
            if(slot.clicked(e.getPoint())){
                switch(e.getButton()){
                    case MouseEvent.BUTTON1: if(!slot.isEmpty()) panel.itemSelected(slot.getNumber(), slot.getType()); break;
                    case MouseEvent.BUTTON3: if(!slot.isEmpty()) panel.itemRClicked(slot.getNumber(), slot.getType()); break;
                }
            }
        }
    }
}