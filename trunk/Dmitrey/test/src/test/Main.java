package test;

import java.util.Scanner;


public class Main {
  public static void main(String[] args) throws InterruptedException {
  
    Scanner cin = new Scanner(System.in);
    
    
      Card[] fc = new Card[7];
      Card[] sc = new Card[7];
      
      System.out.println("Тест для класса Hand.");
      System.out.println("формат ввода карт игрока: номер_масти ранг_карты номер_масти ранг_карты номер_масти ранг_карты номер_масти ранг_карты номер_масти ранг_карты номер_масти ранг_карты номер_масти ранг_карты");
      System.out.println("0-hearts 1-spades 2-diamonds 3-clubs");
      System.out.println("цифра ранга=номер ранга карты-1, кроме туза(туз-0)");
      System.out.println("Введите карты первого игрока:");
      
      for(int i = 0; i<7; i++)
      {
        int r, s;
        r=cin.nextInt();
        s=cin.nextInt();
        fc[i] = new Card(r, s);
      }
      System.out.println("Введите карты второго игрока:");
      for(int i = 0; i<7; i++)
      {
        int r, s;
        r=cin.nextInt();
        s=cin.nextInt();
        sc[i] = new Card(r, s);
      }
      
      
      
      int u = new TestHand(fc).compareTo(new TestHand(sc));
     
      if(u<0) System.out.println("second player is wins!");
      if(u>0) System.out.println("fist player is wins!");
      if(u==0) System.out.println("both players are wins!");
  }

  
}
