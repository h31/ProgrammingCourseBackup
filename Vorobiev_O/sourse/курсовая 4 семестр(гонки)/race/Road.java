
package race;

import java.awt.Color;
import java.awt.Graphics;

public class Road {
    private Color color;
    
    public Road()
    {
        this.color=color.GRAY;
    }
    
    void paint(Graphics g)
    {
        g.setColor(color);
        g.fillRect(260, 0, 100, 480);
    }
    
}
