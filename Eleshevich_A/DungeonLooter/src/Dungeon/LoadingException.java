package Dungeon;

/**
 * @author Andrew
 */
public class LoadingException extends Exception{
    String cause;
    
    LoadingException(String cause){
        this.cause = cause;
    }
    
    @Override
    public String getMessage(){
        return "Не удалось загрузить подземелье - " + cause;
    }
}
