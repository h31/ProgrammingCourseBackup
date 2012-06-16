/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package railway.datahandle;

import railway.datahandle.SAXDataHandler;
import java.io.File;
import java.io.IOException;
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
import railway.model.RailwayStation;

/**
 *
 * @author RemiX
 */
public class DataLoader {

    public static List<RailwayStation> parse(File file) {
        try {
            XMLReader reader;
            SAXParserFactory factory = SAXParserFactory.newInstance();
            SAXParser saxParser = factory.newSAXParser();
            SAXDataHandler handler = new SAXDataHandler();
            saxParser.parse(file, handler);
            List<RailwayStation> list= handler.getRailwayStationList();
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
}
