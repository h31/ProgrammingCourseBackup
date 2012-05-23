package Dungeon;

import Constants.CellType;

/**
 * @author Andrew
 */
public class Door extends Cell{
    int weight;
    boolean closed;
    
    Door(int weight){
        super(CellType.DOOR);
        this.weight = weight;
    }
    
    public boolean tryOpen(){
        if(new Percenter(4, 5).getChance() == 0){
            closed = false;
            solid = false;
            return true;
        }else
            return false;
    }
}
