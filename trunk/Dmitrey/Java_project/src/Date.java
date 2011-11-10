import java.io.*;
import java.util.Calendar;

class Date {
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
	System.out.print("Current date: ");
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
}

























