package Dungeon;

import java.util.LinkedList;

/**
 * @author Andrew
 */
public class Percenter{
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
    
    public int[] getMultiChance(int num){
        if(num > ratios.length)
            num = ratios.length;
        int[] res = new int[num];
        LinkedList<Pair> pairs = new LinkedList<Pair>();
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

class Pair{
    int ratio;
    int num;
    
    
    Pair(int ratio, int num){
        this.ratio = ratio;
        this.num = num;
    }
}