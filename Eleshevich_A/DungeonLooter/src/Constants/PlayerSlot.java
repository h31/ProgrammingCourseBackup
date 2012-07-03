package Constants;

/**
 * @author Andrew
 */
public enum PlayerSlot {
    HEAD, BODY, RIGHT_HAND, LEFT_HAND, LEGS;
    public int getVal(){
        return this.ordinal() + 1;
    }
    public static PlayerSlot getSlot(int val) throws InvalidConstantException{
        try{
            return PlayerSlot.values()[val - 1];
        }catch(IndexOutOfBoundsException ioex){
            throw new InvalidConstantException("PlayerSlot", val);
        }
    }
}
