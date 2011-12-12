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
}
