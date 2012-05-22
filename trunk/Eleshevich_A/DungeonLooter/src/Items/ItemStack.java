package Items;

import Creatures.InventoryFullException;
import Dungeon.Position;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.LinkedList;
import java.util.List;

/**
 *
 * @author Andrew
 */
public class ItemStack {
    Position pos;
    LinkedList<Item> items;
    static Image imgBag;
    
    public ItemStack(Position pos){
        this.pos = pos;
        items = new LinkedList<Item>();
        imgBag = Toolkit.getDefaultToolkit().createImage("Data/Bag.gif");
    }
    
    public Image getImg(){
        if(items.size() == 1)
            return items.getFirst().getImg();
        else
            return imgBag;
    }
    public Position getPos(){
        return pos;
    }
    
    public Item itemGet(int num){
        try{
            return items.get(num);
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    public void itemPut(Item item){
        items.add(item);
    }
    
    public Item itemTake(int num){
        try{
            return items.remove(num);
        }catch(IndexOutOfBoundsException ioex){
            return null;
        }
    }
    public boolean isEmpty(){
        return items.isEmpty();
    }
}
