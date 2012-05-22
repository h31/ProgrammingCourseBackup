package GUI;

import Creatures.Player;
import Creatures.PlayerException;
import Dungeon.Dungeon;
import Items.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class PlayerPanel extends JPanel implements Updatable{
    Player player;
    Dungeon dungeon;    
    ArrayDeque<ItemSlot> slots;
    Point[] invTxt;
    
    PlayerPanel(Dungeon dungeon){
        this.dungeon = dungeon;
        player = dungeon.getPlayer();
        int space = 10;
        int tileSize = 36;  //задавать автоматически и придумать другое название
        int by = 140;
        invTxt = setSlots(294, 710, 140, 36, 10);
        this.addMouseListener(new SlotMouseAdapter(slots, this)); //опасно при вызове setSlots тут всё слетит
    }
    
    @Override
    public void paint(Graphics g){
        int width = getWidth();
        int height = getHeight();
        setSlotItems();
        g.setColor(Color.lightGray);
        g.fillRect(0, 0, width, height);
        //System.out.println("Width/Height: " + width + "/" + height);
        g.setColor(Color.BLACK);
        g.setFont(new Font("Lucid", Font.PLAIN, 13));
        FontMetrics fm = g.getFontMetrics();
        int dh = 0;
        int x, y;
        x = 10;
        y = 16;
        g.drawString(player.getName(), x, y);
        y += fm.getHeight();
        g.drawString("Здоровье: " + player.getHealth() + " / " + player.getMaxHealth(), x, y);
        y += fm.getHeight();
        g.drawString("Защита: " + player.getDefence(), x, y);
        g.drawString("Инвентарь", invTxt[0].x, invTxt[0].y);
        g.drawString("Лежит на полу", invTxt[1].x, invTxt[1].y);
        for(ItemSlot is: slots)
            is.drawSlot(g, this);
    }
    @Override
    public void update(){
        repaint();
    }
    
    Point[] setSlots(int width, int height, int startline, int tileSize, int space){  //space можно и не задавать в арг
        slots = new ArrayDeque<ItemSlot>();
        ItemSlot.setSize(tileSize);
        Point[] invTxt = new Point[2];
        int x ,y;
        int bigSpace = 40;
        y = startline;
        x = width/2 - tileSize/2;
        slots.add(new ItemSlot(new Point(x, y), 1, ItemSlot.EQUIPPED));
        y += tileSize + space;
        slots.add(new ItemSlot(new Point(x, y), 2, ItemSlot.EQUIPPED));
        slots.add(new ItemSlot(new Point(x - tileSize - space, y), 3, ItemSlot.EQUIPPED));
        slots.add(new ItemSlot(new Point(x + tileSize + space, y), 4, ItemSlot.EQUIPPED));
        y += tileSize + space;
        slots.add(new ItemSlot(new Point(x, y), 5, ItemSlot.EQUIPPED));
        int bx = width/2 - (tileSize*5 + space*4)/2;
        y += tileSize + bigSpace;
        invTxt[0] = new Point(bx, y - 5);
        for(int b = 0; b < 2; b++){
            x = bx;
            for(int f = 0; f < 5; f++){
                slots.add(new ItemSlot(new Point(x, y), f + b*5, ItemSlot.INVENTORY));
                x += tileSize + space;
            }
            y += tileSize + space;
        }
        y += (bigSpace - space);
        invTxt[1] = new Point(bx, y - 5);
        for(int b = 0; b < 2; b++){
            x = bx;
            for(int f = 0; f < 5; f++){
                slots.add(new ItemSlot(new Point(x, y), f + b*5, ItemSlot.FLOOR));
                x += tileSize + space;
            }
            y += tileSize + space;
        }
        return invTxt;
    }
    
    void setSlotItems(){
        Iterator<ItemSlot> itt = slots.iterator();
        for(int x = 1; x < 6; x++)  //тут расчитывается что константы известны, может нужно по другому, но так компактней
            itt.next().setItem(player.getEquippedItem(x));
        for(int x = 0; x < 10; x++)
            itt.next().setItem(player.inventoryGet(x));
        if(player.getItemsFloor() != null)
            for(int x = 0; x < 10; x++)
                itt.next().setItem(player.getItemsFloor().itemGet(x));
        else
            for(int x = 0; x < 10; x++)
                itt.next().setItem(null);
    }
    
    void itemSelected(int number, int slotType){
        try{
            Item item;
            switch(slotType){
                case ItemSlot.EQUIPPED: item = player.getEquippedItem(number); break;
                case ItemSlot.INVENTORY: item = player.inventoryGet(number); break;
                case ItemSlot.FLOOR: item = player.getItemsFloor().itemGet(number); break;
                default: return;    //тут можно выбросить исключение, потом сделать
            }
            if(dialogItem(item) != 1)
                return;
            switch(item.getUseType()){
                case Item.PUTABLE: player.inventoryPut(player.putOn((BodyArmor)item)); break; //если я сделаю как хотел passTurn в player то тут может пройти два хода, над обдумать
                case Item.WIELDABLE: player.inventoryPut(player.wieldHand(item, handDialog())); break; //тут можно сделать диалог с кансел и выбросить кансел эксцептион для отмены
                case Item.USABLE: player.use((Usable)item); break;
            }
            boolean doTake = true;
            if(item.getUseType() == Item.USABLE)
                if(!((Usable)item).isUsed())
                    doTake = false;
            if(doTake)
                switch(slotType){   //пока экипированные предметы не трогаем, но может будет надо
                    case ItemSlot.INVENTORY:player.inventoryTake(number); break;
                    case ItemSlot.FLOOR: player.getItemsFloor().itemTake(number); break;
                }
        }catch(PlayerException pex){
            JOptionPane.showMessageDialog(this, pex.getDialogMessage(), "Ошибка", JOptionPane.ERROR_MESSAGE);
        }catch(Exception ex){   //потом тут надо поправить, чтоб выводилось человеческое сообщение... хотя надо ли оно вообще
            JOptionPane.showMessageDialog(this, ex.getMessage(), "Ошибка", JOptionPane.ERROR_MESSAGE);
        }
    }
    void itemRClicked(int number, int slotType){
        try{
            switch(slotType){
                case ItemSlot.EQUIPPED: player.inventoryPut(player.takeOff(number)); dungeon.passTurn(); break;
                case ItemSlot.FLOOR: player.inventoryPut(player.getItemsFloor().itemTake(number)); dungeon.passTurn(); break;
                case ItemSlot.INVENTORY: player.dropToFloor(player.inventoryTake(number)); dungeon.passTurn(); break;
            }
        }catch(Exception ex){
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }
    int dialogItem(Item item){
        String option = "";
        String message = "";
        switch(item.getType()){
            case Item.WEAPON:{
                Weapon wep = (Weapon)item;
                option = "Взять в руку";
                String type = "";
                switch(wep.getWtype()){
                    case Weapon.SWORD: type = "меч"; break;
                    case Weapon.MACE: type = "булава"; break;
                    case Weapon.STAFF: type = "посох"; break;
                }
                message = item.getName() + "\nАтака: " + wep.getDamage() + "\nТип: " + type + "\n" + item.getDescr();
                break;
            }
            case Item.ARMOR:{
                Armor arm = (Armor)item;
                option = "Надеть";
                String type = "";
                switch(arm.getArmType()){
                    case Player.HEAD: type = "шлем"; break;
                    case Player.BODY: type = "нагрудник"; break;
                    case Player.LEGS: type = "поножи"; break;
                }
                message = item.getName() + "\nЗащита: " + arm.getDefence() + "\nТип: " + type + "\n" + item.getDescr();
                break;
            }
            case Item.POTION:{
                Potion pot = (Potion)item;
                option = "Использовать";
                String type = "";
                message = item.getName() + "\nНу тут как бы пока что нечего написать";
                break;
            }
        }
        String title = item.getName();
        String[] vars = {"Ок", option};
        ImageIcon ic = new ImageIcon(item.getImg());
        return JOptionPane.showOptionDialog(this, message, title, JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, ic, vars, "Ок");
    }
    int handDialog(){
        String[] options = {"В правую", "В левую"};
        switch(JOptionPane.showOptionDialog(this, "В какую руку взять предмет",
                "Выбор руки", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,
                null, options, player)){
            case 0: return Player.RIGHT_HAND;
            case 1: return Player.LEFT_HAND;
            default: return Player.RIGHT_HAND;  //ну точно нужно исключение
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