
package race;

import java.awt.BorderLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.KeyStroke;


public class MainFrame extends JFrame
{
    KeyListener keyListener;
    MainPanel panel;
    JMenuBar menuBar;
    JMenu m1, m2,m3,ms1;
    JMenuItem mf1,mf2,mf3,mr1;
    JRadioButtonMenuItem mss1,mss2,mss3,mss4;
    
    
    
    
    MainFrame(String s)
    {
        super(s);
        
        
        setBounds(200,80,425,531);
        
        
        this.setLayout(new BorderLayout());
        
        menuBar = new JMenuBar();
        
        m1 = new JMenu("File");
        menuBar.add(m1);
        
        mf1 = new JMenuItem("New game");
        mf1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_N, ActionEvent.CTRL_MASK));
        mf1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                panel.restart_game();
            }
        });
        m1.add(mf1);
        
        mf2 = new JMenuItem("Pause/Continue");
        mf2.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_P, ActionEvent.CTRL_MASK));
        mf2.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                panel.pause_game();
            }
        });
        m1.add(mf2);
        
        mf3 = new JMenuItem("Exit");
        mf3.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_E, ActionEvent.CTRL_MASK));
        mf3.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                System.exit(0);
            }
        });
        m1.add(mf3);
        
        m2 = new JMenu("Records");
        menuBar.add(m2);
        
        mr1 = new JMenuItem("View records");
        mr1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, ActionEvent.CTRL_MASK));
        mr1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                try {
                    new RecordList(" ",0);
                } catch (FileNotFoundException ex) {
                    Logger.getLogger(MainFrame.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        m2.add(mr1);
        
        m3 = new JMenu("Settings");
        menuBar.add(m3);
        
        ms1 = new JMenu("Level");
        m3.add(ms1);
        
        ButtonGroup group = new ButtonGroup();
        mss1 = new JRadioButtonMenuItem("Easy");
        mss1.setSelected(true);
        mss1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                panel.change_difficultly(110);
                panel.restart_game();
                panel.pause_game();
            }
        });
        group.add(mss1);
        ms1.add(mss1);
        
        mss2 = new JRadioButtonMenuItem("Medium");
        mss2.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                panel.change_difficultly(40);
                panel.restart_game();
                panel.pause_game();
            }
        });
        group.add(mss2);
        ms1.add(mss2);
        
        mss3 = new JRadioButtonMenuItem("Hard");
        mss3.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                panel.change_difficultly(-10);
                panel.restart_game();
                panel.pause_game();
            }
        });
        group.add(mss3);
        ms1.add(mss3);
        
        mss4 = new JRadioButtonMenuItem("Hardcore");
        mss4.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                panel.change_difficultly(-80);
                panel.restart_game();
                panel.pause_game();
            }
        });
        group.add(mss4);
        ms1.add(mss4);
        
        this.setJMenuBar(menuBar);
        
        panel = new MainPanel();
        this.add(panel,BorderLayout.CENTER);
        
        keyListener=new KeyListener()
        {
            @Override
            public void keyPressed(KeyEvent e)
            {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_DOWN:
                        panel.world.move_car(0,4);
                        break;
                    case KeyEvent.VK_UP:
                        panel.world.move_car(0, -4);
                        break;
                    case KeyEvent.VK_LEFT:
                        panel.world.move_car(-5, 0);
                        break;
                    case KeyEvent.VK_RIGHT:
                        panel.world.move_car(5, 0);
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
    
    
    public static void main(String[] args) 
    {
        new MainFrame("My race.");
    }
}
