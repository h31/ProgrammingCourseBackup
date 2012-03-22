
package poker;



public class Map {   
   
   private Rank rank;
   private Suit suit;      
   Map(Map m)
   {
       rank = m.getRank();
       suit = m.getSuit();
   }
   
   Map(Rank r, Suit s)
   {
       rank = r;
       suit = s;
   }
   
   public Rank getRank()
   {
       return rank;
   }
    
   public Suit getSuit()
   {
       return suit;
   }
   public boolean equals(Map m)
   {
       if(rank==m.getRank() && suit==m.getSuit()){
           return true;}
       return false;
   }
   
   
}
