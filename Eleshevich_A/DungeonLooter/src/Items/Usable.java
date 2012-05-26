package Items;

import Creatures.Buff;
import Creatures.Effect;

/**
 * @author Andrew
 */
public interface Usable {
    public boolean isUsed();
    public Buff use();
    public Buff getBuff();
}
