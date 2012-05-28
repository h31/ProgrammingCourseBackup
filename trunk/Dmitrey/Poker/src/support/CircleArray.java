package support;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import poker.Player;

public class CircleArray<E> {
    
    private ArrayList<E> CirArray;
    private int ind;
    
    public CircleArray()
    {
        CirArray = new ArrayList();
        ind = 0;
    }
    
    public void add(E ob)
    {
        CirArray.add(ob);
    }
    
    public void addAll(CircleArray<E> c)
    {
        for(int i = 0; i<c.size(); i++)
        {
            this.CirArray.add(c.get(i));
        }
    }
    
    public void setInd(int i)
    {
        if(i<CirArray.size())
        {ind = i;}
        else
        {
            ind = (i%CirArray.size());
        }
    }
    
    public int size()
    {
        return CirArray.size();
    }
    
    public void resetInd()
    {
        ind = 0;
    }
    
    public E get(int i)
    {
        if(i >= CirArray.size())
        {i = (i%CirArray.size());}
        return (E)CirArray.get(i);
    }
    
    public E getFst()
    {
        return (E)CirArray.get(0);
    }
    
    public int getInd()
    {
        if(ind >= CirArray.size())
        {ind = (ind%CirArray.size());}
        return ind;
    }
    
    public E getNext() 
    {
        if(ind >= CirArray.size())
        {ind = (ind%CirArray.size());}
        return (E)CirArray.get(ind++);
    }
    
    public int getNextx() 
    {
        if(ind == CirArray.size())
        {resetInd();}
        return ind++;
    }
        
    public E remove(int i)
    {
        //if(i >= CirArray.size()){
        //i = (i%CirArray.size());}
        if(i<=ind) 
        ind--;
        return CirArray.remove(i);
    }
    
    public Object toArray()
    {
        return CirArray.toArray();
    }
    
    public void removeAll()
    {
        CirArray.removeAll(CirArray);
    }
    
    public ArrayList getCA()
    {
        return CirArray;
    }
}
    
    
    
