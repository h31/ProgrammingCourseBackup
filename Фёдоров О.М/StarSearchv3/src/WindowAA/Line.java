/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package WindowAA;

import WindowAA.Star;
import javax.swing.*;
import java.awt.*;

public class Line extends JComponent {
    public Star Star1;
    public Star Star2;
    public Boolean Visibility;
    public Line(Star St1,Star St2)
    {
        Star1 = new Star(St1);
        Star2 = new Star(St2);
        Visibility = true;
        
    }
/*    public Line(Line sl)
    {
        if(sl == null)
        {
            Star1 = new Star(1,"BB",10,200,150);
            Star2 = new Star(0,"AA",5,150,150);
        }
        Star1 = new Star(sl.Star1);
        Star2 = new Star(sl.Star2);
    }*/
    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        if(Visibility)
        {
            Color color= Color.red; 
            g.setColor(color);
            g.drawLine(Star1.getX(),Star1.getY(),Star2.getX(),Star2.getY());
        }
    }
}
