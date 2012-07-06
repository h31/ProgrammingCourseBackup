
package race;

import java.awt.Color;
import java.awt.Graphics;

public class Block {
    
    private int x,y;
    private int width,heigth;
    private Color color;
    private int dx,dy;
    
    
    public Block(int x,int y,int width, int heigth,Color color)
    {
        this.x=x;
        this.y=y;
        this.width=width;
        this.heigth=heigth;
        this.color=color;
        this.dx=0;
        this.dy=0;
    }
    
    public int get_x() {return x;}
    public int get_y() {return y;}
    public int get_width() {return width;}
    public int get_heigth() {return heigth;}
    public Color get_color() {return color;}
    
    void set_speed(int dx_,int dy_)
    {
        this.dx=dx_;
        this.dy=dy_;
    }
    
    void step(int dx_,int dy_)
    {
        this.x+=dx_;
        this.y+=dy_;
    }
    
    void step()
    {
       this.x+=dx;
       this.y+=dy; 
    }
    
}
