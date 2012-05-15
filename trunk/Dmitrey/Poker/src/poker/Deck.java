package poker;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;

public class Deck {
    private ArrayList<Card> cards;

     Deck()
    {
        cards = new ArrayList<Card>();
//        int index_1, index_2;
//        Random generator = new Random();
//        Card temp;

        for (int a=0; a<4; a++)      //filling deck
        {
            for (int b=0; b<13; b++)
             {
               cards.add( new Card(a,b) );
             }
        }

        Collections.shuffle(cards);
        
//        int size = cards.size() -1;
//
//        for (int i=0; i<100; i++) //randoming deck
//        {
//            index_1 = generator.nextInt( size );
//            index_2 = generator.nextInt( size );
//
//            temp = (Card) cards.get( index_2 );
//            cards.set( index_2 , cards.get( index_1 ) );
//            cards.set( index_1, temp );
//        }
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