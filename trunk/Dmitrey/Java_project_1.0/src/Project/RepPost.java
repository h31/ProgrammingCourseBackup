package Project;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import java.util.*;
import java.io.*;

public class RepPost {
  
    protected ArrayList<Post> pst = new ArrayList();
    
    public int getSize()
    {
        return pst.size();
    }
    public void addNewPost()
    {
       
       Post CurPst = new Post();
       CurPst.setName();
       CurPst.setDescr();
       CurPst.setSalary();
       pst.add(CurPst);
       System.out.println("size is " +pst.size());
    }
    public void deletePost()
    {
      Scanner ConsIn = new Scanner(System.in);
      System.out.println("Input name: ");
      int ndx = pst.indexOf(this.findPost(ConsIn.next()));
      if(ndx >= 0){
        pst.remove(ndx); //??????!
      }
      System.out.println("The post has deleted.");
    }
    public void showPost()
    {
      for(int i = 0; i<pst.size(); i++)
         {
           System.out.println("\n");
           pst.get(i).showPost();
           System.out.println("\n");
         }   
    }
    public Post findPost(String name)
    {
        for(int i=0; i<pst.size(); i++)
            {
                if(pst.get(i).getName().equals(name))
                    return pst.get(i);
            }
        System.out.println("Post not found");
         return (new Post());
      }
    
    public  void Parcer(File in) {
	  try {
 
        	SAXParserFactory factory = SAXParserFactory.newInstance();
                SAXParser saxParser = factory.newSAXParser();
             
                DefaultHandler P = new DefaultHandler() {
                String thisElement = new String();
                Post CurP = new Post();
                
  
                @Override
                public void startElement(String uri, String localName,String qName, 
                Attributes attributes) throws SAXException {
                  thisElement = qName;
                }

                @Override
                public void endElement(String uri, String localName,String qName) throws SAXException {
                      if(qName.equalsIgnoreCase("POST"))
                      {                        
                        pst.add(CurP);
                        CurP = new Post();
                      }
                      thisElement = "";
                     
                      
                   }
                

                @Override
                public void characters(char ch[], int start, int length) throws SAXException {
                   
                  if(thisElement.equalsIgnoreCase("NAME"))
                  {CurP.setName(new String(ch, start, length));}
                  
                  if(thisElement.equalsIgnoreCase("DESCR"))
                  {CurP.setDescr(new String(ch, start, length));}
                  
                  if(thisElement.equalsIgnoreCase("SALARY"))
                  {CurP.setSalary(new Integer(new String(ch, start, length)));}
                }
        };
                saxParser.parse(in, P);
                
             }
          catch (Exception e) {
             }
    }
    
    public void XMLOutputter(File f) throws IOException
       {
         FileOutputStream out = new FileOutputStream(f);
         out.write(new String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<start>\n").getBytes());
         for(int i = 0; i<pst.size(); i++)
         {        
            out.write(new String(" <post>\n").getBytes());
            out.write(new String("  <name>").getBytes());
            out.write(pst.get(i).getName().getBytes());
            out.write(new String("</name>\n").getBytes());
            out.write(new String("  <descr>").getBytes());
            out.write(pst.get(i).getDescr().getBytes());
            out.write(new String("</descr>\n").getBytes());
            out.write(new String("  <salary>").getBytes());
            out.write(Integer.toString(pst.get(i).getSalary()).getBytes());
            out.write(new String("</salary>\n").getBytes());
            out.write(new String(" </post>\n").getBytes()); 
          }
         out.write(new String("</start>").getBytes());
       }
}
