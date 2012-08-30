
package race;


import java.awt.Color;
import java.awt.Graphics;

public class Car 
{
    private int x1,y1;
    private int width,heigth;
    private Color color;
    
    
    public Car(int x1,int y1,int width, int heigth,Color color)
    {
        this.x1=x1;
        this.y1=y1;
        this.width=width;
        this.heigth=heigth;
        this.color=color;
    }
    
    
    public int get_x() {return x1;}
    public int get_y() {return y1;}
    public int get_width() {return width;}
    public int get_heigth() {return heigth;}
    public Color get_color() {return color;}
    
    public void move(int dx,int dy)
    {
        if ((x1+width+dx>410) || (x1+dx<0)) this.x1=x1;
        else this.x1+=dx;
        if ((y1+heigth+dy>470) || (y1+dy<0)) this.y1=y1;
        else this.y1+=dy;
    }     
}