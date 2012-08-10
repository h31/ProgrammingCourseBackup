
package race;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ScoreFrame extends JFrame
{
    ScoreFrame(String s,final int score)
    {
        super(s);
        int x=250,y=160;
        setBounds(250,150,x,y);
        setLayout(null);
        setResizable(false);
        int score_=score;
        
        JLabel text = new JLabel("You score is:");
        text.setBounds(x/2-40,10, 80, 40);
        add(text);
        
        JLabel text2 = new JLabel(String.valueOf(score));
        text2.setBounds(x/2-20,30, 80, 40);
        add(text2);
        
        JButton recButton = new JButton("View records");
        recButton.setBounds(x/2-80, 70, 140, 20);
        recButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                new RecordList(" ",score);
            }
        });
        add(recButton);
        
        
        JButton exitButton = new JButton("Exit to Windows");
        exitButton.setBounds(x/2-80, 100, 140, 20);
        exitButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                System.exit(0);
            }
        });
        add(exitButton);
        setVisible(true);
        
        setDefaultCloseOperation(JFrame.ABORT);
    }
}
