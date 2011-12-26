package Sums;

import java.util.StringTokenizer;

/**
 * @author Andrew
 */
public class Sum {
    private int rub = 0;
    private int kop = 0;
    
    public Sum add(Sum sum){
        Sum res = new Sum(this);
        res.rub += sum.rub;
        res.kop += sum.kop;
        res.simp();
        return res;
    }
    
    public Sum sub( Sum sum){
        Sum res = new Sum(this);
        if(kop < sum.kop && rub > 0){
            res.rub -= 1;
            res.kop += 100;
        }
        res.kop -= sum.kop;
        res.rub -= sum.rub;
        return res;
    }
    
    public Sum mult(int x){
        Sum res = new Sum(this);
        res.rub *= x;
        res.kop *= x;
        res.simp();
        return res;
    }
    
    public boolean greater(Sum sum){
        if(rub == sum.rub)
            return kop > sum.kop;
        return rub > sum.rub;
    }
    
    public int div( Sum sum ){
        return (rub*100 + kop)/(sum.rub*100 + sum.kop);
    }
    
    public Sum(Sum sum){
        rub = sum.rub;
        kop = sum.kop;
        simp();
    }
    
    public Sum(int r, int k){
        rub = r;
        kop = k;
        simp();
    }
    
    public int getKop(){
        return kop;
    }
    public int getRub(){
        return rub;
    }
    
    @Override
    public String toString(){
        StringBuilder str = new StringBuilder();
        str.append(Integer.toString(rub)).append(".");
        if(kop < 10)
            str.append("0");
        str.append(Integer.toString(kop));
        return str.toString();
    }
    
    public static Sum parseSum(String str) throws InvalidFormatException{
        try{
            StringTokenizer st = new StringTokenizer(str, ".");
            if(st.countTokens() != 2)
                throw new InvalidFormatException();
            return new Sum(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }catch(Exception e){throw new InvalidFormatException();}
    }
    @Override
    public boolean equals(Object obj){
        if(obj.getClass().equals(this.getClass())){
            return ((Sum)obj).rub == this.rub && ((Sum)obj).kop == this.kop;
        }else
            return false;
    }
    final void simp(){
        rub += kop / 100;
        kop %= 100;
    }
}
