package poker;

public class Poker {

    public static void main(String[] args) {
        
        
        
        int bb = 100;
        Table table = new Table(bb);
        Deck deck = new Deck();
        int qp = 5;
        table.addPlayers(qp);
        table.blinds();
        
        
        
    }
}
