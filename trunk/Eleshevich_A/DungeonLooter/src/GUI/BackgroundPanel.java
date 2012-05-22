package GUI;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class BackgroundPanel extends JPanel{
    JPanel Dpanel;
    JPanel Ppanel;
    JPanel Mpanel;
    int sWidth = 880;
    int sHeight = 710;
    
    BackgroundPanel(JPanel Dpanel, JPanel Ppanel, JPanel Mpanel){
        this.Dpanel = Dpanel;
        this.Ppanel = Ppanel;
        this.Mpanel = Mpanel;
    }
    
    @Override
    public void paint(Graphics g){
        int width = getWidth();
        int height = getHeight();
        g.setColor(Color.gray);
        g.drawRect(0, 0, width, height);
        int dmxcorner = (width - sWidth)/2;
        int dpycorner = (height - sHeight)/2;
        int dmwidth = (int)((2d/3)*sWidth);
        int dheight = dmwidth;
        Dpanel.setBounds(dmxcorner, dpycorner, dmwidth, dheight);
        Ppanel.setBounds(dmxcorner + dmwidth, dpycorner, sWidth - dmwidth, sHeight);
        Mpanel.setBounds(dmxcorner, dpycorner + dheight, dmwidth, sHeight - dheight);
    }
}
