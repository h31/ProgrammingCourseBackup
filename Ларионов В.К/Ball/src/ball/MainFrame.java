

package ball;


import javax.swing.JFrame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;


public class MainFrame extends JFrame {
         KeyListener keyListener;
    MainPanel panel;

    public void close(){setVisible(false);}
    MainFrame(String s) {
        super(s);
        setSize(800, 400);
        panel = new MainPanel();
        
        this.add(panel);
        keyListener = new KeyListener() {
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_DOWN:
                        panel.moveRacket(10);
                        break;
                    case KeyEvent.VK_UP:
                        panel.moveRacket(-10);
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

    public static void main(String args[]) {
        MainFrame mf = new MainFrame("Пинг-понг");
   
    }

}
