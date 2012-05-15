package poker;

public class Poker {

    public static void main(String[] args) {
        
        Table table = new Table(20);
        table.start();
        System.out.println("END!");
    }
}
