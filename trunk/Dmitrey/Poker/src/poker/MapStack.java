package poker;

import java.util.ArrayList;

public class MapStack {
    
    
    private ArrayList<Map> maps = new ArrayList();
    private Combination com = new Combination();
    private int size;
    
    public void addMap(Map m)
    {
        if(size<6){
        maps.add(m);
        size++;
        if(!maps.isEmpty()){
        com.setName(maps);}}
        
            
        
    }
    
    public void setCombination()
    {
        if()
    }
    
   
}

