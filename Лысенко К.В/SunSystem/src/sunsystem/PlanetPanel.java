package sunsystem;

import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.util.StringTokenizer;
import javax.swing.JPanel;

public class PlanetPanel extends JPanel{
    Planet planet;
    Image img;
    
    PlanetPanel(Planet tplanet){
        super();
        planet = tplanet;
        img = planet.getBigImage();
    }
    
    @Override
    public void paint(Graphics g){
        super.paint(g);
        g.drawString(planet.getName(), 155, 20);
        StringTokenizer st = new StringTokenizer(planet.getDiscr());
        FontMetrics fm = g.getFontMetrics();
        int width = getWidth();
        StringBuilder sb = new StringBuilder();
        int space = fm.charWidth(' ');
        int sheight = 0;
        while(st.hasMoreTokens()){
            String str = st.nextToken();
            if(fm.stringWidth(sb.toString()) + fm.stringWidth(str) + space + 10 > width){
                g.drawString(sb.toString(), 10, 170 + sheight);
                sheight += fm.getHeight();
                sb = new StringBuilder();
                sb.append(str);
            }   
            else
                sb.append(' ').append(str);
        }
        g.drawString(sb.toString(), 10, 170 + sheight);
        g.drawImage(img, 0, 0, 150, 150, this);
    }
}
