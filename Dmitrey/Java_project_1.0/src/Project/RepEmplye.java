package Project;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import java.util.*;
import java.io.*;

public class RepEmplye {
	//Variables	
	private ArrayList<Emplye> empl = new ArrayList();
        private String thisElement = "";
        private Emplye CurE = new Emplye();
        private Date dat = new Date();
        //Methods	
	public void addNewEmp(RepPost RPst, RepTask RTsk)
	{
            Scanner ConsIn = new Scanner(System.in);
                Emplye CurEmp = new Emplye();
                CurEmp.setName();
		System.out.println("Input postname: ");
                CurEmp.setPost(RPst.findPost(ConsIn.next()));
                System.out.println("Input task(id): ");
                CurEmp.setTask(RTsk.findTask(ConsIn.nextInt()));
                empl.add(CurEmp);
         }
            
        
        public void deleteEmplye()
        {
            Scanner ConsIn = new Scanner(System.in);             
		String name = new String();
                String surname = new String();
                System.out.println("Input name and surname ");
                int ndx = empl.indexOf(this.findEmplye(ConsIn.next(), ConsIn.next()));
                if(ndx >= 0){
                  empl.remove(ndx); //??????!
                }
                empl.remove(empl.indexOf(this.findEmplye(name, surname))); //??????!
                System.out.println("the employee has deleted.");
                
        }
        public void refreshSal(Date CurDate)
        {
            for(int i=0; i<empl.size(); i++)
            {
                empl.get(i).chargeMon(CurDate);
            }
        }
        
      public Emplye findEmplye(String name, String surname)
      {
        for(int i=0; i<empl.size(); i++)
            {
                if(empl.get(i).getName().equals(name)){
                  if(empl.get(i).getSurname().equals(surname)){
                    return empl.get(i);
                  }
                }
             }
        System.out.println("Emplyee not found");
         return (new Emplye());
         
     }
      
     public void showEmployees()
     {
       for(int i = 0; i<empl.size(); i++)
       {
         System.out.println('{');
         empl.get(i).showEmloyee();
         System.out.println('}');
       }   
     }
     
     public void setTask(RepTask RTsk)
     {
         Scanner ConsIn = new Scanner(System.in);
       String name = new String();
       String surname = new String();
       int id = 0;
       System.out.print("Input name: ");
       ConsIn.next(name);
       System.out.print("Input surname: ");
       ConsIn.next(surname);
       System.out.print("Input task id: ");
       ConsIn.nextInt(id);
       this.findEmplye(name, surname).setTask(RTsk.findTask(id));
      }
     
  
       public  void Parcer(File in, final RepPost RPst, final RepTask RTsk) {
	  try {
 
        	SAXParserFactory factory = SAXParserFactory.newInstance();
                SAXParser saxParser = factory.newSAXParser();
             
                DefaultHandler _E = new DefaultHandler() {
  
        @Override
                public void startElement(String uri, String localName,String qName, 
                
                        Attributes attributes) throws SAXException {
                thisElement = qName;
                }

        @Override
                public void endElement(String uri, String localName,String qName) throws SAXException {
                      if(qName.equalsIgnoreCase("EMPLOYEE"))
                      {
                        CurE.setLstCh(dat);
                        empl.add(CurE);
                        CurE = new Emplye();
                      }
                      thisElement = "";
                }

        @Override
                public void characters(char ch[], int start, int length) throws SAXException {

                  if(thisElement.equalsIgnoreCase("NAME"))
                      {
                          CurE.setName(new String(ch, start, length));
                      }
                  if(thisElement.equalsIgnoreCase("SURNAME"))
                      {
                          CurE.setSurname(new String(ch, start, length));
                      }
                  if(thisElement.equalsIgnoreCase("POSTNAME"))
                      {
                          CurE.setPost(RPst.findPost(new String(ch, start, length)));
                      }
                  if(thisElement.equalsIgnoreCase("ACCOUNT"))
                      {
                          CurE.setAcc(new Integer(new String(ch, start, length)));
                      }
                  if(thisElement.equalsIgnoreCase("TASKID"))
                      {
                          CurE.setTask(RTsk.findTask(new Integer(new String(ch, start, length))));
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
            saxParser.parse(in, _E);
          }
          catch (Exception e) {
                
             }
       }
       
       public void XMLOutputter(File f) throws IOException
       {
         FileOutputStream out = new FileOutputStream(f);
         out.write(new String("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<start>\n").getBytes());
         for(int i = 0; i<empl.size(); i++)
         { 
            out.write(new String("<employee>\n").getBytes());
            out.write(new String(" <name>").getBytes());
            out.write(new String(empl.get(i).getName()).getBytes());
            out.write(new String("</name>\n").getBytes());
            out.write(new String(" <surname>").getBytes());
            out.write(new String(empl.get(i).getSurname()).getBytes());
            out.write(new String("</surname>\n").getBytes());
            out.write(new String(" <postname>").getBytes());
            out.write(new String(empl.get(i).getPostName()).getBytes());
            out.write(new String("</postname>\n").getBytes());
            out.write(new String(" <account>").getBytes());
            out.write(new String(Integer.toString(empl.get(i).getAcc())).getBytes());
            out.write(new String("</account>\n").getBytes());
            out.write(new String(" <taskid>").getBytes());
            out.write(new String(Integer.toString(empl.get(i).getTaskId())).getBytes());
            out.write(new String("</taskid>\n").getBytes());
            out.write(new String(" <lastcharg>\n").getBytes());
            out.write(new String("  <day>").getBytes());
            out.write(new String(Integer.toString(empl.get(i).getLstCh().getDay())).getBytes());
            out.write(new String("</day>\n").getBytes());
            out.write(new String("  <month>").getBytes());
            out.write(new String(Integer.toString(empl.get(i).getLstCh().getMonth())).getBytes());
            out.write(new String("</month>\n").getBytes());
            out.write(new String("  <year>").getBytes());
            out.write(new String(Integer.toString(empl.get(i).getLstCh().getYear())).getBytes());
            out.write(new String("</year>\n").getBytes());
            out.write(new String(" </lastcharg>\n").getBytes());
            out.write(new String("</employee>\n").getBytes());
         }
         
         out.write(new String("</start>\n").getBytes());
       }
       
}
