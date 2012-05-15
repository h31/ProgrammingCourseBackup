package support;

import java.util.Collections;
import java.util.ArrayList;

public abstract class maxNums {
    
        public static int maxn(ArrayList n)
        {
            int res = 0;
            int m = new Integer(Collections.max(n).toString());
            System.out.println("m: " +m);
            for(int i = 0; i<n.size(); i++)
            {
                if(new Integer(n.get(i).toString())==m)
                {res++;}
            }
            return m;
        }
}
