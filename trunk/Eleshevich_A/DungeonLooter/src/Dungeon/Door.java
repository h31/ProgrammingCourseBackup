package Dungeon;

import Constants.CellStatus;
import Constants.CellType;
import java.awt.Component;
import java.awt.Image;
import java.awt.Toolkit;

/**
 * @author Andrew
 */
public class Door extends Cell{
    int weight;
    boolean closed;
    
    static Image doorOpen = Toolkit.getDefaultToolkit().createImage("Data/doorOpen.gif");
    static Image doorClose = Toolkit.getDefaultToolkit().createImage("Data/doorClose.gif");
    static Image doorOpendark = Toolkit.getDefaultToolkit().createImage("Data/doorOpendark.gif");
    static Image doorClosedark = Toolkit.getDefaultToolkit().createImage("Data/doorClosedark.gif");
    
    static void prepareImages(Component comp){
        
    }
    
    Door(int weight){
        super(CellType.DOOR);
        this.weight = weight;
        closed = true;
    }
    
    public boolean isClosed(){
        return closed;
    }
    public boolean tryOpen(){
        if(new Percenter(3, weight).getChance() == 1){
            closed = false;
            solid = false;
            return true;
        }else
            return false;
    }
    public boolean tryClose(){
        if(new Percenter(4, weight).getChance() == 1){
            closed = true;
            solid = false;
            return true;
        }else
            return false;
    }
    @Override
    public Image getImg(){
        if(closed){
            if(status.equals(CellStatus.VISIBLE))
                return doorClose;
            else
                return doorClosedark;
        }
        else{
            if(status.equals(CellStatus.VISIBLE))
                return doorOpen;
            else
                return doorOpendark;
        }
    }
}
