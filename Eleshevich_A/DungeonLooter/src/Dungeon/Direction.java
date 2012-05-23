package Dungeon;

import dungeonlooter.InvalidConstantException;

/**
 * @author Andrew
 */
public enum Direction {
    LEFT(1), RIGHT(2), UP(3), DOWN(4);
    int val;
    private Direction(int val){
        this.val = val;
    }
    public int getVal(){
        return val;
    }
    public static Direction getDir(int val) throws InvalidConstantException{
        try{
            return Direction.values()[val - 1];
        }catch(IndexOutOfBoundsException ioex){
            throw new InvalidConstantException("Direction", val);
        }
    }
}