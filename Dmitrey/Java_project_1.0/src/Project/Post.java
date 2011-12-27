package Project;

import java.io.*;
import java.util.*;

public class Post {
//Variables	
 	private String name, descr;
 	private int salary;
//Methods
        Post()
        {
          name="emp";
          descr="emp";
          salary=-1;
        }
        
        Post(String n, String d, int s)
        {
          name=n;
          descr=d;
          salary=s;
        }
        
        public void showPost()
        {
          System.out.print("(Name: ");
          System.out.println(name);
          System.out.print("(Description: ");
          System.out.println(descr);
          System.out.print("(Salary: ");
          System.out.println(salary);
        }
        
 	public void setName()
 	{
                Scanner ConsIn = new Scanner(System.in);
		System.out.println("Input name");
		name=ConsIn.next();
 	}
        
        public void setName(String name)
 	{
                this.name = name;
 	}
        
 	public void setDescr()
 	{
                Scanner ConsIn = new Scanner(System.in);
		System.out.println("Input descr");
		descr=ConsIn.next();
 	}
        public void setDescr(String descr)
 	{
		this.descr = descr;
 	}
 	public void setSalary()
 	{
                Scanner ConsIn = new Scanner(System.in);
		System.out.println("Input salary");
		salary=ConsIn.nextInt();
 	}
        
        public void setSalary(int salary)
 	{
		this.salary = salary;
 	}
        
 	public String getName()
 	{
 		return name;
 	}
 	public String getDescr()
 	{
 		return descr;
 	}
 	public int getSalary()
 	{
 		return salary;
 	}
 	public void equat(Post pst)
 	{
 		name=pst.name;
 		descr=pst.descr;
 		salary=pst.salary;
 	}
       
	public boolean equals(Post ob)
        {
          return name.equalsIgnoreCase(ob.name);
        }
}
