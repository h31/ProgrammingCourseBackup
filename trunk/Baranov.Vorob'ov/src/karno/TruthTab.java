package karno;

import java.util.ArrayList;



public class TruthTab {
    
    int[][] m;
    int row, col;
    int nov; //num of var
    
    public TruthTab(ArrayList<Integer> v)
    {
        nov = ((int)(Math.log(v.get(v.size()-1)) / Math.log( 2 )))+1;
        row = (int)Math.pow(2, nov);
        col = nov+1;
        m = new int[row][col];
                
        for(int t = 2; t<=col; t++)
        {   
            int w = (int)Math.pow(2, (t-2));
            boolean b = false;
            for(int q = 0, p=0; q<row; q++)
            {
                if(p>=w){
                    if(!b)p+=(w-1);
                    b = true;
                m[q][col-t]=1;
                p--;}
                
                else
                {
                    if(b)p-=(w-1);
                    b = false;
                    m[q][col-t]=0;
                p++;}
            }
        }
        
        
        for(int i = 0; i<v.size(); i++)
        {
            m[v.get(i)][col-1] = 1;           
        }
    }
    
    public void incertEl(int r, int c, int el)
    {
        m[r][c] = el;
    }
    
    public void showTruthTab()
    {
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                {
                    if(j==(col-1)){System.out.print(" ");}
                    System.out.print(m[i][j]);
                }
            }
        System.out.println();
        }
     }
    
    public int getNOV()
    {
        return nov;
    }
    
    public int getSize()
    {
        return (row*(col-1));
    }
    
    public void checkTable()
    {
    int nos = (int)Math.pow(2, (col-1));
    
    for(int k = 0; k<nos; k++){
            int cn = 0;
            for(int i = (nov-1); i>=0; i--)
            {
                cn=cn+(m[k][i])*((int)Math.pow(2, ((nov-1)-i)));
                 
            }
            System.out.println(cn);
        }
    }
}
