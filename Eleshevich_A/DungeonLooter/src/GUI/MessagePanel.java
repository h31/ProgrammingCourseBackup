package GUI;

import java.awt.Color;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.util.ArrayDeque;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class MessagePanel extends JPanel implements Messager{
    ArrayDeque<String> strings;
    MessagePanel(){
        strings = new ArrayDeque<String>();
    }
    @Override
    public void paint(Graphics g){
        g.setColor(Color.white);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(Color.black);
        FontMetrics fm = g.getFontMetrics();
        int dheight = 0;
        for(String str: strings){
            g.drawString(str, 10, 15 + dheight);
            dheight += fm.getHeight();
        }
    }
    @Override
    public void print(String str){
        strings.addFirst(str);
        if(strings.size() > 6)
            strings.removeLast();
        repaint();
    }
}
