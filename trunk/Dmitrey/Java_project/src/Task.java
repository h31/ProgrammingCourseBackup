import java.io.*;

class task{
private int descr;
private int time;
private int money;
private Date since;
	
public void task(){
		descr=descr;
		time=time;
		money=money;
		since=since;
	}

public void task(int t, int d, int m){
		descr=d;
		time=t;
		money=m;
		since=since;
	}

public void show(){
		System.out.println("Description of task: " +descr);
		System.out.println("Time of task: " +time);
	}

public boolean check(Date curDate){
		if((curDate.convertionDate()-since.convertionDate())>time)
		{return true;}
		else
		{return false;}
	}

public void setBeginDate(Date dat){
		since.setDate(dat);
	}
}