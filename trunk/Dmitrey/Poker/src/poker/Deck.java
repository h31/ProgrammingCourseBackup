package poker;

import java.util.ArrayList;
import java.util.Random;

public class Deck {
    
    ArrayList<Map> deck;
    
    public void filling()
    {
        Rank i = Rank.tw;
        Suit j = Suit.CLUB;
        do{
            do{
               deck.add(new Map(i, j));
               j = j.next();
              }while(j.equals(Suit.CLUB));
          i = i.next();
        }while(i.equals(Rank.tw));
    }
          
    
    public Map getMap()
    {
        if(deck.isEmpty()){ 
            System.out.println("Deck is empty!");
            return null;}
        Random g = new Random();
        int q = g.nextInt(deck.size());
        Map p = new Map(deck.get(q));
        deck.remove(q);
        return p;
    }
}
