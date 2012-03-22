package poker;

import java.util.ArrayList;
import java.util.Scanner;

public class Player {
    
    
    private int stack = 1500;
    private ArrayList<Map> maps;
    private String name;
    private Combination com;
    private int totalBet;
    private boolean activ;
    
    public boolean action(int bb, int hb)
    {
        int a;
        Scanner con = new Scanner(System.in);
        System.out.println("intput action: ");
        a = con.nextInt();
        if(a==1){
            fold();
            return false;  
        }
        if(a==2){
            chek();
            return true;
        }
        if(a==3){
            call(hb);
            return true;
        }
        if(a==4){
            rise(bb, hb);
            return true;
        }
        if(a==5){
            bet(bb);
            return true;
        }
        if(a==6){
            allIn();
            return false;
        }
        return false;
        
    }
    
    public void fold()    //1
    {
        stack -= totalBet;
        activ = true;
    }
    public void chek()    //2
    {
        activ = true;
    }
    public void call(int highBet)  //3
    {
        totalBet += (highBet - totalBet);
        activ = true;
    }
    public void rise(int bb, int highBet)        //4
    {
        totalBet += (highBet - totalBet);
        totalBet += bb;
        activ = true;
    }
    public void bet(int bet)        //5
    {
        totalBet += bet;
        activ = true;
    }
    public void allIn()         //6
    {
        totalBet = stack;
        activ = true;
    }
    
    public void newRaund()
    {
        totalBet = 0;
        activ = false;
    }
                        
    public int getStack()
    {return stack;}
    
    public Combination getCom()
    {return com;}
    
    public String getName()
    {return name;}
    
    public void giveWin(int w)
    {
        stack += w;
    }
    
    public int getTotalBet()
    {
        return totalBet;
    }
            
    
}
