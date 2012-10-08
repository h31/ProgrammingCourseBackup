package karno;

import java.util.ArrayList;
import suport.GrayCode;

public class KarnoMap {
    
    TruthTab m;
    int[][] karno;
    int row, col;
    
    public KarnoMap(TruthTab m)
    {
        this.m = m;
        
        row = (int)Math.pow(2,(m.getNOV()/2));
        col = (int)Math.pow(2,(m.getNOV()/2+(m.getNOV()%2)));
        
        karno = new int[row][col];
    }
    
    public KarnoMap(ArrayList<Integer> v)
    {
        int nov = ((int)(Math.log(v.get(v.size()-1)) / Math.log( 2 )))+1;
        int border = nov/2;
        row = (int)Math.pow(2,border);
        col = (int)Math.pow(2,(border+(nov%2)));
        
        karno = new int[row][col];
    
        for(int i = 0; i<col; i++){
            for(int u = 0; u<row; u++){
                karno[u][i] = 0;}}
        
        for(int q = 0; q<v.size(); q++)
        {
            String z = Integer.toBinaryString(v.get(q));
            String e = "";
            for(int i = 0; i<(nov-z.length()); i++)
            {
                e+="0";
            }
            e+=z;
            //System.out.println(e);
            if(e.length()!=nov)System.out.println("Error of code lengh");
            int r = GrayCode.decodeGray(Integer.parseInt(e.substring(0, (border)), 2));
            
            int c = GrayCode.decodeGray(Integer.parseInt(e.substring(border), 2));
            
            karno[r][c] = 1;
        }
    
    }
    
    void showKarno()
    {
        for(int i = 0; i<row; i++){
            for(int y = 0; y<col; y++)
            {
                System.out.print(karno[i][y]);
            }
            System.out.println();
        }
    }
}