package race;

import java.awt.Color;
import java.awt.Font;
import java.io.IOException;
import javax.swing.JPanel;
import javax.swing.Timer;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;



public class MainPanel extends JPanel
{
    World world;
    private Timer timer;
    ActionListener timerListener;
    Boolean crash = false;
    int difficultly;
    
    public MainPanel()
    {
        super();
        
        world=new World();
                
        timerListener = new ActionListener() 
        {
            
           @Override
            public void actionPerformed(ActionEvent e)
            {
                if(!world.collision())
                {
                    world.world_step();
                    repaint();
                }
                else 
                {
                    
                    timer.stop();
                    crash= true;
                    
                    new ScoreFrame("Game Over",world.get_score().get_resscore());    
                }
            }
        };
        timer = new Timer(15, timerListener);   
    }
    
    public void restart_game() 
    {
        world=new World();
        timer.start();
    }
    
    public void change_difficultly(int s)
    {
        world.set_difficultly(s);
        this.difficultly=s;
    }
    
    void pause_game()
    {
        if(crash){timer.stop();}
        else if (timer.isRunning()) timer.stop();
        else timer.start();
        
    }
        
    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        world.paint(g);
        
        String s = String.valueOf(difficultly);
        g.setColor(Color.WHITE);
        Font font= new Font("Serif",Font.ITALIC,15);
        g.setFont(font);
        g.fillRect(10, 20, 45, 28);
        g.setColor(Color.BLACK);
        g.drawString(s, 11, 40);
        
    }
}
