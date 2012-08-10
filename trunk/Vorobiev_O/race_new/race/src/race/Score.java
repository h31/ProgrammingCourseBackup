package race;

import java.awt.Graphics;
import java.awt.Font;
import java.awt.Color;

public class Score
{
   private int recent_score;
   private Road test_road;
   private Font font;
   private String s;
   private Color t_color;
   private Color b_color;
   private int x=0,y=0;
   private int difficultly;
   
   public Score()
   {
       this.x=360;
       this.y=5;
       this.recent_score=0;
       test_road= new Road();
       Font font= new Font("Serif",Font.ITALIC,9);
       this.t_color= t_color.BLACK;
       this.b_color= b_color.WHITE;
   }
   
   int get_resscore() {return recent_score;}
   
   void change_difficultly(int a) {this.difficultly=a;}
           
   void raise_score(Car car)
   {
       if (car.get_x()<test_road.get_x()+test_road.get_width()/2) recent_score+=2*(400-2*difficultly)/100;
       else recent_score+=(400-2*difficultly)/100;
   }
   
   void printScore(Graphics g)
    {
        
        int x=100;
        int y=100;
        g.setColor(b_color);
        g.fillRect(x, y, 100, 100);
        s=String.valueOf(recent_score);
        g.setColor(t_color);
        g.drawString(s, x+50, y+50);
    }
   
   
   void paint(Graphics g, Car car)
   {
       s = String.valueOf(recent_score);
       g.setColor(b_color);
       g.setFont(font);
       g.fillRect(x, y, 45, 28);
       g.setColor(t_color);
       g.drawString("Score:", x+5, y+10);
       g.drawString(s, x+5, y+25);
       if (car.get_x()<test_road.get_x()+test_road.get_width()/2) 
       {
           g.setColor(b_color);
           g.fillRect(x, y+28, 45, 14);
           g.setColor(t_color);
           g.drawString("2x!!!", x+5, y+40);
       }
   }
}
