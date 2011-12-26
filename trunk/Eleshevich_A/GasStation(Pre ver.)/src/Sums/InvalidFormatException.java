package Sums;

/**
 * @author Andrew
 */
public class InvalidFormatException extends Exception{
    @Override
    public String getMessage(){
        return "Некорректный формат ввода данных";
    }
}
