

package ball;

import java.awt.Graphics;
import java.awt.Color;

public class ScoreViewFull extends ScoreView{
    public ScoreViewFull( Score score ) {
        super( score );
    }
    @Override
    public void update() {

    }
    public void paint(Graphics g) {
        Score score = (Score) object;
        g.setColor(Color.WHITE);
        g.fillRect(600,0,400,30);
        g.setColor(Color.BLACK);
        String s ="Score = ";
        String s1 = String.valueOf(score.amount);
        s=s+s1;
        g.drawString(s, 650 , 15);
        
        
    }
}
