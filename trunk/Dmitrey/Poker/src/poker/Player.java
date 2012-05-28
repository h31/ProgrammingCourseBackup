package poker;

import java.util.Scanner;

public class Player implements Comparable{
    
    private int size;
    private int stack;
    private Card[] cards;
    private int id;
    private Hand hand;
    private int totalBet;
    private int points;
        
    public Player(int id)
    {
        this.id = id;
        points = 0;
        stack = 1500;
        totalBet = 0;
        hand = null;
        cards = new Card[7];
        size = 0;
    }
    
    public void resetCards()
    {
        size = 0;
    }
    
    public Player olderHand(Player that)            //Player with older hand
    {
        if(this.hand.equals(this.hand.compareTo(that.getHand())))
        {
            return this;
        }
        return that;       
    }
    
    public void changePoints(int i)
    {
        points+=i;
    }
    
    public int getPoints()
    {
        return points;
    }
    
    public Hand getHand()
    {
        return hand;
    }
       
    public int action_r_c()
    {
        Scanner con = new Scanner(System.in);
        System.out.println("intput action: ");
        System.out.println("1-fold");
        System.out.println("2-check");
        System.out.println("3-call");
        System.out.println("4-rise");
        System.out.println("5-bet");
        System.out.println("6-allin");
        return con.nextInt();
    }
          
    public void newRaund()
    {
        totalBet = 0;
    }
                        
    public int getStack()
    {return stack;}
        
    public int getId()
    {return id;}
    
    public void giveChips(int w)
    {
        stack += w;
    }
    public void takeChips(int w)
    {
        totalBet += w;
        stack -= w;
    }
    
    public int getTotalBet()
    {
        return totalBet;
    }

    public void buildHand()
    {
        if(size == 7)
        hand = new Hand(cards);
        else
        {
            System.out.println("incorrect num of cards!");
        }
    }
    
    public Card getFCard()
    {
      return cards[0];
    }
    
    public Card getSCard()
    {
      return cards[1];
    }

    public void giveCard(Card card)
    {
        cards[size] = card;
        size++;
    }

    @Override
    public int compareTo(Object o) {
        
        Player pl = (Player) o;
        
        if(pl.id>id) return -1;
        else if(pl.id<id) return 1;
        else return 0;
    }
    
    
}
