
package race;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class Road {
    private Color color;
    private Color color2;
    private int x,y;
    private int width,heigth;
    private ArrayList<Block> mass;
    private Blockview block_v;
    
    public Road()
    {
        this.color=color.GRAY;
        this.color2=color.WHITE;
        this.x=0;
        this.y=0;
        this.width=410;
        this.heigth=470;
        mass=new ArrayList<Block>();
    }
    
    void fill_road()
    {
        for(int i=0;i<heigth;i+=70)
        {
            for(int j=0;j<width-70;j+=70)
            {
                Block block=new Block(x+63+j,i,5,25,Color.WHITE);
                mass.add(block);
            }
        }
    }
    
    public int get_x() {return x;}
    public int get_y() {return y;}
    public int get_width() {return width;}
    public int get_heigth() {return heigth;}
    
    void add_band()
    {
        if(mass.get(mass.size()-1).get_y()>70)
        {
            for(int j=0;j<width-70;j+=70)
             {
                 Block block=new Block(x+63+j,0,5,25,Color.WHITE);
                 mass.add(block);
              }   
        }
    }
    
    void road_step()
    {
        for(Block block: mass)
        {
            block.step(0,2);
        }
        
        add_band();
    }
    
    void paint(Graphics g)
    {
        g.setColor(color);
        g.fillRect(x,y,width,heigth);
        g.setColor(color2);
        g.fillRect(x-2+width/2, 0, 5, heigth);
        for(Block block: mass)
        {
            if(block.get_y()>= 480) mass.remove(block);
            else 
            {
                block_v=new Blockview(block);
                block_v.paint(g);
            }
        }
    }
    
}
