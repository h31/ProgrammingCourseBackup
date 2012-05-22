package Dungeon;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedList;

/**
 * @author Andrew
 */
public class Percenter {
    int[] ratios;
    
    public Percenter(int... ratios){
        this.ratios = ratios;
    }
    
    public int getChance(){
        int sum = 0;
        for(int val: ratios)
            sum += val;
        int res = (int)((Math.pow(10, Integer.toString(sum).length())*Math.random())%(sum))+1;
        int lb = 1;
        int ub = ratios[0] + 1;
        for(int count = 0; count < ratios.length; ){
            if(res >= lb && res < ub)
                return count + 1;
            lb += ratios[count];
            count++;
            if(count < ratios.length)
                ub += ratios[count];
        }
        return 0;
    }
    
//    public int[] getMultiChance(int num){
//        //System.out.println("num: " + num);
//        if(num > ratios.length)
//            num = ratios.length;
//        //System.out.println("num: " + num);
//        int[] nratios = ratios.clone();
//        int res[] = new int[num];
//        int offset = 0;
//        for(int x = 0; x < num; x++){
//            int tres = (new Percenter(nratios)).getChance() - 1;
//            if(tres == 0)
//                offset++;
//            //System.out.println("x: " + x + "; tres: " + tres + ";");
//            int[] tratios = new int[nratios.length - 1];
//            int t = 0;
//            for(int b = 0; b < nratios.length; b++){
//                //System.out.print("b: " + b + "; t: " + t + "; ");
//                if(b != tres){
//                    //System.out.print("nratios[b]: " + nratios[b] + ";");
//                    tratios[t] = nratios[b];
//                    t++;
//                }
//                //System.out.println();
//            }
//            nratios = tratios;
//            tres++;
//            //System.out.println("tres: " + tres);
//            boolean flag = true;
//            while(flag){
//                flag = false;
//                for(int val: res)
//                    if(val == tres){
//                        tres++;
//                        flag = true;
//                    }
//            }
//            //tres += offset;
//            System.out.println("offset: " + offset);
//            //System.out.println("tres: " + tres);
//            res[x] = tres;
//        }
//        return res;
//    }
    
    public int[] getMultiChance(int num){
        if(num > ratios.length)
            num = ratios.length;
        int[] res = new int[num];
        LinkedList<Pair> pairs = new LinkedList<Pair>(); //подумать над выбором, просто нужна индексация, но обращение единожды
        for(int x = 0; x < ratios.length; x++)
            pairs.add(new Pair(ratios[x], x+1));
        for(int x = 0; x < num; x++){
            int[] tratios = new int[pairs.size()];
            int y = 0;
            for(Pair p: pairs){
                tratios[y] = p.ratio;
                y++;
            }
            int indx = (new Percenter(tratios)).getChance() - 1;
            res[x] = pairs.get(indx).num;
            pairs.remove(indx);
        }
        return res;
    }
}

class PercentException extends Exception{
    
}

class Pair{
    int ratio;
    int num;
    
    
    Pair(int ratio, int num){
        this.ratio = ratio;
        this.num = num;
    }
}

//    int[] chances;
//    public Percenter(int... chances) throws PercentException{
//        int val = 0;
//        for(int x: chances){
//            if(x <= 0)
//                throw new PercentException();
//            val += x;
//        }
//        if(val != 100)
//            throw new PercentException();
//        this.chances = chances;
//    }
//    public int getChance(){
//        int val = (int)(1000*Math.random())%99 + 1;
//        int count = 0;
//        int lb = 1;
//        int ub = chances[0];
//        for(int x: chances){
//            if(val >= lb && val < ub)
//                return count + 1;
//            lb += chances[count];
//            count++;
//            if(count < chances.length)
//                ub += chances[count];
//        }
//        return 0;
//    }