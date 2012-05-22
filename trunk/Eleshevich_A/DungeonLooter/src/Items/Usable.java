package Items;

import Creatures.Effects.Effect;

/**
 * @author Andrew
 */
public interface Usable {
    public boolean isUsed();
    public Effect use();
    public Effect getEffect();
}
