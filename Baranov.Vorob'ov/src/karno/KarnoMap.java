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
        
        row = (int)Math.pow(2,(nov/2));
        col = (int)Math.pow(2,(nov/2+(nov%2)));
        
        karno = new int[row][col];
    
        for(int i = 0; i<col; i++){
            for(int u = 0; u<row; u++){
                karno[u][i] = 0;}}
        
        for(int q = 0; q<v.size(); q++)
        {
            int r = GrayCode.decodeGray(v.get(q))
            int c =
            karno[r][c] = 1;
        }
    
    }
    
    
}