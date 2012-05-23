package GUI;

import Constants.SlotType;
import Creatures.Player;
import Creatures.PlayerException;
import Constants.PlayerSlot;
import Constants.UseType;
import Dungeon.Dungeon;
import Items.*;
import dungeonlooter.InvalidConstantException;
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
        invTxt = new Point[2];
        this.dungeon = dungeon;
        player = dungeon.getPlayer();
        int space = 10;
        int tileSize = 36;  //задавать автоматически и придумать другое название
        int by = 140;
        setSlots(294, 710, 140, 36, 10);
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
    
    void setSlots(int width, int height, int startline, int tileSize, int space){  //space можно и не задавать в арг
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
        for(int x = 1; x < 6; x++)  //тут расчитывается что константы известны, может нужно по другому, но так компактней
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
    
    void itemSelected(int number, SlotType slotType){   //может разбить на 3 функции?
        try{
            Item item;
            switch(slotType){
                case EQUIPPED: item = player.getEquippedItem(PlayerSlot.getSlot(number)); break;
                case INVENTORY: item = player.inventoryGet(number); break;
                case FLOOR: item = player.getItemsFloor().itemGet(number); break;
                default: return;    //тут можно выбросить исключение, потом сделать
            }
            if(dialogItem(item, slotType) != 1)
                return;
            switch(slotType){
                case EQUIPPED: player.inventoryPut(player.takeOff(PlayerSlot.getSlot(number))); return;
                case INVENTORY: player.inventoryTake(number); break;
                case FLOOR: player.getItemsFloor().itemTake(number); break;
            }
            switch(item.getUseType()){
                case PUTABLE: player.inventoryPut(player.putOn((BodyArmor)item)); break; //если я сделаю как хотел passTurn в player то тут может пройти два хода, над обдумать
                case WIELDABLE: player.inventoryPut(player.wieldHand(item, handDialog())); break; //тут можно сделать диалог с кансел и выбросить кансел эксцептион для отмены
                case USABLE: player.use((Usable)item); break;
            }
            boolean putback = false;
            if(item.getUseType().equals(UseType.USABLE))
                if(!((Usable)item).isUsed())
                    putback = true;
            if(putback) //выглядит глупо, но причин возврата может быть несколько... в теории
                putback(item, number, slotType);
            dungeon.passTurn();
        }catch(PlayerException pex){    //где то как то нужно вернуть предмет, надо подумать
            JOptionPane.showMessageDialog(this, pex.getDialogMessage(), "Ошибка", JOptionPane.ERROR_MESSAGE);
        }catch(Exception ex){   //потом тут надо поправить, чтоб выводилось человеческое сообщение... хотя надо ли оно вообще
            System.err.println(ex.getMessage());
        }
    }
    boolean putback(Item item, int number, SlotType stype){
        try{
            switch(stype){
                case EQUIPPED:{
                    switch(item.getUseType()){  //тут проверку, не надето ли уже что то
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
                case EQUIPPED: player.inventoryPut(player.takeOff(PlayerSlot.getSlot(number))); dungeon.passTurn(); break;
                case FLOOR: player.inventoryPut(player.getItemsFloor().itemTake(number)); dungeon.passTurn(); break;
                case INVENTORY: player.dropToFloor(player.inventoryTake(number)); dungeon.passTurn(); break;
            }
        }catch(Exception ex){
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }
    int dialogItem(Item item, SlotType stype){
        String option = "";
        StringBuilder message = new StringBuilder(item.getName());
        String title = "";
        switch(item.getType()){
            case ARMOR:{
                title = "Броня";
                Armor arm = (Armor)item;
                message.append("\nЗащита: ").append(arm.getDefence());
                String aclass = "";
                switch(arm.getArmClass()){
                    case HEAVY: aclass = "Тяжёлый"; break;
                    case LIGHT: aclass = "Лёгкий"; break;
                }
                message.append("\nКласс брони: ").append(aclass);
                switch(arm.getArmType()){
                    case SHIELD:
                        message.append("\nТип: щит\nБлок: ").append(((Shield)arm).getBlock());
                    case BODY_ARMOR:{
                        String type = "";
                        switch(((BodyArmor)arm).getSlotType()){
                            case HEAD: type = "Шлем"; break;
                            case BODY: type = "Нагрудник"; break;
                            case LEGS: type = "Поножи"; break;
                        }
                        message.append("\nТип: ").append(type);
                    }
                }
                break;
            }
            case WEAPON:{
                title = "Оружие";
                Weapon wep = (Weapon)item;
                String wtype = "";
                switch(wep.getWtype()){
                    case SWORD: wtype = "Меч"; break;
                    case MACE: wtype = "Булава"; break;
                    case STAFF: wtype = "Посох"; break;
                }
                message.append("\nТип: ").append(wtype).append("\nАтака: ").append(wep.getDamage());
                break;
            }
            case MISC:{
                title = "Разное";
            }    
        }
        message.append("\n").append(item.getDescr());
        switch(item.getUseType()){
            case USABLE: option = "Использовать"; break;
            case PUTABLE:
                if(stype == SlotType.EQUIPPED)
                    option = "Снять";
                else option = "Надеть";
                break;
            case WIELDABLE:
                if(stype == SlotType.EQUIPPED)
                    option = "Убрать из руки";
                else
                    option = "Взять в руку";
                break;  
            case NONE: option = "Тут тоже Ок";
        }
        String[] vars = {"Ок", option};
        ImageIcon ic = new ImageIcon(item.getImg());
        return JOptionPane.showOptionDialog(this, message, title, JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, ic, vars, "Ок");
    }
    PlayerSlot handDialog(){
        String[] options = {"В правую", "В левую"};
        switch(JOptionPane.showOptionDialog(this, "В какую руку взять предмет",
                "Выбор руки", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,
                null, options, player)){
            case 0: return PlayerSlot.RIGHT_HAND;
            case 1: return PlayerSlot.LEFT_HAND;
            default: return PlayerSlot.RIGHT_HAND;  //ну точно нужно исключение
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