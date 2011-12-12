package Project;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException
 	{
                RepEmplye REmp = new RepEmplye();
                RepPost RPos = new RepPost();
                RepTask RTas = new RepTask();
                
		Date globDate = new Date();
                File RE = new File("Emplyee.xml");
                File RP = new File("Post.xml");
                File RT = new File("Task.xml");
                
                RPos.Parcer(RP);
                RTas.Parcer(RT);
                REmp.Parcer(RE, RPos, RTas);
                
                Scanner ConsIn = new Scanner(System.in);
		int opt;
		int addop;
		
		do{
			System.out.println("1.Work with Emplyee");
			System.out.println("2.Work with Post");
			System.out.println("3.Work with Task");
			System.out.println("4.Set CurDate");
			System.out.println("5.Refresh Salary");
			System.out.println("6.Exit");
			
			
	 	opt=ConsIn.nextInt();
		 	switch (opt){
			case 1:
                        {
				do{
				System.out.println("1.Add new Emplyee.");
				System.out.println("2.Delete Emplyee");
				System.out.println("3.Show Emlyee");
				System.out.println("4.Set Task to Emplyee");
				System.out.println("5.<<Back");
				
				addop = ConsIn.nextInt();
				
				switch(addop){
				case 1:
                                {
                                    REmp.addNewEmp(RPos, RTas);
                                    break;}
				case 2: 
                                {
                                    REmp.deleteEmplye();
                                    break;}
				case 3: 
                                {
                                    REmp.showEmployees();
                                    break;}
				case 4: 
                                {
                                    REmp.setTask(RTas);
                                    break;}
					}
				}while(addop!=5);
				break;}
				
			case 2:
                        {
                            do{
				System.out.println("1.Add new Post");
				System.out.println("2.Delete Post");
				System.out.println("3.Show Post");
				System.out.println("4.<<Back");
				
				addop=ConsIn.nextInt();
				
				switch(addop){
				case 1: 
                                {
                                    RPos.addNewPost();
                                    break;}
				case 2: 
                                {
                                    RPos.deletePost();
                                    break;}
				case 3: 
                                {
                                    RPos.showPost();
                                    break;}
					}
				}while(addop!=4);
				break;}
				
			case 3:
                        {
				do{
				System.out.println("1.Add new Task");
				System.out.println("2.Delete Task");
				System.out.println("3.Show Task");
				System.out.println("4.<<Back");
				
				addop=ConsIn.nextInt();
				
				switch(addop){
				case 1: 
                                {
                                    RTas.addNewTask();
                                    break;}
				case 2: 
                                {
                                    RTas.deleteTask();
                                    break;}
				case 3: 
                                {
                                    RTas.showTasks();
                                    break;}
				}
				}while(addop!=4);
				break;}
				
			case 4:
                        {
				globDate.showDate();
				System.out.println("Input new Date. (day month year)");
				int d, m, y;
				d=ConsIn.nextInt();
				m=ConsIn.nextInt();
				y=ConsIn.nextInt();
				globDate.setDate(d, m, y);
				break;}
			case 5:
                        {
                                REmp.refreshSal(globDate);
                                break;}
		 	}
	 	}while(opt!=6);
	
        RTas.XMLOutputter(RT);
        RPos.XMLOutputter(RP);
        REmp.XMLOutputter(RE);
       }
        
}
