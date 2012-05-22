package Creatures;

/**
 *
 * @author Andrew
 */
public class InventoryFullException extends PlayerException{    //надо поместить в файл Player
    @Override
    public String getDialogMessage(){
        return "Инвентарь полон";
    }
}
