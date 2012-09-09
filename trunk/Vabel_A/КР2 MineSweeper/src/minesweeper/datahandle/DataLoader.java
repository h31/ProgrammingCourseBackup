/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package minesweeper.datahandle;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.XMLReaderFactory;

/**
 *
 * @author RemiX
 */
public class DataLoader {
    public static String fileName="src/resources/data.xml";
    public List<User> parse() {
        File file=new File(fileName);
        try {
            XMLReader reader;
            SAXParserFactory factory = SAXParserFactory.newInstance();
            SAXParser saxParser = factory.newSAXParser();
            SAXDataHandler handler = new SAXDataHandler();
            saxParser.parse(file, handler);
            List<User> list= handler.getList();
            return list;
        } catch (IOException ex) {
            Logger.getLogger(DataLoader.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        } catch (ParserConfigurationException ex) {
            Logger.getLogger(DataLoader.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        } catch (SAXException ex) {
            Logger.getLogger(DataLoader.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }

    public List<User> getSortedList(String level){
        List<User> list = parse();
        List<User> temp = new ArrayList<User>();
        for(User user:list){
            if(user.getLevel().equals(level)){
                temp.add(user);
            }
        }
        Collections.sort(temp);
        return temp;
    }
}
