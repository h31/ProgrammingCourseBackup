/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package minesweeper.datahandle;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Iterator;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.output.XMLOutputter;

/**
 *
 * @author RemiX
 */
public class DataWriter {

    private String fileName = DataLoader.fileName;
    private User newUser;
    public DataWriter(User user){
        newUser = user;
    }

    public void write(){
        List<User> list = new DataLoader().parse();
        list.add(newUser);
        Document doc = createDocument(list);
        saveDocument(doc);
    }

    public Document createDocument(List<User> usersList) {
        Element root = new Element("root");
        Iterator<User> iter = usersList.iterator();
        while (iter.hasNext()) {
            User currentUser = iter.next();
            Element userElement = new Element("user");
            userElement.setAttribute("name", currentUser.getName());
            userElement.setAttribute("level", currentUser.getLevel());
            userElement.setAttribute("time", String.valueOf(currentUser.getTime()));
            root.addContent(userElement);
        }
        return new Document(root);
    }

    public void saveDocument(Document doc) {
        XMLOutputter outputter = new XMLOutputter();
        try {
            outputter.output(doc, new FileOutputStream(fileName));

        } catch (Exception ex) {
            Logger.getLogger(DataWriter.class.getName()).log(Level.SEVERE, null, ex);
        }


    }
}
