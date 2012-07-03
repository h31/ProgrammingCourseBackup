package Creatures;

/**
 * @author Andrew
 */
public abstract class PlayerException extends Exception{
    abstract public String getDialogMessage();
}

class InventoryFullException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Инвентарь полон";
    }
}

class InvalidArmorTypeException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Неверный тип брони";
    }
}

class UnequipabbleItemException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Этот предмет нельзя надеть";
    }
}

class UnusableItemException extends PlayerException{
    @Override
    public String getDialogMessage(){
        return "Этот предмет нельзя использовать";
    }
}