
package race;

import java.awt.Color;
import java.awt.Graphics;

public class Block {
    
    private int x,y;
    private int width,heigth;
    private Color color;
    
    public Block(int x,int y,int width, int heigth,Color color)
    {
        this.x=x;
        this.y=y;
        this.width=width;
        this.heigth=heigth;
        this.color=color;
    }
    
    int get_x() {return x;}
    int get_y() {return y;}
    int get_width() {return width;}
    int get_heigth() {return heigth;}
    void step(int dx,int dy)
    {
        this.x+=dx;
        this.y+=dy;
    }
    void paint(Graphics g)
    {
        g.setColor(color);
        g.fillRect(x, y, width, heigth);
    }
}
