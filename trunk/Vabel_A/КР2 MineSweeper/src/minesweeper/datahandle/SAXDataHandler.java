/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package minesweeper.datahandle;

import java.util.ArrayList;
import java.util.List;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;

/**
 *
 * @author RemiX
 */
public class SAXDataHandler extends DefaultHandler {

    private List<User> usersList = new ArrayList<User>();
    private String currentElement;

    public List<User> getList() {
        return usersList;
    }

    public void startElement(String uri, String localName, String qName, Attributes attrs) {
        currentElement = qName;
        if ("user".equals(currentElement)) {
             String name = attrs.getValue("name");
             String level = attrs.getValue("level");
             int time= Integer.valueOf(attrs.getValue("time"));
             usersList.add(new User(name, level, time));
        }
    }


    public void endElement(String uri, String localName, String qName) {
    }

    public void characters(char[] ch, int start, int length) {
    }
}
