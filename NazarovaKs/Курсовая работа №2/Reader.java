package demography;

import java.io.EOFException;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Reader {
   public Reader(String fileName)throws FileNotFoundException, EOFException{
        years=new LinkedList<>();
        birth=new LinkedList<>();
        death=new LinkedList<>();
        length=0;
        readOfString(fileName);
    }
    /*public class Reader {
   public Reader(String fileName)throws FileNotFoundException, EOFException{
        years=new LinkedList<>();
        birth=new LinkedList<>();
        death=new LinkedList<>();
        years=readOfString(fileName, "Years");
        birth=readOfString(fileName, "Birth");
        death=readOfString(fileName, "Death");
        length=amtLength();
    }*/
    /*private List readOfString(String fileName, String stringName)throws FileNotFoundException, EOFException{
        int i;
        Scanner in=new Scanner(new File(fileName));
        while(!in.next().equals(stringName)) in.next();
        if(!in.hasNext()) throw new EOFException();
        else{
            List<Integer> list=new LinkedList<>();
            while(in.hasNextInt()){
                i=in.nextInt();                
                list.add(i);
            }
            return list;
        }       
    }*/
   
   private void readOfString(String fileName)throws FileNotFoundException, EOFException{
    Scanner in=new Scanner(new File(fileName));
        while(in.hasNextLine()){
            in.nextLine();
            if(in.hasNextInt()){
                years.add(in.nextInt());
                birth.add(in.nextInt());
                death.add(in.nextInt());
            }
        } 
    length=amtLength();
    }
   
    private int amtLength(){
        if(years.size()==birth.size() && years.size()==death.size()) return years.size();
        else return minLength(years.size(), birth.size(), death.size());
    }
    private int minLength(int a, int b, int c){
        int min=(a<b)?a:b;
        return (c<min)?c:min;
    }
    public List getListOfYear(){
        return years;
    }
    public List getListOfBirth(){
        return birth;
    }
    public List getListOfDeath(){
        return death;
    }
    public int getLength(){
        return length;
    }
    
    List<Integer> years;
    List<Integer> birth;
    List<Integer> death;
    int length; 
}
