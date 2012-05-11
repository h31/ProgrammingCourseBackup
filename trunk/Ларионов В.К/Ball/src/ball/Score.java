
package ball;

public class Score extends SpaceObject {
    public double amount;
    
    public Score(Vector pos , Vector speed) {
                super( pos, speed );
        this.amount=0;
    }
    
}
