package Dungeon;

import Constants.CellStatus;
import Constants.CellType;
import java.awt.Image;
import java.awt.Toolkit;

/**
 * @author Andrew
 */
public abstract class Cell{
    CellType type;
    CellStatus status;
    boolean solid;
    
    protected Cell(CellType type){
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
        status = newStatus;
    }
    public boolean isSolid(){
        return solid;
    }
    public abstract Image getImg();
}
class Wall extends Cell{
    static Image wallImg = Toolkit.getDefaultToolkit().createImage("Data/wall.gif");
    static Image dwallImg = Toolkit.getDefaultToolkit().createImage("Data/walldark.gif");
    
    Wall(){
        super(CellType.WALL);
    }
    @Override
    public Image getImg(){
        if(status.equals(CellStatus.VISIBLE))
            return wallImg;
        else
            return dwallImg;
    }
}
class Floor extends Cell{
    static Image floorImg = Toolkit.getDefaultToolkit().createImage("Data/floor.gif");
    static Image dfloorImg = Toolkit.getDefaultToolkit().createImage("Data/floordark.gif");
    
    Floor(){
        super(CellType.FLOOR);
    }
    @Override
    public Image getImg(){
        if(status.equals(CellStatus.VISIBLE))
            return floorImg;
        else
            return dfloorImg;
    }
}