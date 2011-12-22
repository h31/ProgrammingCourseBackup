package MainPack;

/**
 * @author Andrew
 */
public class Sum {
    private int rub = 0;
    private int kop = 0;
    
    public Sum add(Sum sum){
        Sum res = new Sum(this);
        this.rub += sum.rub;
        this.kop += sum.kop;
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
    
    final void simp(){
        rub += kop / 100;
        kop %= 100;
    }
}
