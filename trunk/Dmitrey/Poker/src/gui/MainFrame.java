package gui;

import poker.*;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import java.awt.Image;
import java.awt.Toolkit;

    
public class MainFrame extends JFrame{
  
    private JButton b2 = new JButton("RAISE"), b1 = new JButton("CALL"), b3 = new JButton("FOLD"), b4 = new JButton("ALL_IN");
    private JLabel pa1 = new JLabel("pa"), pa2 = new JLabel("pa"), pa3 = new JLabel("pa"), pa4 = new JLabel("pa"), pa5 = new JLabel("pa"), stack = new JLabel("STACK"), pot = new JLabel("POT: 0"), bank1 = new JLabel("BANK"), bank2 = new JLabel("BANK"), bank3 = new JLabel("BANK"), bank4 = new JLabel("BANK"), bank5 = new JLabel("BANK");
    private JLabel c1= new JLabel(), c2= new JLabel(), c3= new JLabel(), c4= new JLabel(), c5= new JLabel(), cp1 = new JLabel(), cp2 = new JLabel();
    private JLabel plim1;
    private JLabel plim2;
    private JLabel plim3;
    private JLabel plim4;
    private JLabel plim5;
    private JLabel st1;
    private JLabel st2;
    private JLabel st3;
    private JLabel st4;
    private JLabel st5;
    private JLabel stp;
    private JPanel bot = new JPanel();
    private JPanel top = new JPanel();
    private JPanel pane1 = new JPanel();
    private JPanel pane2 = new JPanel();
    private JPanel pane3 = new JPanel();
    private JPanel pane4 = new JPanel();
    private JPanel pane4_1 = new JPanel();
    private JPanel pane4_2 = new JPanel();
    private JMenuItem mIt1 = new JMenuItem();
    private JMenuItem mIt2 = new JMenuItem();
    private JMenuItem mIt3 = new JMenuItem();
    private JMenuItem mIt4 = new JMenuItem();
    private JMenuItem mIt5 = new JMenuItem();
    private JMenuItem mIt6 = new JMenuItem();
    private JMenuItem mIt7 = new JMenuItem();
    private JMenu menu1 = new JMenu();
    private JMenu menu2 = new JMenu();
    private JMenuBar menBar = new JMenuBar();
    private JTextField bet = new JTextField("0");
    private JButton bt = new JButton("OK");
    private int act;
    
    public MainFrame()
    {
        super("Poker_GUI");
        setSize(1030, 500);
        Image ic = Toolkit.getDefaultToolkit().getImage("src\\gui\\pic\\logo.png");
        setIconImage(ic);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        plim1 = new JLabel(new ImageIcon("src\\gui\\pic\\player_a.png"));
        plim2 = new JLabel(new ImageIcon("src\\gui\\pic\\player_a.png"));
        plim3 = new JLabel(new ImageIcon("src\\gui\\pic\\player_a.png"));
        plim4 = new JLabel(new ImageIcon("src\\gui\\pic\\player_a.png"));
        plim5 = new JLabel(new ImageIcon("src\\gui\\pic\\player_a.png"));
        
        JPanel pl1 = new JPanel();
        JPanel pl2 = new JPanel();
        JPanel pl3 = new JPanel();
        JPanel pl4 = new JPanel();
        JPanel pl5 = new JPanel();
        
        st1 = new JLabel();
        st2 = new JLabel();
        st3 = new JLabel();
        st4 = new JLabel();
        st5 = new JLabel();
        stp = new JLabel();
        
        pl1.setLayout(new BorderLayout());
        pl2.setLayout(new BorderLayout());
        pl3.setLayout(new BorderLayout());
        pl4.setLayout(new BorderLayout());
        pl5.setLayout(new BorderLayout());
        
        pl1.setBackground(new Color(50, 160, 35));
        pl2.setBackground(new Color(50, 160, 35));
        pl3.setBackground(new Color(50, 160, 35));
        pl4.setBackground(new Color(50, 160, 35));
        pl5.setBackground(new Color(50, 160, 35));
        
        pl1.add(plim1, BorderLayout.WEST);
        pl1.add(bank1, BorderLayout.CENTER);
        pl1.add(pa1, BorderLayout.SOUTH);
        pl1.add(st1, BorderLayout.EAST);
        pl2.add(plim2, BorderLayout.WEST);
        pl2.add(bank2, BorderLayout.CENTER);
        pl2.add(pa2, BorderLayout.SOUTH);
        pl2.add(st2, BorderLayout.EAST);
        pl3.add(plim3, BorderLayout.WEST);
        pl3.add(bank3, BorderLayout.CENTER);
        pl3.add(pa3, BorderLayout.SOUTH);
        pl3.add(st3, BorderLayout.EAST);
        pl4.add(plim4, BorderLayout.WEST);
        pl4.add(bank4, BorderLayout.CENTER);
        pl4.add(pa4, BorderLayout.SOUTH);
        pl4.add(st4, BorderLayout.EAST);
        pl5.add(plim5, BorderLayout.WEST);
        pl5.add(bank5, BorderLayout.CENTER);
        pl5.add(pa5, BorderLayout.SOUTH);
        pl5.add(st5, BorderLayout.EAST);
        
        pane1.setLayout(new FlowLayout());
        pane1.add(pl1);
        pane1.add(pl2);
        pane1.add(pl3);
        pane1.add(pl4);
        pane1.add(pl5);
        
        pane2.setLayout(new GridLayout(1, 6));
        pane2.add(c1);
        pane2.add(c2);
        pane2.add(c3);
        pane2.add(c4);
        pane2.add(c5);
        pane2.add(pot);
        
        pane4_1.setLayout(new FlowLayout());
        pane4_1.setBackground(new Color(50, 160, 35));
        pane4_1.add(cp1);
        pane4_1.add(cp2);
        
               
        bot.setBackground(new Color(50, 160, 35));
        top.setBackground(new Color(50, 160, 35));
        bet.setBackground(new Color(50, 160, 35));
        bot.add(stack);
        bot.add(stp);
        top.setLayout(new FlowLayout());
        top.add(b1);
        top.add(b2);
        top.add(b3);
        top.add(b4);
        top.add(bet);
        top.add(bt);
        pane4_2.setLayout(new GridLayout(2, 1));
        pane4_2.add(top);
        pane4_2.add(bot);
        
        pane4.setLayout(new FlowLayout());
        pane4.add(pane4_1);
        pane4.add(pane4_2);
        
        this.setLayout(new GridLayout(3, 1));
        
        pane1.setBackground(new Color(50, 160, 35));
        pane2.setBackground(new Color(50, 160, 35));
        pane3.setBackground(new Color(50, 160, 35));
        pane4.setBackground(new Color(50, 160, 35));
        
        mIt1.setText("New Game");
        mIt2.setText("Save Game");
        mIt3.setText("Load Game");
        mIt4.setText("Options");
        mIt5.setText("Exit");
        mIt6.setText("Rules");
        mIt7.setText("About");
        menu1.setText("Game");
        menu2.setText("Help");
        menu1.add(mIt1);
        menu1.add(mIt2);
        menu1.add(mIt3);
        menu1.add(mIt4);
        menu1.add(mIt5);
        menu2.add(mIt6);
        menu2.add(mIt7);
        menBar.add(menu1);
        menBar.add(menu2);
        this.setJMenuBar(menBar);
        
        this.add(pane1);
        this.add(pane2);
        this.add(pane4);
        
                   
        theheandler hendler = new theheandler();
        mIt1.addActionListener(hendler);
        mIt2.addActionListener(hendler);
        mIt3.addActionListener(hendler);
        mIt4.addActionListener(hendler);
        mIt5.addActionListener(hendler);
        mIt6.addActionListener(hendler);
        mIt7.addActionListener(hendler);
        b1.addActionListener(hendler);
        b2.addActionListener(hendler);
        b3.addActionListener(hendler);
        b4.addActionListener(hendler);
        bt.addActionListener(hendler);
        
        b1.setEnabled(false);
        b2.setEnabled(false);
        b3.setEnabled(false);
        b4.setEnabled(false);
        
        bet.setVisible(false);
        bt.setVisible(false);
    }    
   
    private class theheandler implements ActionListener{
    
        @Override
        public void actionPerformed(ActionEvent e) {
            
            if(e.getSource()==b1)
            {
                if(b1.getText().equalsIgnoreCase("CALL"))
                {
                    act = 3;
                }
                if(b1.getText().equalsIgnoreCase("CHECK"))
                {
                    act = 2;
                }
            }
            if(e.getSource()==b2)
            {
                if(b2.getText().equalsIgnoreCase("BET"))
                {
                    act = 5;
                }
                if(b2.getText().equalsIgnoreCase("RAISE"))
                {
                    act = 4;
                }
            }
            if(e.getSource()==b3)
            {
                if(b3.getText().equalsIgnoreCase("FOLD"))
                {
                    act = 1;
                }
            }
            if(e.getSource()==b4)
            {
                if(b4.getText().equalsIgnoreCase("ALL_IN"))
                {
                    act = 6;
                }
            }
            if(e.getSource()==bt)
            {
               act = -1;
            }
            if(e.getSource()==mIt1)
            {
               
            }
            if(e.getSource()==mIt2)
            {
               
            }
            if(e.getSource()==mIt3)
            {
               
            }
            if(e.getSource()==mIt4)
            {
               
            }
            if(e.getSource()==mIt5)
            {
               dispose();
            }
            if(e.getSource()==mIt6)
            {
               JOptionPane.showMessageDialog(null, "Rulles");
            }
            if(e.getSource()==mIt7)
            {
               
            }
        } //a_listener
    } //s_class
    
    public int action()
    {
        b1.setEnabled(true);
        b2.setEnabled(true);
        b3.setEnabled(true);
        b4.setEnabled(true);
        act = 0;
        while(true)
        {
            if(act!=0){
                b1.setEnabled(false);
                b2.setEnabled(false);
                b3.setEnabled(false);
                b4.setEnabled(false);
                return act;
            }
        }
    }
        
    public int _bet()
    {
        act = 0;
        bet.setVisible(true);
        bt.setVisible(true);
        while(true){
        if(act == -1){
            bet.setVisible(false);
            bt.setVisible(false);
        return new Integer(bet.getText());}
      }
    }
    
    public void removeBot(int number)
    {
      switch (number){
        case 1: {plim1.setIcon(new ImageIcon("src\\gui\\pic\\player_d.png"));
                plim1.repaint(); break;}
        case 2: {plim2.setIcon(new ImageIcon("src\\gui\\pic\\player_d.png"));
                plim2.repaint(); break;}
        case 3: {plim3.setIcon(new ImageIcon("src\\gui\\pic\\player_d.png"));
                plim3.repaint(); break;}
        case 4: {plim4.setIcon(new ImageIcon("src\\gui\\pic\\player_d.png"));
                plim4.repaint(); break;}
        case 5: {plim5.setIcon(new ImageIcon("src\\gui\\pic\\player_d.png"));
                plim5.repaint(); break;}
      }
    }
    
    public void botAction(Player pl, int a)
    {
        switch (pl.getId()){
            case 1: {
                switch(a){
                    case 1: pa1.setText("FOLD"); pa1.repaint(); break;
                    case 2: pa1.setText("CHECK"); pa1.repaint(); break;
                    case 3: pa1.setText("CALL"); pa1.repaint(); break;
                    case 4: pa1.setText("RISE"); pa1.repaint(); break;
                    case 5: pa1.setText("BET"); pa1.repaint(); break;
                    case 6: pa1.setText("ALLIN"); pa1.repaint(); break;    
                }
            break;}
            case 2:  {
                switch(a){
                    case 1: pa2.setText("FOLD"); pa2.repaint(); break;
                    case 2: pa2.setText("CHECK"); pa2.repaint(); break;
                    case 3: pa2.setText("CALL"); pa2.repaint(); break;
                    case 4: pa2.setText("RISE"); pa2.repaint(); break;
                    case 5: pa2.setText("BET"); pa2.repaint(); break;
                    case 6: pa2.setText("ALLIN"); pa2.repaint(); break;    
                }
            break;}
            case 3: {
                switch(a){
                    case 1: pa3.setText("FOLD"); pa3.repaint(); break;
                    case 2: pa3.setText("CHECK"); pa3.repaint(); break;
                    case 3: pa3.setText("CALL"); pa3.repaint(); break;
                    case 4: pa3.setText("RISE"); pa3.repaint(); break;
                    case 5: pa3.setText("BET"); pa3.repaint(); break;
                    case 6: pa3.setText("ALLIN"); pa3.repaint(); break;    
                }
            break;}
            case 4:  {
                switch(a){
                    case 1: pa4.setText("FOLD"); pa4.repaint(); break;
                    case 2: pa4.setText("CHECK"); pa4.repaint(); break;
                    case 3: pa4.setText("CALL"); pa4.repaint(); break;
                    case 4: pa4.setText("RISE"); pa4.repaint(); break;
                    case 5: pa4.setText("BET"); pa4.repaint(); break;
                    case 6: pa4.setText("ALLIN"); pa4.repaint(); break;    
                }
            break;}
            case 5:  {
                switch(a){
                    case 1: pa5.setText("FOLD"); pa5.repaint(); break;
                    case 2: pa5.setText("CHECK"); pa5.repaint(); break;
                    case 3: pa5.setText("CALL"); pa5.repaint(); break;
                    case 4: pa5.setText("RISE"); pa5.repaint(); break;
                    case 5: pa5.setText("BET"); pa5.repaint(); break;
                    case 6: pa5.setText("ALLIN"); pa5.repaint(); break;    
                }
            break;}
            default: break;
        }
    }    
    
    public void setStack(Player pl)/////////////////////////////////////////////
    {
        switch (pl.getId()){
            case 0: {stack.setText(("Stack: " +pl.getStack())); stack.repaint(); break;}
            case 1: {bank1.setText(("Stack: " +pl.getStack())); bank1.repaint(); break;}
            case 2: {bank2.setText(("Stack: " +pl.getStack())); bank2.repaint(); break;}
            case 3: {bank3.setText(("Stack: " +pl.getStack())); bank3.repaint(); break;}
            case 4: {bank4.setText(("Stack: " +pl.getStack())); bank4.repaint(); break;}
            case 5: {bank5.setText(("Stack: " +pl.getStack())); bank5.repaint(); break;}
        }
    }
    
    public void newRaund()
    {              
        cp1.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        cp2.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        c1.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        c2.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        c3.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        c4.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        c5.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\back.png"));
        cp1.repaint();
        cp2.repaint();
        c1.repaint();
        c2.repaint();
        c3.repaint();
        c4.repaint();
        c5.repaint();
    }
    
    public void setPot(int p)
    {
      pot.setText(("POT: " +p));
      pot.repaint();
    }
    
    public void addFlopCards(Card cd1, Card cd2, Card cd3)
    {
      setCardIm(cd1, c1);
      setCardIm(cd2, c2);
      setCardIm(cd3, c3);
      c1.repaint();
      c2.repaint();
      c3.repaint();
    }
    
    public void addTurnCard(Card cd4)
    {
      setCardIm(cd4, c4);
      c4.repaint();
    }
    
    public void addRiverCard(Card cd5)
    {
      setCardIm(cd5, c5);
      c5.repaint();
    }
    
    public void addPlayerCard(Card cd1, Card cd2)
    {
      setCardIm(cd1, cp1);
      setCardIm(cd2, cp2);
      cp1.repaint();
      cp2.repaint();
    }
       
    public void setStat(Player pl, int n)
    {
      switch (n){
        case 0: {
          switch (new Integer(pl.getId())){
            case 0:  {stp.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            stp.repaint(); break;}
            case 1:  {st1.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            st1.repaint(); break;}
            case 2:  {st2.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            st2.repaint(); break;}
            case 3:  {st3.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            st3.repaint(); break;}
            case 4:  {st4.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            st4.repaint(); break;}
            case 5:  {st5.setIcon(new ImageIcon("src\\gui\\pic\\Status\\D.png"));
            st5.repaint(); break;}
            }break;}
        case 1: {switch (new Integer(pl.getId())){
            case 0:  {stp.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            stp.repaint(); break;}
            case 1:  {st1.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            st1.repaint(); break;}
            case 2:  {st2.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            st2.repaint(); break;}
            case 3:  {st3.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            st3.repaint(); break;}
            case 4:  {st4.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            st4.repaint(); break;}
            case 5:  {st5.setIcon(new ImageIcon("src\\gui\\pic\\Status\\SB.png"));
            st5.repaint(); break;}
            }break;}
        case 2: {switch (new Integer(pl.getId())){
            case 0:  {stp.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            stp.repaint(); break;}
            case 1:  {st1.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            st1.repaint(); break;}
            case 2:  {st2.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            st2.repaint(); break;}
            case 3:  {st3.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            st3.repaint(); break;}
            case 4:  {st4.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            st4.repaint(); break;}
            case 5:  {st5.setIcon(new ImageIcon("src\\gui\\pic\\Status\\BB.png"));
            st5.repaint(); break;}
            }break;}
        default: {switch (new Integer(pl.getId())){
            case 0:  {stp.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            stp.repaint(); break;}
            case 1:  {st1.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            st1.repaint(); break;}
            case 2:  {st2.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            st2.repaint(); break;}
            case 3:  {st3.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            st3.repaint(); break;}
            case 4:  {st4.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            st4.repaint(); break;}
            case 5:  {st5.setIcon(new ImageIcon("src\\gui\\pic\\Status\\EM.png"));
            st5.repaint(); break;}
            }break;}
       }
    }
    
    public void estSetBut(int s)
    {
        if(s==1){
        b1.setText("CALL");
        b2.setText("RAISE");
        b1.repaint();
        b2.repaint();
        }
        if(s==2){
        b1.setText("CHECK");
        b2.setText("BET");
        b1.repaint();
        b2.repaint();
        }
    }        
    
    public void setCardIm(Card c, JLabel l)
    {
        switch(c.getSuit()){
                case 0:
                {
                    switch(c.getRank()){
                        case 0:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\HA.png"));
                          break;}
                        case 1:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H2.png"));
                          break;}
                        case 2:{l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H3.png"));
                          break;}
                        case 3:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H4.png"));
                          break;}
                        case 4:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H5.png"));
                          break;}
                        case 5:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H6.png"));
                          break;}
                        case 6:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H7.png"));
                          break;}
                        case 7:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H8.png"));
                          break;}
                        case 8:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H9.png"));
                          break;}
                        case 9:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\H10.png"));
                          break;}
                        case 10:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\HJ.png"));
                          break;}
                        case 11:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\HQ.png"));
                          break;}
                        case 12:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\HK.png"));
                          break;}
                    }
                    break;
                }
                case 1:
                {
                    switch(c.getRank()){
                        case 0:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\SA.png"));
                          break;}
                        case 1:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S2.png"));
                          break;}
                        case 2:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S3.png"));
                          break;}
                        case 3:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S4.png"));
                          break;}
                        case 4:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S5.png"));
                          break;}
                        case 5:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S6.png"));
                          break;}
                        case 6:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S7.png"));
                          break;}
                        case 7:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S8.png"));
                          break;}
                        case 8:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S9.png"));
                          break;}
                        case 9:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\S10.png"));
                          break;}
                        case 10:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\SJ.png"));
                          break;}
                        case 11:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\SQ.png"));
                          break;}
                        case 12:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\SK.png"));
                          break;}
                    }
                    break;
                }
                case 2:
                {
                    switch(c.getRank()){
                        case 0:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\DA.png"));
                          break;}
                        case 1:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D2.png"));
                          break;}
                        case 2:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D3.png"));
                          break;}
                        case 3:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D4.png"));
                          break;}
                        case 4:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D5.png"));
                          break;}
                        case 5:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D6.png"));
                          break;}
                        case 6:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D7.png"));
                          break;}
                        case 7:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D8.png"));
                          break;}
                        case 8:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D9.png"));
                          break;}
                        case 9:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\D10.png"));
                          break;}
                        case 10:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\DJ.png"));
                          break;}
                        case 11:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\DQ.png"));
                          break;}
                        case 12:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\DK.png"));
                          break;}
                    }
                    break;
                }
                case 3:
                {
                    switch(c.getRank()){
                        case 0:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\CA.png"));
                          break;}
                        case 1:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C2.png"));
                          break;}
                        case 2:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C3.png"));
                          break;}
                        case 3:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C4.png"));
                          break;}
                        case 4:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C5.png"));
                          break;}
                        case 5:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C6.png"));
                          break;}
                        case 6:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C7.png"));
                          break;}
                        case 7:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C8.png"));
                          break;}
                        case 8:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C9.png"));
                          break;}
                        case 9:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\C10.png"));
                          break;}
                        case 10:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\CJ.png"));
                          break;}
                        case 11:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\CQ.png"));
                          break;}
                        case 12:{ l.setIcon(new ImageIcon("src\\gui\\pic\\Cards\\CK.png"));
                          break;}
                    }
                    break;
                }
        }
    }
    
} //m_class
