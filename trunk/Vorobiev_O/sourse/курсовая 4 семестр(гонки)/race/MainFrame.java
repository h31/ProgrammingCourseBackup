
package race;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;



public class MainFrame extends JFrame
{
    KeyListener keyListener;
    MainPanel panel;
    MainFrame(String s)
    {
        super(s);
        setSize(640,480);
        panel = new MainPanel();
        this.add(panel);
        keyListener=new KeyListener()
        {
            @Override
            public void keyPressed(KeyEvent e)
            {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_DOWN:
                        panel.move_car(0, 5);
                        break;
                    case KeyEvent.VK_UP:
                        panel.move_car(0, -5);
                        break;
                    case KeyEvent.VK_LEFT:
                        panel.move_car(-5, 0);
                        break;
                    case KeyEvent.VK_RIGHT:
                        panel.move_car(5, 0);
                        break;
                }
            }
            public void keyReleased(KeyEvent e) {}
            public void keyTyped(KeyEvent e) {}
        };
        
        this.addKeyListener(keyListener);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    public static void main(String[] args) {
        new MainFrame("My race.");
    }
}
