package poker;

public class Poker {
               
    public static void main(String[] args) throws InterruptedException {
        
        StartFrame sf = new StartFrame();
        sf.Start();
        do{
        
        if(sf.rdy()){
        Table table = new Table(sf._b());
        table.start();
        sf.Start();}
        }while(true);
    }
    
}  
    