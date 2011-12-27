package Project;

class Task {
	private String descr;
        private int id;
	private int time;
	private int money;
	private Date since;
        private boolean done;
		
	public Task(){
                        done=false;
                        id=0000;
			descr="emp";
			time=0;
			money=0;
			since = new Date();
		}
	public void showTask(){
                        System.out.println("Status done: " +done);
                        System.out.println("(Id of task: " +id);
                        System.out.println("(Description of task: " +descr);
			System.out.println("(Time of task: " +time);
                        System.out.println("(Price of task: " +money);
                        System.out.print("(Since date of task: ");
                        since.showDate();
                        
		}
	
	public void setDone(Date curDate)
        {
          done=((curDate.convertionDate()-since.convertionDate())>time);
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
        public void setStatus(int mark)
        {
          if(mark!=0) done=true;
          else{done=false;}
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
        public int getStatus()
        {
          if(done) return 1;
          return 0;
        }
        public void equat(Task tsk)
        {
            done = tsk.done;
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
