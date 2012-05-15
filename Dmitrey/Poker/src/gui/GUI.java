package gui;

import java.awt.Image;
import java.awt.Toolkit;
import javax.swing.JFrame;

public class GUI {

    public static void main(String[] args) {
        
        
        
        MainFrame f = new MainFrame();
        Image im = Toolkit.getDefaultToolkit().getImage("src\\gui\\pic\\logo.png");
        f.setIconImage(im);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(900, 500);
        f.setVisible(true);
    }
}
