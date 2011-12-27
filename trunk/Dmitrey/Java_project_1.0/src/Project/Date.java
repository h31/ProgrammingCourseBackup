package Project;

import java.io.*;
import java.util.*;

public class Date{
	
	private int day;
	private int month;
	private int year;
	
	public Date(){
			Calendar calendar=Calendar.getInstance();
			day=calendar.get(Calendar.DATE);
			month=calendar.get(Calendar.MONTH);
			year=calendar.get(Calendar.YEAR);
		}
	
	public void setDate(int d, int m, int y){
			day=d;
			month=m;
			year=y;
		}
	public void setDate(Date dat){
			day=dat.day;
			month=dat.month;
			year=dat.year;	
		}
	
	public void showDate(){
		System.out.print(+day);
		System.out.print(".");
		System.out.print(+month);
		System.out.print(".");
		System.out.println(+year);
                }
	
	public int convertionDate(){
			return (356*year+30*month+day);
		}
	public boolean after(Date d){
			if(this.convertionDate()>d.convertionDate())
				{return true;}
			else
				{return false;}
		}
	public boolean equally(Date d){
			
                if(this.convertionDate()==d.convertionDate())
			{return true;}
		else
			{return false;}
		}
	
	public void read()
        {
	                Scanner in = new Scanner(System.in);
			day = in.nextInt();
			month = in.nextInt();
			year = in.nextInt();
		}
	public void write(FileOutputStream out) throws IOException {
		
                out.write(day);
		out.write(month);
		out.write(year);
	}
	public void write() throws IOException {
		
                System.out.print(day);
		System.out.print(".");
		System.out.print(month);
		System.out.print(".");
		System.out.println(year);
	}
        public void setDay(int d)
        {day = d;}
        public void setMonth(int m)
        {month = m;}
        public void setYear(int y)
        {year = y;}
        
        public int getDay()
        {
          return day;
        }
        public int getMonth()
        {
          return month;
        }
        public int getYear()
        {
          return year;
        }
        
        public boolean lastDayOfMonth()
        {
//            if(((month==1  ||
//                 month==3  ||
//                 month==5  ||
//                 month==7  ||   
//                 month==8  ||   
//                 month==10 ||   
//                 month==12)
//                 && day==31)   || 
//
//                (month==2 
//                 && day==28)   || 
//
//               ((month==4 ||
//                 month==6 ||
//                 month==9 ||
//                 month==11)  
//                 && day==30))
//              
//            return true;
//            else
//            {return false;}
          if(month==1 && day==31) return true;
          if(month==2 && day==28) return true;
          if(month==3 && day==31) return true;
          if(month==4 && day==30) return true;
          if(month==5 && day==31) return true;
          if(month==6 && day==30) return true;
          if(month==7 && day==31) return true;
          if(month==8 && day==31) return true;
          if(month==9 && day==30) return true;
          if(month==10 && day==31) return true;
          if(month==11 && day==30) return true;
          if(month==12 && day==31) return true;
          return false;
          }
        public boolean equals(Date ob)
        {
          return(day==ob.day && month==ob.month && year==ob.year);
        }
}
