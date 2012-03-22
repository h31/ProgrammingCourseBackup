package poker;

import java.util.ArrayList;

public class Combination {
    
    private String name;
    private int power;
    
    public void setName(ArrayList<Map> m)
    {
        
    }
    
     private boolean high_card(ArrayList<Map> m)
    {
        for(int i = 0; i<m.size(); i++)
        {
            power = m.get(i).getRank();
        }
    }
     
     private boolean one_pair (ArrayList<Map> m)
     {
         
        for(int i = 0; i<size-1; i++){
            for(int j = i+1; j<size; j++){
            if()
            }
        }
     }
     private boolean two_pair (ArrayList<Map> m)
     private boolean straight (ArrayList<Map> m)
     private boolean flush (ArrayList<Map> m)
     private boolean full_House (ArrayList<Map> m)
     private boolean four_of_a_kind (ArrayList<Map> m)
     private boolean straight_flush (ArrayList<Map> m)
     private boolean royal_flush (ArrayList<Map> m)
    
    public int getPower()
    {return power;}
             
    @Override
    public boolean equals(Combination c)
    {
         return power == c.getPower();
    }
    
    public boolean older(Combination c)
    {
        return power > c.getPower();
    }
    
}
