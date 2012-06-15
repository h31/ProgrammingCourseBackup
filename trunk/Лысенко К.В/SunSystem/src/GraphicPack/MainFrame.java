package GraphicPack;

import LogicPack.Planet;
import java.awt.Container;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayDeque;
import javax.swing.JFrame;

public class MainFrame extends JFrame{
    public MainFrame(String s, ArrayDeque<Planet> planets){
        super(s);
        setSize(816, 838);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();
        MainPanel panel = new MainPanel(planets);
        addKeyListener(new KeyMonitor(panel));
        panel.setBounds(0, 0, contentPane.getWidth(), contentPane.getHeight());
        this.add(panel);
        setVisible(true);
    }
}

class KeyMonitor extends KeyAdapter{
    Screen scr;
    
    KeyMonitor(Screen scr){
        this.scr = scr;
    }
    @Override
    public void keyPressed(KeyEvent e){
        switch(e.getKeyCode()){
            case KeyEvent.VK_UP:if(scr.getTfact()<=4096) scr.setTfact(scr.getTfact()*2); break;
            case KeyEvent.VK_DOWN: scr.setTfact(scr.getTfact()/2); break;
            case KeyEvent.VK_SPACE: scr.setTfact(1); break;
        }
    }
}