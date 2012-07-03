package dungeonlooter;

import Creatures.Bestiary;
import GUI.MainFrame;
import Items.ItemBase;

public class DungeonLooter{

    public static void main(String[] args){
        Bestiary.setBestiaryDefault();
        ItemBase.setBaseDefault();
        MainFrame mf = new MainFrame("Dungeon Looter");
    }
}