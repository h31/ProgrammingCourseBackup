
package race;


import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.io.File;
import java.util.List;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import java.util.*;
import java.io.*;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;
import org.jdom.output.XMLOutputter;

public class RecordList extends JFrame
{
    
    Recordmass r_mass;
    int mass[]= new int [5];
    String s;
    
    RecordList(String s,int score) 
    {
        super(s);
        int x=150,y=250;
        setBounds(320,150,x,y);
        
        setLayout(null);
        setResizable(false);
        
        r_mass=new Recordmass();
        r_mass.add_record(score);
        
        JLabel text = new JLabel("Records");
        text.setBounds(x/2-40,1, 80, 40);
        add(text);
        
        s="1. "+String.valueOf(r_mass.get_element(0));
        JLabel rec1 = new JLabel(s);
        rec1.setBounds(x/2-40,y-220, 80, 40);
        add(rec1);
        
        s="2. "+String.valueOf(r_mass.get_element(1));
        JLabel rec2 = new JLabel(s);
        rec2.setBounds(x/2-40,y-200, 80, 40);
        add(rec2);
        
        s="3. "+String.valueOf(r_mass.get_element(2));
        JLabel rec3 = new JLabel(s);
        rec3.setBounds(x/2-40,y-180, 80, 40);
        add(rec3);
        
        s="4. "+String.valueOf(r_mass.get_element(3));
        JLabel rec4 = new JLabel(s);
        rec4.setBounds(x/2-40,y-160, 80, 40);
        add(rec4);
        
        s="5. "+String.valueOf(r_mass.get_element(4));
        JLabel rec5 = new JLabel(s);
        rec5.setBounds(x/2-40,y-140, 80, 40);
        add(rec5);
        
        JButton exitButton = new JButton("Exit to Windows");
        exitButton.setBounds(x/2-73, y-100, 140, 20);
        exitButton.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e) 
            {
                System.exit(0);
            }
        });
        add(exitButton);
        
        //writeXML(file);
        
        setVisible(true);
        
        setDefaultCloseOperation(JFrame.ABORT);        
    }
    
    
}

