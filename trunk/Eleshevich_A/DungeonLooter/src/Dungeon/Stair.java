package Dungeon;

import Constants.CellStatus;
import Constants.CellType;
import Constants.StairType;
import java.awt.Image;
import java.awt.Toolkit;

/**
 * @author Andrew
 */
public class Stair extends Cell{
    StairType stype;
    Position tpos;
    
    static Image stairUp = Toolkit.getDefaultToolkit().createImage("Data/stairUp.gif");
    static Image stairDown = Toolkit.getDefaultToolkit().createImage("Data/stairDown.gif");
    static Image stairUpdark = Toolkit.getDefaultToolkit().createImage("Data/stairUpdark.gif");
    static Image stairDowndark = Toolkit.getDefaultToolkit().createImage("Data/stairDowndark.gif");
    
    Stair(StairType stype, Position targetPos){
        super(CellType.STAIR);
        this.stype = stype;
        tpos = targetPos;
    }
    Stair(StairType stype){
        super(CellType.STAIR);
        this.stype = stype;
    }
    
    void setTarget(Position pos){
        tpos = pos;
    }
    public Position getTarget(){
        return tpos;
    }
    public StairType getSType(){
        return stype;
    }
    void changeSType(StairType stype){
        this.stype = stype;
    }
    @Override
    public Image getImg(){
        if(stype.equals(StairType.STAIR_DOWN)){
            if(status.equals(CellStatus.VISIBLE))
                return stairDown;
            else
                return stairDowndark;
        }else{
            if(status.equals(CellStatus.VISIBLE))
                return stairUp;
            else
                return stairUpdark;
        }
    }
}
