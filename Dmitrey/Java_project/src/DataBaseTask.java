import java.io.*;

class datbasTask{
private	task tsk[];

public void add()
		throws IOException{
		InputStreamReader usin = new InputStreamReader(System.in);
		int t, d, m;
		System.out.println("Input time: ");
		t=usin.read();
		System.out.println("Input description: ");
		d=usin.read();
		System.out.println("Input price of task: ");
		m=usin.read();
		
		FileOutputStream out = new FileOutputStream ("/DataBaseTask.txt", true);
		out.write(t);
		out.write(d);
		out.write(m);
	}

public void read()
		 throws IOException{
				try{
				FileInputStream in = new FileInputStream("/DataBaseTask.txt");
					
					int d, t, m, s, i=0;
					do{
						t = in.read();
						d = in.read();
						m = in.read();
						s = in.read();
						if(t!=-1 || d!=-1 || m!=-1 || s!=-1){
						tsk[i] = new task();
						tsk[i].task(t, d, m);
						}
						i++;
					}while(t!=-1 || d!=-1 || m!=-1 || s!=-1);
				}
				catch(FileNotFoundException e){
					System.out.println("File not found!");
					return;
					}
	}
}