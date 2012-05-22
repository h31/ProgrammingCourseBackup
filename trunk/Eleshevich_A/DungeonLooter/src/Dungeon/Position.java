package Dungeon;

/**
 * @author Andrew
 */
public class Position {
    public int x;
    public int y;
    
    public Position(){
        x = 0;
        y = 0;
    }
    public Position(int x, int y){
        this.x = x;
        this.y = y;
    }
    public Position(Position pos){
        x = pos.x;
        y = pos.y;
    }
    @Override
    public boolean equals(Object obj){
        if(!obj.getClass().equals(this.getClass()))
            return false;
        Position pos = (Position)obj;
        return pos.x == x && pos.y == y;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 73 * hash + this.x;
        hash = 73 * hash + this.y;
        return hash;
    }
}
