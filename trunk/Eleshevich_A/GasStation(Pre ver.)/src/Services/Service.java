package Services;

import Sums.Sum;

/**
 * @author Andrew
 */
public abstract class Service {
    public abstract Sum getCost();
    public abstract String getName();
    @Override
    public String toString(){
        return getName() + " стоимость: " + getCost();
    }
}