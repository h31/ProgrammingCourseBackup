package GUI;

import Constants.SlotType;
import Items.Item;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.Point;

/**
 *
 * @author Andrew
 */
public class ItemSlot{
    Point pos;
    int number;
    SlotType type;
    Item item;
    
    static int size;
    static void setSize(int newSize){
        size = newSize;
    }
    
    ItemSlot(Point pos, int num, SlotType type){
        this.pos = pos;
        number = num;
        this.type = type;
    }
    void setItem(Item item){
        this.item = item;
    }
    
    Point getPos(){ return pos; }
    int getNumber(){ return number; }
    SlotType getType(){ return type; }
    boolean clicked(Point p){
        return p.x > pos.x && p.x < pos.x + size && p.y > pos.y && p.y < pos.y + size;
    }
    boolean isEmpty(){
        return item == null;
    }
    void drawSlot(Graphics g, Container cont){
        g.drawRect(pos.x, pos.y, size, size);
        if(item != null)
            g.drawImage(item.getImg(), pos.x, pos.y, size, size, cont);
    }
}