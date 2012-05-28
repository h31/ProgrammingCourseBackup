package poker;

import java.awt.BorderLayout;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.GridLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JPanel;
import javax.swing.JTextField;



public class StartFrame{
    
        private JButton ng;
        private JButton sb;
        private JButton qt;
        private JButton ob;
        private ActionListener mLs;   
        private int bb;
        private JTextField tf;
        public JFrame f;
        private JPanel p;
        private boolean h;
        
public StartFrame(){
        ng = new JButton("New Game");
        sb = new JButton("Set Blinds");
        qt = new JButton("Quit");
        ob = new JButton("OK");
        bb = 20;
        tf = new JTextField();
        f = new JFrame("Poker");
        p = new JPanel();
 }
public void Start() throws InterruptedException{
        h = false;
        f.setSize(400, 200);
        Image ic = Toolkit.getDefaultToolkit().getImage("src\\gui\\pic\\logo.png");
        f.setIconImage(ic);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setBackground(new Color(50, 160, 35));
        p.setBackground(new Color(50, 160, 35));
        p.repaint();
        f.repaint();
        
        mLs = new ActionListener() {
        
             public void actionPerformed(ActionEvent e) {
                if(e.getSource()==ng){h = true; f.dispose();}
                if(e.getSource()==sb){tf.setVisible(true); ob.setVisible(true);}
                if(e.getSource()==qt){f.dispose(); System.exit(0);}
                if(e.getSource()==ob){bb=new Integer(tf.getText()); tf.setVisible(false);
                ob.setVisible(false);
                }
             }
        };
                
        ng.addActionListener(mLs);
        sb.addActionListener(mLs);
        qt.addActionListener(mLs);
        ob.addActionListener(mLs);
        p.setLayout(new GridLayout(5, 1));
        p.add(ng);
        p.add(sb);
        p.add(qt);
        ob.setVisible(false);
        tf.setVisible(false);
        p.add(ob);
        p.add(tf);
        p.repaint();
        f.setLayout(new BorderLayout());
        
        JPanel t = new JPanel();
        t.setBackground(new Color(50, 160, 35));
        JPanel b = new JPanel();
        b.setBackground(new Color(50, 160, 35));
        JPanel l = new JPanel();
        l.setBackground(new Color(50, 160, 35));
        JPanel r = new JPanel();
        r.setBackground(new Color(50, 160, 35));
        
        f.add(t, BorderLayout.NORTH);
        f.add(b, BorderLayout.SOUTH);
        f.add(l, BorderLayout.WEST);
        f.add(r, BorderLayout.EAST);
        f.add(p, BorderLayout.CENTER); 
        
    }

    public int _b()
    {
        return bb;
    }
    
    public boolean rdy()
    {
        return h;
    }
}