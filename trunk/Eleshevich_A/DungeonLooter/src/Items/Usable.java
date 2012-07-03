package Items;

import Creatures.Buff;

/**
 * @author Andrew
 */
public interface Usable {
    public boolean isUsed();
    public Buff use();
    public Buff getBuff();
}
