/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package MainPack;

/**
 *
 * @author Andrew
 */
public class NotFoundException extends Exception{
    @Override
    public String getMessage(){
        return "Запись не была найдена";
    }
}
