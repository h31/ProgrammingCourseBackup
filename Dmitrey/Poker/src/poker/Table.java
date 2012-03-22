package poker;

import java.util.ArrayList;

public class Table {
    
    private int distribution = -1;
    private int bank = 0;
    private int bigBl;
    private int highBet;
    private ArrayList<Map> maps;
    private ArrayList<Player> players;
    
    Table(int b)
    {
        bigBl = b;
        highBet = b; 
    }
    
    
    public void Blinds()
    {
        players.get((distribution%players.size())+1).bet(bigBl);
        players.get((distribution%players.size())+2).bet(bigBl/2);
        
    }
   
    
    public void addPlayers(int qp)
    {
        for(int i = qp; i != 0; i--)
        {
            players.add(new Player());
        }
    }
        
    public void pre_flop()
    {
        for(int i = 0; i<players.size(); i++)
        {
            players.get(i).newRaund();
        }
        
        for(int i = 0; i<players.size(); i++)
        {
           if(!players.get(i).action(bigBl, highBet))
           {
               players.remove(i);
           }
        }
        for(int i = 0; i<players.size(); i++)
        {
            bank += players.get(i).getTotalBet();
        }
        if(players.size()==1)
        {
            win(players.get(0));
        }
        
    }
            public void flop()
                    public void turn()
                            public void river()
      
    public Player findWiner()
    {
        int index = 0;
        for(int i = 1; i<players.size(); i++){
            if(players.get(index).getCom().getPower() < players.get(i).getCom().getPower()){
                index = i;}
        }
        return players.get(index);            
    }
    
    public void win(Player pl)
    {
        pl.giveWin(bank);
        distribution++;
    }
            
    
    
    public Player Dealer()
    {
        return players.get(distribution%players.size());       
    }
}
