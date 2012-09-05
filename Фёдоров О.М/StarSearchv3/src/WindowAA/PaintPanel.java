/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package WindowAA;

import java.io.*;
import java.util.*;
import javax.swing.*;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.Timer;
import javax.swing.JPanel;
import java.lang.*;
//import Graphics.*;

public class PaintPanel extends JPanel{
     private Timer timer;
     ActionListener timerListener;
     MouseListener mouseListener;
     MouseMotionListener mousMotionListener;
     public Boolean Edi = false;
     int X,Y;
     String Name;
     int Type;
     Boolean StarB = false;
     Boolean LineB = false;
    
    
    public void setEdi(Boolean a)
    {
      Edi = a;
    }
    
    
    
    
    
    
    
    
    public PaintPanel()
    {
        super();
        /*mouseListener = new MouseListener() {
            public void mouseClicked(MouseEvent e) { 
                                BufferedReader in2;
                String z="";
                if((Edi == true) && StarB && !LineB)
                {
                    try {
                        in2 = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\SQLStars.txt")));
                        while (in2.ready()) {
                            z = in2.readLine();
                        }
                        } catch (IOException x) {
                        }
                    String z2[] = z.split(":"); 
                    X=e.getX();
                    Y=e.getY();
                    Star NewStar = new Star(Integer.parseInt(z2[0]),Name,Type,e.getX(),e.getY());
                    
                
                }
            }

            public void mousePressed(MouseEvent e) {
               // if (e.getButton()==MouseEvent.BUTTON1)
                //    hold = ball.inside(e.getX(), e.getY());
            }

            public void mouseReleased(MouseEvent e) {
                //if (e.getButton()==MouseEvent.BUTTON1)
                 //   hold = false;
            }

            public void mouseEntered(MouseEvent e) {}

            public void mouseExited(MouseEvent e) {}
        };
        this.addMouseListener(mouseListener);*/
        /*mousMotionListener  = new MousMotionListener(){
            public void mouseDragged(MouseEvent e)
            {
                
            }

            public void mouseMoved(MouseEvent e)
            {
                
            }
        };*/
        
    }
    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        /*BufferedReader in;
        BufferedReader in2;
        String s="";
        String z="";
        
        try {
            in2 = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\SQLStars.txt")));
            while (in2.ready()) {
                z = in2.readLine();
            }
        } catch (IOException e) {
        }
        String z2[] = z.split(":");
        Star Stars[] = new Star[Integer.parseInt(z2[0])];
        
        int o = 0;
        //System.out.println(z2[10]);
        for(int i = 1; i < z2.length; i++)
        {
            try {
            String z3[] = z2[i].split(" ");
            //System.out.println(z3[0]);
            //Stars[o].setID(Integer.parseInt(z3[0]));
            //Stars[o].setName(z3[1]);
            //Stars[o].setType(Integer.parseInt(z3[2]));
            //Stars[o].setX(Integer.parseInt(z3[3]));
            //Stars[o].setY(Integer.parseInt(z3[4]));
            Stars[o] = new Star(Integer.parseInt(z3[0]),z3[1],Integer.parseInt(z3[2]),Integer.parseInt(z3[3]),Integer.parseInt(z3[4]));
            o++;
            } catch (NumberFormatException e) {
            e.printStackTrace();
        } 
        }
        
        //System.out.println(z2[10]);
        
        
        
        
        
        
        try {
            in = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\SQLConstellations.txt")));
            while (in.ready()) {
                s = in.readLine();
            }
        } catch (IOException e) {
        }
        String s2[] = s.split(":");
        int j = Integer.parseInt(s2[0]);
        Constellation Constellations[];
        Constellations = new Constellation[j];
        int k = 0;
        
        
        
        for(int i = 1;i<s2.length;i=i+4)
        {
            //Constellations[k].ID=Integer.parseInt(s2[i]);
            //Constellations[k].Name=s2[i+1];
            String s3[] = s2[i+2].split(" "); // s3 - содержит айди звезд, которые находятся в этом созвездии
            //Constellations[k].Stars = new Star[s3.length];
            Star TempStars[] = new Star[s3.length];
            for(int t = 0; t<s3.length;t++)
            {
                for(int h = 0; h<Stars.length;h++)
                {
                    if(Integer.parseInt(s3[t])==Stars[h].ID)
                    //Constellations[k].Stars[t] = Stars[h];
                        TempStars[t]= new Star(Stars[h]);
                }
            }
            String s4[] =s2[i+3].split("-");
            Line TempLines[] =  new Line[s4.length];
            Star TempSt1 = new Star();
            Star TempSt2 = new Star();
            for(int t = 0; t<s4.length;t++)
            {
                String s5[] = s4[t].split(" "); //сплит по пробелу для разделения айди звезд для линий
                //Constellations[k].Lines = new Line[s4.length];  
                for(int p = 0; p<Stars.length;p++)
                {
                    if(Integer.parseInt(s5[0])==Stars[p].ID)
                        TempSt1= new Star(Stars[p]);
                    if(Integer.parseInt(s5[1])==Stars[p].ID)
                        TempSt2 = new Star(Stars[p]);
                        
                    //TempLines[t] = new Line(TempSt1,TempSt2);}
                }
                TempLines[t] = new Line(TempSt1,TempSt2);
                //TempLines[t].Star2=TempSt2;
                
            }
            
            Constellations[k] = new Constellation(Integer.parseInt(s2[i]),s2[i+1],TempStars,TempLines);
            k++;
        }*/
        

        /*for(int b = 0; b < Constellations[0].Lines.length; b++)
        Constellations[0].Lines[b].paint(g);
        for(int b = 0; b < Constellations[0].Stars.length; b++)
        Constellations[0].Stars[b].paint(g);
        
        
        for(int b = 0; b < Constellations[1].Lines.length; b++)
        Constellations[1].Lines[b].paint(g);
        for(int b = 0; b < Constellations[1].Stars.length; b++)
        Constellations[1].Stars[b].paint(g);*/

        
        
        
    /*    Star TestStar = new Star(0,"AA",5,150,150);
        
        Star TestStar2 = new Star(1,"BB",10,200,150);
        
        Line TestLine = new Line(TestStar,TestStar2);
        TestLine.paint(g);
        TestStar.paint(g);
        TestStar2.paint(g);
        //g.fillOval(150, 150, 10, 10);*/
    }
    public void paint2(Graphics g,Star St)
    {
        super.paint(g);
        St.paint(g);
    }

    
}
