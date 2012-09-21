package karno;

import java.awt.GridLayout;
import javax.swing.*;

public class GUI extends JFrame {
    
    JPanel mp = new JPanel();
    JLabel cl1 = new JLabel("00");
    JLabel cl2 = new JLabel("01");
    JLabel cl3 = new JLabel("11");
    JLabel cl4 = new JLabel("10");
    JLabel cl5 = new JLabel("00");
    JLabel cl6 = new JLabel("01");
    JLabel cl7 = new JLabel("11");
    JLabel cl8 = new JLabel("10");
    JTextField cell1 = new JTextField();
    JTextField cell2 = new JTextField();
    JTextField cell3 = new JTextField();
    JTextField cell4 = new JTextField();
    JTextField cell5 = new JTextField();
    JTextField cell6 = new JTextField();
    JTextField cell7 = new JTextField();
    JTextField cell8 = new JTextField();
    JTextField cell9 = new JTextField();
    JTextField cell10 = new JTextField();
    JTextField cell11 = new JTextField();
    JTextField cell12 = new JTextField();
    JTextField cell13 = new JTextField();
    JTextField cell14 = new JTextField();
    JTextField cell15 = new JTextField();
    JTextField cell16 = new JTextField();
    JLabel cr = new JLabel("X1X2|X3X4");
    
    GUI()
    {
       super("Table");
       setSize(400, 400);
       setVisible(true);
       setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       
       mp.setLayout(new GridLayout(5,5));
       mp.add(cr);
       mp.add(cl1);
       mp.add(cl2);
       mp.add(cl3);
       mp.add(cl4);
       mp.add(cl5);
       mp.add(cell1);
       mp.add(cell2);
       mp.add(cell3);
       mp.add(cell4);
       mp.add(cl6);
       mp.add(cell5);
       mp.add(cell6);
       mp.add(cell7);
       mp.add(cell8);
       mp.add(cl7);
       mp.add(cell9);
       mp.add(cell10);
       mp.add(cell11);
       mp.add(cell12);
       mp.add(cl8);
       mp.add(cell13);
       mp.add(cell14);
       mp.add(cell15);
       mp.add(cell16);
       add(mp);
       //repaint();
       //revalidate();
    }
}
