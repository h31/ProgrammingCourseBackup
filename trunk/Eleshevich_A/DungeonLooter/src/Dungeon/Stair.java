package Dungeon;

import Constants.StairType;
import Constants.CellType;

/**
 * @author Andrew
 */
public class Stair extends Cell{
    StairType stype;
    Position tpos;
    
    Stair(StairType stype, Position targetPos){
        super(CellType.STAIR);
        this.stype = stype;
        tpos = targetPos;
    }
}
