package poker;

import gui.MainFrame;   
import support.CircleArray;
import java.util.Scanner;
import java.util.Random;

public class Table {
    
    private int distribution;
    private int pot;
    private int bigBl;
    private int highBet;
    private CircleArray<Player> tempPlayers; //worked players
    private CircleArray<Player> allPlayers;  //all players + folders
    private CircleArray<Player> reserve;     //alliners
    private Deck deck;
    private MainFrame frame;
    
    public Table(int b)
    {
        highBet = 0;
        pot = 0;
        bigBl = b;
        distribution = 0;
        tempPlayers = new CircleArray();
        allPlayers = new CircleArray();
        reserve = new CircleArray(); 
        deck = new Deck();
        frame = new MainFrame();
    }
         
     public void start()
    {
        createPlayers(5);
        
        do{
        frame.newRaund();
        tempPlayers.addAll(allPlayers);
        allPlayers.removeAll();
        blinds();
        pre_flop(); if(tempPlayers.size()<=1) break;
        flop(); if(tempPlayers.size()<=1) break;
        turn(); if(tempPlayers.size()<=1) break;
        river(); 
        }while(allPlayers.size()<=1);
        for(int i = 0; i<tempPlayers.size(); i++){
        if(tempPlayers.get(i).getStack()<=0){
           tempPlayers.remove(i);}}
        allPlayers.addAll(tempPlayers);
        tempPlayers.removeAll();
        distribution++;
             
    }
    
    private void createPlayers(int qp)
    {           
        for(int i = 0; i<=qp; i++)
        {
            allPlayers.add(new Player(i));
        }
    }
        
    private void blinds()
    {
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).newRaund();
            frame.setStat(tempPlayers.get(dealer()+i), i);
        }
        bet(dealer()+1, bigBl/2);
        bet(dealer()+2, bigBl);
        frame.setPot(pot);
        for(int i = 0; i<tempPlayers.size(); i++)
        {frame.setStack(tempPlayers.get(i));}
    }
       
    private void pre_flop()
    {        
        for(int i = 0; i<tempPlayers.size(); i++)      //given cards to tempPlayers
        {
            tempPlayers.get(i).giveCard(deck.getCard());
            tempPlayers.get(i).giveCard(deck.getCard());
        }                                          
        frame.addPlayerCard(tempPlayers.get(0).getFCard(), tempPlayers.get(0).getSCard());
        tempPlayers.setInd(dealer()+3); 
        while(true)
        {
                playersTurn_G();
                if(checkAl() || ((tempPlayers.size()+reserve.size())<=1))
                {break;}       
        }
        
        if((tempPlayers.size()+reserve.size())==1)
        {
            if(tempPlayers.size()!=0){
            win(tempPlayers.getFst());}
            else{win(reserve.getFst());}
            return;
        }
        
    }
   
    private void flop()
    {
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).newRaund();
        }
        
        Card card1 = new Card(deck.getCard());
        Card card2 = new Card(deck.getCard());
        Card card3 = new Card(deck.getCard());
        frame.addFlopCards(card1, card2, card3);
        
        for(int i = 0; i<reserve.size(); i++)
        {
            reserve.get(i).giveCard(card1);
            reserve.get(i).giveCard(card2);
            reserve.get(i).giveCard(card3);
        }
        
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).giveCard(card1);
            tempPlayers.get(i).giveCard(card2);
            tempPlayers.get(i).giveCard(card3);
        }
        
        tempPlayers.setInd(dealer()+1);                      
        while(true)
        {
                playersTurn_G();
                if(checkAl() || ((tempPlayers.size()+reserve.size())<=1))
                {break;}       
        }
        
        if((tempPlayers.size()+reserve.size())==1)
        {
            if(tempPlayers.size()!=0){
            win(tempPlayers.getFst());}
            else{win(reserve.getFst());}
            return;
        }
        
    }        
            
    private void turn()
    {
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).newRaund();
        }
        
        Card card4 = new Card(deck.getCard());
        frame.addTurnCard(card4);
        
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).giveCard(card4);
        }
        
        for(int i = 0; i<reserve.size(); i++)
        {
            reserve.get(i).giveCard(card4);
        }
        
        tempPlayers.setInd(dealer()+1);                      
        while(true)
        {
                playersTurn_G();
                if(checkAl() || ((tempPlayers.size()+reserve.size())<=1))
                {break;}       
        }
        
        if((tempPlayers.size()+reserve.size())==1)
        {
            if(tempPlayers.size()!=0){
            win(tempPlayers.getFst());}
            else{win(reserve.getFst());}
            return;
        }
    }
    private void river()
    {
        for(int i = 0; i<tempPlayers.size(); i++) //reset player's status
        {
            tempPlayers.get(i).newRaund();
        }
        
        Card card5 = new Card(deck.getCard());
        frame.addRiverCard(card5);
        
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).giveCard(card5);
        }
        
        for(int i = 0; i<reserve.size(); i++)
        {
            reserve.get(i).giveCard(card5);
        }
        
        tempPlayers.setInd(dealer()+1);                      
        while(true)
        {
                playersTurn_G();
                if(checkAl() || ((tempPlayers.size()+reserve.size())<=1))
                {break;}       
        }
        
        if((tempPlayers.size()+reserve.size())==1)
        {
            if(tempPlayers.size()!=0){
            win(tempPlayers.getFst());}
            else{win(reserve.getFst());}
            return;
        }
        else
        {
            findWiner();
            return;
        }
    }
      
    private void findWiner()
    {        
        tempPlayers.addAll(reserve);
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).buildHand();
        }
        
       for(int i = 0; i<tempPlayers.size(); i++){
           for(int k = i+1; k<tempPlayers.size(); k++){
               tempPlayers.get(i).changePoints(tempPlayers.get(i).getHand().compareTo(tempPlayers.get(k).getHand()));
           }
       }
       
       int winers = 0;
       int p=tempPlayers.size()-1;
       while(p>0){
           for(int i = 0; i<tempPlayers.size(); i++)
           {
               if(tempPlayers.get(i).getPoints()==p)
               {
                   winers++;
               }  
           }
           if(winers>=1) break; 
           p--;}
       
          for(int i = 0; i<tempPlayers.size(); i++)
              {
                  if(tempPlayers.get(i).getPoints()==p){
                      tempPlayers.get(i).giveChips(pot/winers);
                  }
                  frame.setStack(tempPlayers.get(i));
              }
              pot=0;
              frame.setPot(pot);
              return;
    } 
    
    private void win(Player pl)
    {
        pl.giveChips(pot);
        pot = 0;
        for(int i = 0; i<tempPlayers.size(); i++)
        {frame.setStack(tempPlayers.get(i));}
        frame.setPot(pot);
        for(int i = 0; i<reserve.size(); i++)
        {frame.setStack(reserve.get(i));}
        frame.setPot(pot);
    }
    
    private int dealer()
    {
        return (distribution%tempPlayers.size());
    }
    
    private boolean checkAl()
    {
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            if(tempPlayers.get(i).getTotalBet()!=highBet)
            {
                return false;
            }
        }
        return true;           
    }
    
    public int action_r()
    {
        int r = frame.action();
        return r;
    }
    
    public int bet_r()
    {
        return frame._bet();
    }
    
    public int action_b(int i)//////////////////////////////bot
    {
      //double ptch = pt/(hb - totalBet);  
        Random gen = new Random();
        int res = gen.nextInt(5);
        res++;
      return 3;
    }
        
    public int bet_b(int i)///////////////////////////////////////bot
    {
        return bigBl;
    }
    
    private void playersTurn_G()
    {                  
            int i = tempPlayers.getNextx();
            int a;
            int b;
            boolean f;
            do{
            if(tempPlayers.get(i).getId() == 0){
                if(tempPlayers.get(i).getTotalBet()==highBet){frame.estSetBut(2);}
                a = action_r();}
            else{
            a = action_b(i);}
                    switch (a)
                    {
                        case 1:{ //fold
                            f = fold(i); break;
                            }
                        case 2:{ //check
                            f = check(i); break;
                            }
                            
                        case 3:{ //call
                            f = call(i); break;
                            }
                            
                        case 4:{ //rise
                            if(i==0){
                                b = bet_r();}
                            else
                            {
                                b = bet_b(i);
                            }
                            f = rise(i, b); break;
                            }
                            
                        case 5:{ //bet
                            if(i==0){
                                b = bet_r();}
                            else
                            {
                                b = bet_b(i);
                            }
                            f = bet(i, b); break;
                            }
                            
                        case 6:{ //allin   
                            f = allin(i); break;
                            }
                        default:{f = false;}    
                    }
                }while(!f);            
    }
        
    private void playersTurn()
    {
        Scanner in = new Scanner(System.in);
        int i;
                while(true){
                    i = tempPlayers.getInd();
                    System.out.println("------------Player" +tempPlayers.get(i).getId() +"------------");
                    switch (action_r())
                    {
                        case 1: //fold
                            if(fold(i))
                            {break;}
                        case 2: //check
                            if(check(i))
                            {break;}
                            System.out.println("You can not to check");
                        case 3: //call
                            if(call(i))
                            {break;}
                            System.out.println("You can not to call");
                        case 4: //rise
                            System.out.println("Your bet: ");
                            if(rise(i, in.nextInt()))
                            {break;}
                            System.out.println("You can not to rise");
                        case 5: //bet
                            System.out.println("Your bet: ");
                            if(bet(i, in.nextInt()))
                            {break;}
                            System.out.println("You can not to bet");
                        case 6: //allin   
                            if(allin(i))
                            {break;}
                    }
                }            
    }
    
    private boolean fold(int i)    //1
    {
        frame.removeBot(tempPlayers.get(i).getId());
        frame.botAction(tempPlayers.get(i), 1);
        allPlayers.add(tempPlayers.remove(i));
        return true;
    }
    private boolean check(int i)    //2
    {
        if(highBet == tempPlayers.get(i).getTotalBet())
        {frame.botAction(tempPlayers.get(i), 2);
            return true;}
        else
        {return false;}
    }
    private boolean call(int i)  //3
    {
        int toCall = (highBet - tempPlayers.get(i).getTotalBet());
        if(tempPlayers.get(i).getStack()>toCall){
        pot += toCall;
        tempPlayers.get(i).takeChips(toCall);
        frame.setStack(tempPlayers.get(i));
        frame.setPot(pot);
        frame.botAction(tempPlayers.get(i), 3);
        return true;}
        else
        {return false;}
    }
    private boolean rise(int i, int b)        //4
    {
        if(tempPlayers.get(i).getStack()>((highBet - tempPlayers.get(i).getTotalBet())+b))
        {call(i);
         bet(i, b);
         frame.botAction(tempPlayers.get(i), 4);
        return true;}
        else
        {return false;}
    }
    private boolean bet(int i, int b)        //5
    {  
       if(tempPlayers.get(i).getStack()>b){ 
       if(b>highBet) {highBet = b;}
       pot = pot + b;
       tempPlayers.get(i).takeChips(b);
       frame.setStack(tempPlayers.get(i));
       frame.setPot(pot); 
       frame.botAction(tempPlayers.get(i), 5);
        return true;}
       else
       {return false;}
       
    }
    private boolean allin(int i)         //6
    {
        if(tempPlayers.get(i).getStack()!=0){ 
           if(tempPlayers.get(i).getStack()>highBet) {highBet = tempPlayers.get(i).getStack();}
           pot = pot + tempPlayers.get(i).getStack();
           tempPlayers.get(i).takeChips(tempPlayers.get(i).getStack());
           
           frame.setStack(tempPlayers.get(i));
           frame.setPot(pot); 
           frame.botAction(tempPlayers.get(i), 5);
           frame.botAction(tempPlayers.get(i), 6);
           reserve.add(tempPlayers.remove(i));
           return true;
        }
        return false;
    }
}