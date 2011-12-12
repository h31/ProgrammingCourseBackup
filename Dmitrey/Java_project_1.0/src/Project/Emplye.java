package Project;

import java.util.*;

public class Emplye {
//Variables	
	private String name, surname;
	private Post post;
	private int account;
	private Task tsk;
	private Date lstCharg;
//Methods
       public Emplye()
	{
		name="emp";
		surname="emp";
		post = new Post();
		account=0;
		tsk = new Task();
		lstCharg = new Date();
	}
       public void setName()
	{
		Scanner ConIn = new Scanner(System.in);
		System.out.println("Input name");
		name=ConIn.next();
		System.out.println("Input surname");
		surname=ConIn.next();
	}
       public void setName(String name)
        {
          this.name = name;
        }
       public void setAcc(int ac)
       {
         account = ac;
       }
       public void setSurname(String surname)
        {
          this.surname = surname;
        }
       public void setPost(Post pst)
	{
		post.equat(pst);
	}
       public void setTask(Task tsk)
        {
            this.tsk.equat(tsk);
        }
       public void setLstCh(Date dat)
       {
         lstCharg.setDate(dat);
       }
       public String getName()
        {
          return name;
        }
       public String getSurname()
        {
          return surname;
        }
       public int getTaskId()
       {
         return tsk.getId();
       }
       
       public String getPostName()
       {
         return post.getName();
       }
       public int getAcc()
       {
         return account;
       }
       public Date getLstCh()
       {
         return lstCharg;
       }
       public void chargeMon(Date CurDate)
	{
		
		if(CurDate.convertionDate()-tsk.getSinceDate().convertionDate()>=30)
			account=account+tsk.getMon();
		int qm = (CurDate.convertionDate()-lstCharg.convertionDate()/30);
		while(qm!=0){
			account=account+post.getSalary();
                      qm--;  
		}
		lstCharg.setDate(CurDate);
	}
       public void showEmloyee()
        {
          System.out.print("Name: ");
          System.out.println(name);
          System.out.print("Surname: ");
          System.out.println(surname);
          System.out.print("Postname: ");
          System.out.println(post.getName());
          System.out.print("Account: ");
          System.out.println(account);
          System.out.print("Taskid: ");
          System.out.println(tsk.getId());
          System.out.print("Last Charge: ");
          lstCharg.showDate();
         }
       
       public boolean equals(Emplye ob)
        {
          return (name.equalsIgnoreCase(ob.getName()) && surname.equalsIgnoreCase(ob.getSurname()));
        }

}
