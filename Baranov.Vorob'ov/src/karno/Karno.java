package karno;

import suport.*;
import java.util.ArrayList;

public class Karno {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//       
//        ArrayList<Integer> a = new ArrayList();
//        a.add(0);
//        a.add(3);
//        a.add(4);
//        a.add(7);
//        a.add(9);
//        a.add(13);
//        a.add(15);
//        a.add(23);
//        a.add(35);
//        
//        
//        truthTab mt = new truthTab(a);
//        mt.conShow();
        for(int i = 0; i<7; i++){
            
            System.out.print(Integer.toBinaryString(i));
            System.out.print("-");
            int y = GrayCode.encodeGray(i);
            System.out.println(Integer.toBinaryString(y));
        }
    }
}