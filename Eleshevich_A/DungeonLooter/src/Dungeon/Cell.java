package Dungeon;

/**
 * @author Andrew
 */
public class Cell{
    public static final int FLOOR = 1;
    public static final int WALL = 2;
    public static final int VISIBLE = 0;
    public static final int INVISIBLE = 1;
    public static final int UNDISCOVERED = 2;
    int type;
    int status;
    Cell(int type){
        this.type = type;
        status = UNDISCOVERED;
    }
    public int getType(){
        return type;
    }
    public int getStatus(){
        return status;
    }
    public void setStatus(int newStatus){
        status = newStatus; //нужно предусмотреть проверку на корректность статуса и выброс исключения
    }
}