package Constants;

import dungeonlooter.InvalidConstantException;

/**
 * @author Andrew
 */
public enum PlayerSlot {
    HEAD(1), BODY(2), RIGHT_HAND(3), LEFT_HAND(4), LEGS(5);
    int val;
    private PlayerSlot(int val){
        this.val = val;
    }
    public int getVal(){
        return val;
    }
    public static PlayerSlot getSlot(int val) throws InvalidConstantException{
        try{
            return PlayerSlot.values()[val - 1];
        }catch(IndexOutOfBoundsException ioex){
            throw new InvalidConstantException("PlayerSlot", val);
        }
    }
}
