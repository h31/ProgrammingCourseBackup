package poker;

import java.util.Collections;
import gui.MainFrame;   
import java.util.ArrayList;
import support.CircleArray;
import java.util.Scanner;
import java.util.Random;
import javax.swing.plaf.OptionPaneUI;

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
        frame = new MainFrame();
        deck = new Deck();
    }
         
     public void start() throws InterruptedException
    {
        createPlayers(5);
        frame.repaint();
        
        do{
        frame.newRaund();
        blinds(); 
        Thread.currentThread().sleep(1000);
        pre_flop(); 
        Thread.currentThread().sleep(1000);
        if((tempPlayers.size()+reserve.size())>1) flop(); Thread.currentThread().sleep(1000); 
        if((tempPlayers.size()+reserve.size())>1) turn(); Thread.currentThread().sleep(1000);
        if((tempPlayers.size()+reserve.size())>1) river(); Thread.currentThread().sleep(1000);
        
        allPlayers.addAll(tempPlayers);
        allPlayers.addAll(reserve);
        tempPlayers.removeAll();
        reserve.removeAll();
        
        for(int i = 0; i<allPlayers.size(); i++){
            if(allPlayers.get(i).getStack()>0)
            {
                allPlayers.get(i).resetCards();
                tempPlayers.add(allPlayers.get(i));
            } 
        }
        allPlayers.removeAll();
        Collections.sort(tempPlayers.getCA());
        distribution++;
        deck.refill();
        }while(tempPlayers.size()>1 && tempPlayers.getFst().getId()==0);
        frame.dispose();
    }
    
    private void createPlayers(int qp)
    {           
        for(int i = 0; i<=qp; i++)
        {
            tempPlayers.add(new Player(i));
        }
    }
        
    private void blinds()
    {
        for(int i = 0; i<tempPlayers.size(); i++)
        {
            tempPlayers.get(i).newRaund();
            frame.setStat(tempPlayers.get(dealer()+i), i);
        }
        tempPlayers.get(dealer()+1).takeChips(bigBl/2);
        pot += bigBl/2;
        tempPlayers.get(dealer()+2).takeChips(bigBl);
        pot += bigBl;
        highBet = bigBl;
        frame.setPot(pot);
        for(int i = 0; i<tempPlayers.size(); i++)
        {frame.setStack(tempPlayers.get(i));}
    }
       
    private void pre_flop() throws InterruptedException
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
                if(tempPlayers.size()+reserve.size()==1)
                {
                    if(tempPlayers.size()!=0){
                    win(tempPlayers.getFst());}
                    else{win(reserve.getFst());}
                    return;
                }
                if(tempPlayers.size()==0 && reserve.size()>1) break;
                if(checkAl()) break;
        }      
    }
   
    private void flop() throws InterruptedException
    {
        highBet = 0;
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
        if(tempPlayers.size()>1){
        tempPlayers.setInd(dealer()+1);                      
            while(true)
            {
                playersTurn_G();
                if((tempPlayers.size()+reserve.size())==1)
                {
                    if(tempPlayers.size()!=0){
                    win(tempPlayers.getFst());}
                    else{win(reserve.getFst());}
                    return;
                }
                if(tempPlayers.size()==0 && reserve.size()>1) break;
                if(checkAl()) break;       
            }
        }       
    }        
            
    private void turn() throws InterruptedException
    {
        highBet = 0;
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
        if(tempPlayers.size()>1){
        tempPlayers.setInd(dealer()+1);                      
        while(true)
            {
                    playersTurn_G();
                    if((tempPlayers.size()+reserve.size())==1)
                    {
                        if(tempPlayers.size()!=0){
                        win(tempPlayers.getFst());}
                        else{win(reserve.getFst());}
                        return;
                    }
                    if(tempPlayers.size()==0 && reserve.size()>1) break;
                    if(checkAl()) break;       
            }
        }
    }
    private void river() throws InterruptedException
    {
        highBet = 0;
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
        if(tempPlayers.size()>1){
        tempPlayers.setInd(dealer()+1);                      
        while(true)
            {
                playersTurn_G();
                    if((tempPlayers.size()+reserve.size())==1)
                    {
                        if(tempPlayers.size()!=0){
                        win(tempPlayers.getFst());}
                        else{win(reserve.getFst());}
                        return;
                    }
                    if(tempPlayers.size()==0 && reserve.size()>1) break;
                    if(checkAl()) break;
            }
        }
        findWiner();
     }
      
    private void findWiner() throws InterruptedException
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
       int p = tempPlayers.size()-1;
       while(p>=0){
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
                      frame.showWinner(tempPlayers.get(i));
                      tempPlayers.get(i).giveChips(pot/winers);
                  }
                  frame.setStack(tempPlayers.get(i));
              }
              pot=0;
              frame.setPot(pot);
              reserve.removeAll();
    } 
    
    private void win(Player pl) throws InterruptedException
    {
        pl.giveChips(pot);
        pot = 0;
        for(int i = 0; i<tempPlayers.size(); i++)
        {frame.setStack(tempPlayers.get(i));}
        frame.setPot(pot);
        for(int i = 0; i<reserve.size(); i++)
        {frame.setStack(reserve.get(i));}
        frame.setPot(pot);
        frame.showWinner(pl);
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
        ArrayList a1 = new ArrayList();
        a1.add(1);
        a1.add(2);
        a1.add(5);
        a1.add(6);
        ArrayList a2 = new ArrayList();
        a2.add(1);
        a2.add(3);
        a2.add(4);
        a2.add(6);
        Random gen = new Random();
        
        if(tempPlayers.get(i).getTotalBet()<highBet)
        {return new Integer(a2.get(gen.nextInt(a2.size())).toString());}
        else
        {return new Integer(a2.get(gen.nextInt(a1.size())).toString());}
        
    }
        
    public int bet_b(int i)///////////////////////////////////////bot
    {
        return bigBl;
    }
    
    private void playersTurn_G() throws InterruptedException
    {          
            for(int s = tempPlayers.size(); s>0; s--){
                  
            int i, a, b;
            boolean f = false;
            i = tempPlayers.getNextx();
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
                            if(tempPlayers.get(i).getId() == 0){
                                b = bet_r();}
                            else
                            {
                                b = bet_b(i);
                            }
                            f = rise(i, b); break;
                            }                            
                        case 5:{ //bet
                            if(tempPlayers.get(i).getId() == 0){
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
                    }
                  }while(!f);
                }            
    }
        
    private void playersTurn() throws InterruptedException
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
    
    private boolean fold(int i) throws InterruptedException    //1
    {        
        frame.trSleep(tempPlayers.get(i).getId());
        frame.removeBot(tempPlayers.get(i).getId());
        frame.botAction(tempPlayers.get(i), 1);
        allPlayers.add(tempPlayers.remove(i));
        return true;
    }
    private boolean check(int i) throws InterruptedException    //2
    {
        if(highBet == tempPlayers.get(i).getTotalBet())
        {
            frame.trSleep(tempPlayers.get(i).getId());
            frame.botAction(tempPlayers.get(i), 2);
            return true;}
        else
        {return false;}
    }
    private boolean call(int i) throws InterruptedException  //3
    {
        int toCall = (highBet - tempPlayers.get(i).getTotalBet());
        if(tempPlayers.get(i).getStack()>toCall){
        frame.trSleep(tempPlayers.get(i).getId());    
        pot += toCall;
        tempPlayers.get(i).takeChips(toCall);
        frame.setStack(tempPlayers.get(i));
        frame.setPot(pot);
        frame.botAction(tempPlayers.get(i), 3);
        if(tempPlayers.size()==1) reserve.add(tempPlayers.remove(i));
        return true;}
        else
        {return false;}
    }
    private boolean rise(int i, int b) throws InterruptedException        //4
    {
        if(tempPlayers.get(i).getStack()>((highBet - tempPlayers.get(i).getTotalBet())+b))
        {call(i);
         bet(i, b);
         frame.botAction(tempPlayers.get(i), 4);
        return true;}
        else
        {return false;}
    }
    private boolean bet(int i, int b) throws InterruptedException        //5
    {  
       if(tempPlayers.get(i).getStack()>b){
       frame.trSleep(tempPlayers.get(i).getId());    
       highBet += b;
       pot = pot + b;
       tempPlayers.get(i).takeChips(b);
       frame.setStack(tempPlayers.get(i));
       frame.setPot(pot); 
       frame.botAction(tempPlayers.get(i), 5);
        return true;}
       else
       {return false;}
       
    }
    private boolean allin(int i) throws InterruptedException         //6
    {
        if(tempPlayers.get(i).getStack()!=0){
           frame.trSleep(tempPlayers.get(i).getId());
           if(tempPlayers.get(i).getStack()>highBet) 
           {highBet = tempPlayers.get(i).getStack()+tempPlayers.get(i).getTotalBet();}
           pot += tempPlayers.get(i).getStack();    
           tempPlayers.get(i).takeChips(tempPlayers.get(i).getStack());
                     
           frame.setStack(tempPlayers.get(i));
           frame.setPot(pot); 
           frame.botAction(tempPlayers.get(i), 6);
           reserve.add(tempPlayers.remove(i));
           return true;
        }
        return false;
    }
}