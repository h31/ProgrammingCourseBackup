package Dungeon;

import Constants.CellType;
import Constants.CellStatus;
import java.awt.Image;
import java.awt.Toolkit;

/**
 * @author Andrew
 */
public class Cell{
    CellType type;
    CellStatus status;
    boolean solid;
    
    static Image floorImg = Toolkit.getDefaultToolkit().createImage("Data/floor.gif");
    static Image wallImg = Toolkit.getDefaultToolkit().createImage("Data/wall.gif");
    static Image dfloorImg = Toolkit.getDefaultToolkit().createImage("Data/floordark.gif");
    static Image dwallImg = Toolkit.getDefaultToolkit().createImage("Data/walldark.gif");
    
    Cell(CellType type){
        this.type = type;
        switch(type){
            case WALL: solid = true; break;
            case FLOOR: solid = false; break;
            case DOOR: solid = true; break;
            case STAIR: solid = false; break;
        }
        status = CellStatus.UNDISCOVERED;
    }
    public CellType getType(){
        return type;
    }
    public CellStatus getStatus(){
        return status;
    }
    public void setStatus(CellStatus newStatus){
        status = newStatus; //нужно предусмотреть проверку на корректность статуса и выброс исключения
    }
    public boolean isSolid(){
        return solid;
    }
    public Image getImg(){
        switch(type){
            case WALL: if(status.equals(CellStatus.VISIBLE)) return wallImg; else return dwallImg;
            case FLOOR: if(status.equals(CellStatus.VISIBLE)) return floorImg; else return dfloorImg;
            default: return null;   //надо будет потом тут всё починить, а пока сойдёт, может пересмотреть принцип Cell   
        }
    }
}