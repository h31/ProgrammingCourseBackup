package Project;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import java.util.*;
import java.io.*;

public class RepTask {
  
  private ArrayList<Task> tas = new ArrayList();
  private String thisElement = "";
  private Task CurT = new Task();
  private Date dat = new Date();
  
  public int getSize()
  {
    return tas.size();
  }
  public void addNewTask()
  {
    Scanner ConsIn = new Scanner(System.in);
    Task CurTsk = new Task();
    System.out.print("input id: ");
    CurTsk.setId(ConsIn.nextInt());
    System.out.print("input description: ");
    CurTsk.setDescr(ConsIn.next());
    System.out.print("input time: ");
    CurTsk.setTime(ConsIn.nextInt());
    System.out.print("input money: ");
    CurTsk.setMoney(ConsIn.nextInt());
    System.out.print("input date(d m y): ");
    Date d = new Date();
    d.read();
    CurTsk.setSinceDate(d);
    tas.add(CurTsk);
  }
  
  public void deleteTask()
  {
      Scanner ConsIn = new Scanner(System.in);
      System.out.println("Input taskid: ");
      int ndx = tas.indexOf(this.findTask(ConsIn.nextInt()));
      if(ndx >= 0){
        tas.remove(ndx); //??????!
      }
      System.out.println("the task has deleted.");
  }
  
  public Task findTask(int id)
  {
    for(int i=0; i<tas.size(); i++)
            {
                if(tas.get(i).getId()==id){
                  return tas.get(i);
               }
             }
        System.out.println("Task not found");
         return (new Task());
  }
  
  public void showTasks()
  {
    for(int i = 0; i<tas.size(); i++)
       {
         System.out.println('{');
         tas.get(i).showTask();
         System.out.println('}');
       }   
  }
  
  public  void Parcer(File in) {
	  try {
 
        	SAXParserFactory factory = SAXParserFactory.newInstance();
                SAXParser saxParser = factory.newSAXParser();
                
        	DefaultHandler _T = new DefaultHandler() {
  
        @Override
                public void startElement(String uri, String localName,String qName, 
                Attributes attributes) throws SAXException {
                  thisElement = qName;
                 }

        @Override
                public void endElement(String uri, String localName,String qName) throws SAXException {
                      if(qName.equalsIgnoreCase("TASK"))
                      {
                        CurT.setSinceDate(dat);
                        tas.add(CurT);
                        CurT = new Task();
                      }
                      thisElement = "";
                }

        @Override
                public void characters(char ch[], int start, int length) throws SAXException {
                      if(thisElement.equalsIgnoreCase("TASK"))
                      {
                        /////////////
                      }
                      if(thisElement.equalsIgnoreCase("ID"))
                      {
                        CurT.setId(new Integer(new String(ch, start, length)));
                      }
                      if(thisElement.equalsIgnoreCase("DESCR"))
                      {
                        CurT.setDescr(new String(ch, start, length));
                      }
                      if(thisElement.equalsIgnoreCase("TIME"))
                      {
                        CurT.setTime(new Integer(new String(ch, start, length)));
                      }
                      if(thisElement.equalsIgnoreCase("MONEY"))
                      {
                        CurT.setMoney(new Integer(new String(ch, start, length)));
                      }
                      if(thisElement.equalsIgnoreCase("DATE"))
                      {
                          ///////////
                      }
                      if(thisElement.equalsIgnoreCase("DAY"))
                      {
                          dat.setDay(new Integer(new String(ch, start, length)));
                      }
                      if(thisElement.equalsIgnoreCase("MONTH"))
                      {
                          dat.setMonth(new Integer(new String(ch, start, length)));
                      }
                      if(thisElement.equalsIgnoreCase("YEAR"))
                      {
                          dat.setYear(new Integer(new String(ch, start, length)));
                      }
                }       
              };
                saxParser.parse(in, _T);
               }
          catch (Exception e) {
                 //e.printStackTrace();
             }

           }
  
  public void XMLOutputter(File f) throws IOException
       {
         FileOutputStream out = new FileOutputStream(f);
         out.write(new String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<start>\n").getBytes());
         for(int i = 0; i<tas.size(); i++)
         {          
            out.write(new String("<task>\n").getBytes());
            out.write(new String(" <id>").getBytes());
            out.write(Integer.toString(tas.get(i).getId()).getBytes());
            out.write(new String("</id>\n").getBytes());
            out.write(new String(" <descr>").getBytes());
            out.write(tas.get(i).getDescr().getBytes());
            out.write(new String("</descr>\n").getBytes());
            out.write(new String(" <time>").getBytes());
            out.write(Integer.toString(tas.get(i).getTime()).getBytes());
            out.write(new String("</time>\n").getBytes());
            out.write(new String(" <money>").getBytes());
            out.write(Integer.toString(tas.get(i).getMon()).getBytes());
            out.write(new String("</money>\n").getBytes());
            out.write(new String(" <date>\n").getBytes());
            out.write(new String("  <day>").getBytes());
            out.write(Integer.toString(tas.get(i).getSinceDate().getDay()).getBytes());
            out.write(new String("</day>\n").getBytes());
            out.write(new String("  <month>").getBytes());
            out.write(Integer.toString(tas.get(i).getSinceDate().getMonth()).getBytes());
            out.write(new String("</month>\n").getBytes());
            out.write(new String("  <year>").getBytes());
            out.write(Integer.toString(tas.get(i).getSinceDate().getYear()).getBytes());
            out.write(new String("</year>\n").getBytes());
            out.write(new String(" </date>\n").getBytes());  
            out.write(new String("</task>\n").getBytes());
          }
          out.write(new String("</start>").getBytes());
       }
}
