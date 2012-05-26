package GUI;

import Constants.MessageType;
import Creatures.Creature;
import Creatures.Player;
import Items.Item;

/**
 * @author Andrew
 */
public interface Messager {
    public void print(String str);
    //public void messageAttack(Creature c1, Creature c2, int damage);
    //public void messagePlayerItem(Player player, Item item, MessageType mtype);
}