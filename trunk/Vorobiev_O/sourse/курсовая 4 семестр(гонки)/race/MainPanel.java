
package race;

import java.awt.Color;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.Graphics;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class MainPanel extends JPanel
{
    private Car car;
    private Road road;
    private Block block;
    private Timer timer;
    ActionListener timerListener;
    
    public MainPanel()
    {
        super();
        car= new Car(310,380,20,40,Color.BLACK);
        road= new Road();
        block= new Block(260,0,50,40,Color.RED);
        
        
        timerListener = new ActionListener() 
        {
            
           @Override
            public void actionPerformed(ActionEvent e)
            {
                if(!collision())
                {
                    block.step(0,3);
                    repaint();
                }
                
                if(collision())
                {
                    
                    
                }
            }
        };
        timer = new Timer(20, timerListener);
        timer.start();
    }
        
    void move_car(int dx,int dy)
    {
        car.move(dx, dy);
    }
    
    boolean collision()
    {
        
        return (car.get_x() > block.get_x()) && 
               (car.get_x() < block.get_x() + block.get_width()) && 
               (car.get_y() <= block.get_y() + block.get_heigth() &&
               (car.get_y() > block.get_y()));
    }
    
    void game_over(Graphics g)
    {
        Font font= new Font("Serif",Font.ITALIC,24);
        g.drawString("Crashed!", 200, 100);
    }        
    
    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        road.paint(g);
        car.paint(g);
        block.paint(g);
    }
}
