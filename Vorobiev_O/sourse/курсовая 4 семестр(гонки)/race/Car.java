
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
    
    public void move(int dx,int dy)
    {
        this.x1+=dx;
        this.y1+=dy;
    }
    
    void paint(Graphics g)
    {
        g.setColor(color);
        g.fillRect(x1, y1, width, heigth);
    }
}