package Project;

import java.io.*;

class Task {
	private String descr;
        private int id;
	private int time;
	private int money;
	private Date since;
		
	public Task(){
                        id=0000;
			descr="emp";
			time=0;
			money=0;
			since = new Date();
		}
	public int dayleft(){
			Date cd = new Date();
			return (cd.convertionDate()-since.convertionDate());
		}
			
	public int dayleft(Date CurDate){
			return (CurDate.convertionDate()-since.convertionDate());
		}
	
	public void showTask(){
                        System.out.println("Id of task: " +id);
                        System.out.println("Description of task: " +descr);
			System.out.println("Time of task: " +time);
                        System.out.println("Price of task: " +money);
                        System.out.print("Since date of task: ");
                        since.showDate();
                        
		}
	
	public boolean check(Date curDate){
			if((curDate.convertionDate()-since.convertionDate())>time)
			{return true;}
			else
			{return false;}
		}
	
	public void setSinceDate(Date dat)
        {
          since.setDate(dat);
	}
	public void setId(int id)
        {
          this.id = id;
        }
        public void setDescr(String descr)
        {
          this.descr = descr;
        }
        public void setTime(int time)
        {
          this.time = time;
        }
        public void setMoney(int money)
        {
          this.money = money;
        }
   
        public int getId()
        {
          return id;
        }
	public int getMon(){
		return money;
	} 
	public Date getSinceDate(){
		return since;
	}
        public String getDescr()
        {
            return descr;
        }
        public int getTime()
        {
            return time;
        }
        public void equat(Task tsk)
        {
            id = tsk.id;
            descr = tsk.descr;
            time = tsk.time;
            money = tsk.money;
            since.setDate(tsk.since);
        }
        public boolean equals(Task ob)
        {
          return (id == ob.getId());
        }
}
