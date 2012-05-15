package poker;
import java.util.ArrayList;
import java.util.Collections;

public class Deck {
    private ArrayList<Card> cards;

     Deck()
    {
        cards = new ArrayList<Card>();
        for (int a=0; a<4; a++)      //filling deck
        {
            for (int b=0; b<13; b++)
             {
               cards.add( new Card(a,b) );
             }
        }
        Collections.shuffle(cards);
    }
     
    public void refill()
    {
        cards.removeAll(cards);
        for (int a=0; a<4; a++)      //filling deck
        {
            for (int b=0; b<13; b++)
             {
               cards.add( new Card(a,b) );
             }
        }
        Collections.shuffle(cards);
    }

     public int getTotalCards()      //num cards in deck
    {
        return cards.size();
    }

    public Card getCard()   
    {       
        return cards.remove( cards.size()-1 );
    }
}