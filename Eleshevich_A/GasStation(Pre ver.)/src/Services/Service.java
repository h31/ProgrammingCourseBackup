package Services;

import MainPack.Sum;

/**
 * @author Andrew
 */
public abstract class Service {
    public abstract Sum getCost();
    public abstract String getName();
    @Override
    public String toString(){
        return getName() + " " + getCost();
    }
}