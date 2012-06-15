package sunsystem;

import java.awt.Container;
import java.util.ArrayDeque;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MainFrame extends JFrame{
    MainFrame(String s, ArrayDeque<Planet> planets){
        super(s);
        setSize(800, 800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();
        JPanel panel = new MainPanel(planets);
        panel.setBounds(0, 0, contentPane.getWidth(), contentPane.getHeight());
        this.add(panel);
        setVisible(true);
    }
}