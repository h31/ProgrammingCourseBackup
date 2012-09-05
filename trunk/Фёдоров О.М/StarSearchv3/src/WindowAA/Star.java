/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package WindowAA;

import javax.swing.*;
import java.awt.*;

public class Star extends JComponent{
    public int ID;
    String Name;
    int Type;
    Boolean Visibility;
    int PlaceX;
    int PlaceY;
    Boolean Allocation;
    public void setID(int a)
    {
        ID = a;
    }
    public void setName(String a)
    {
        Name = a;
    }
    public void setType(int a)
    {
        Type = a;
    }
    public void setVisibility(Boolean a)
    {
        Visibility = a;
    }
    public void setX(int a)
    {
        PlaceX = a;
    }
    public void setY(int a)
    {
        PlaceY = a;
    }
     
    public Star()
    {
        super();
    }
    
    public Star(int _ID, String _Name, int _Type, int _PlaceX,int _PlaceY)
    {
        ID=_ID;
        Name = _Name;
        Type = _Type;
        PlaceX = _PlaceX;
        PlaceY = _PlaceY;
        Visibility = true;
        Allocation = false;
    }
    public Star(Star s)
    {
        ID=s.ID;
        Name = s.Name;
        Type = s.Type;
        PlaceX = s.PlaceX;
        PlaceY = s.PlaceY;
        Visibility = s.Visibility;
        Allocation = s.Allocation;
    }
    public int getX()
    {
        return(PlaceX);
    }
    public int getY()
    {
        return(PlaceY);
    }
    public void paint(Graphics g)
    {
        super.paint(g);
        if(Visibility)
        {   
            Color color2= Color.yellow; 
            g.setColor(color2);
            int radius = Type;
            int x = PlaceX;
            int y = PlaceY;
            g.fillOval(x-radius, y-radius, 2*radius, 2*radius);
            if(Allocation)
            {
                g.setColor(Color.blue);
                g.drawOval(x-2*radius, y-2*radius, 2*radius+15, 2*radius+15);
            }
        }
        
    }
    public void save()
    {
        
    }
    
    
}
