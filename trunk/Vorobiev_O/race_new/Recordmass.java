
package race;

import java.io.File;
import java.util.List;

import java.util.logging.Level;
import java.util.logging.Logger;
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

public class Recordmass 
{
    private int mass[]=new int[5];
    
    public Recordmass()
    {
        File file = new File("Records.xml");
        try {
            readXML(file);
        } catch (JDOMException ex) {
            Logger.getLogger(Recordmass.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Recordmass.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        sort_mass();
        
    }
    
     int get_element(int index)
    {
        return mass[index];
    }
    
    public void writeXML(final File file) 
    {
        final Element root = new Element("root");
        final Element scoreroot = new Element("score");
        final List<Element> scorearray = new LinkedList<Element>();
        
        final Element massscore = new Element("sc");
        
        for(int i=0;i<mass.length;i++)
        {
            scorearray.add(massscore.setAttribute("score" + String.valueOf(i), String.valueOf(mass[i])));            
        }
        
        scoreroot.setContent(scorearray);
        root.addContent(scoreroot);
        
        final Document document = new Document(root);
        final XMLOutputter outputter = new XMLOutputter();
        try {
            outputter.output(document, new FileOutputStream(file));
        } catch (IOException ex) {
            Logger.getLogger(Recordmass.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
    public void readXML(final File file) throws JDOMException, IOException 
    {
        final SAXBuilder builder = new SAXBuilder();
        final Document document = builder.build(file);
        final Element root = document.getRootElement();
        final Element citiesRoot = root.getChild("score");
        for (int i =0;i<mass.length;i++) 
        {
            mass[i] = Integer.parseInt(citiesRoot.getAttributeValue("score" + String.valueOf(i)));
            
        }
    }
    
    
    
    void sort_mass()
    {
        int val=0;
        for(int i=0;i<mass.length-1;i++)
        {
            for(int j=i;j<mass.length;j++)
                if(mass[i]<mass[j]) 
                {
                    val=mass[i];
                    mass[i]=mass[j];
                    mass[j]=val;
                }
        }
    }
    
    void add_record(int score)
    {
        for(int i:mass)
        {
            if(mass[i]<score)
            {
                for(int j=mass.length-1;j>i-1;j--)
                {
                    mass[j]=mass[j-1];
                }
                mass[i]=score;
            }
        }
    }
    
    
}
