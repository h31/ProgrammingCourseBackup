/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dungeonlooter;

/**
 *
 * @author Andrew
 */
public class InvalidConstantException extends Exception{    //оно нужно всем константам так что пусть побудет здесь
    String Enum;
    int val;
    public InvalidConstantException(String Enum, int val){
      this.Enum = Enum;
      this.val = val;
    }
    @Override
    public String getMessage(){
        return "Enum " + Enum + " don't have constant with value " + val;
    }
}
