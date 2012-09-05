


package ball;

import javax.swing.*;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.BorderLayout;
import java.awt.event.*;
import javax.swing.border.LineBorder;


public class MainFrame extends JFrame {
         KeyListener keyListener;
    MainPanel panel;
    JPanel cpanel;
    JCheckBox checkbox;
  
    

    public void close(){setVisible(false);}
    MainFrame(String s) {
          super(s);
           
        setSize(800, 600);
         panel = new MainPanel();
//         
        this.setLayout(new BorderLayout());
      
     
     
        panel.setBorder(new LineBorder(Color.BLUE, 2));
        panel.setPreferredSize(new Dimension(800, 400));
        this.add(panel, BorderLayout.NORTH);
       
//        this.add(panel);
         setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        keyListener = new KeyListener() {
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_DOWN:
                        panel.moveRacket(10);
                        break;
                    case KeyEvent.VK_UP:
                        panel.moveRacket(-10);
                        break;
                   case KeyEvent.VK_SPACE:
                        panel.pause();
                        break;
                    
                }
            }
                   public void keyReleased(KeyEvent e) {}
            public void keyTyped(KeyEvent e) {}
        };
        
//           cpanel = new CtrlJPanel();
//        cpanel.setPreferredSize(new Dimension(800, 200));
//        this.add(cpanel, BorderLayout.SOUTH);
//         setVisible(true);
          initCPanel();
        setVisible(true);
     addKeyListener(keyListener);
     
    }
 private void initCPanel() {
        cpanel = new JPanel();
        cpanel.setPreferredSize(new Dimension(800, 100));
        String[] items = {
	    "red",
	    "green",
	    "blue"};
        JComboBox cbox1 = new JComboBox(items);
        ActionListener actionListener = new ActionListener() {
	            public void actionPerformed(ActionEvent e) {
                  JComboBox box = (JComboBox)e.getSource();
	                        String item = (String)box.getSelectedItem();
                                if (item=="blue"){panel.change_col(Color.BLUE);}
                                if (item=="green"){panel.change_col(Color.GREEN);}
                                if (item=="red"){panel.change_col(Color.RED);}
                              swp();
                   
                                
                               
	          
            }};  
        cbox1.addActionListener(actionListener);

        cbox1.setAlignmentX(LEFT_ALIGNMENT);
        cbox1.setAlignmentY(BOTTOM_ALIGNMENT);
        JLabel head = new JLabel("Выберите цвет");
     cpanel.add(head); 
        cpanel.add(cbox1);
         checkbox = new JCheckBox("гравитация ");
        checkbox.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                if (checkbox.isSelected()){ panel.v=1;  swp();
                }
                else {panel.v=0;swp();}
            }
        });
     setVisible(true);  
     cpanel.add(checkbox);
        add(cpanel, BorderLayout.SOUTH);
      
 }

    public static void main(String args[]) {
        new MainFrame("mega_game");
        
   
    }
    
    public void swp()
    {
      panel.transferFocusUpCycle();
      
        
    }

}
