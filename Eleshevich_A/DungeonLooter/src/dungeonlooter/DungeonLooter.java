package dungeonlooter;

import Creatures.Bestiary;
import Dungeon.Percenter;
import GUI.MainFrame;
import Items.ItemBase;

public class DungeonLooter {

    public static void main(String[] args){
//        try{
//            int val1 = 0;
//            int val2 = 0;
//            int val3 = 0;
//            Percenter perc = new Percenter(40, 60, 25);
//            for(int x = 0; x<10000; x++){
//                switch(perc.getChance()){
//                    case 1: val1++; break;
//                    case 2: val2++; break;
//                    case 3: val3++; break;
//                }
//            }
//            System.out.println("val1: " + val1 + " val2: " + val2 + " val3: " + val3);
//            int v123 = 0;
//            int v132 = 0;
//            int v231 = 0;
//            int v213 = 0;
//            int v321 = 0;
//            int v312 = 0;
//            for(int x = 0; x < 10000; x++){
//                int[] res = perc.getMultiChance(3);
//                if(res[0] == 1 && res[1] == 2 && res[2] == 3)
//                    v123++;
//                else if(res[0] == 1 && res[1] == 3 && res[2] == 2)
//                    v132++;
//                else if(res[0] == 2 && res[1] == 3 && res[2] == 1)
//                    v231++;
//                else if(res[0] == 2 && res[1] == 1 && res[2] == 3)
//                    v213++;
//                else if(res[0] == 3 && res[1] == 2 && res[2] == 1)
//                    v321++;
//                else if(res[0] == 3 && res[1] == 1 && res[2] == 2)
//                    v312++;
//            }
//            System.out.println("v123: " + v123);
//            System.out.println("v132: " + v132);
//            System.out.println("v231: " + v231);
//            System.out.println("v213: " + v213);
//            System.out.println("v321: " + v321);
//            System.out.println("v312: " + v312);
//        }catch(Exception ex){
//            System.out.println(ex.toString());
//        }
        Bestiary.setBestiaryDefault();
        ItemBase.setBaseDefault();
        new MainFrame("Dungeon Looter");
    }
}
