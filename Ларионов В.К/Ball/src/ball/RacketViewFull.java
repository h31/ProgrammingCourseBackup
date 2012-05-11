

package ball;

import java.awt.Graphics;

public class RacketViewFull extends RacketView{
    public RacketViewFull( Racket racket ) {
        super( racket );
    }
    @Override
    public void update() {

    }
    public void paint(Graphics g) {
        Racket racket = (Racket) object;
        g.setColor(racket.getColor());
        int length = racket.getLength();
        int width = racket.getWidth();
        int x = racket.getPosition().x;
        int y = racket.getPosition().y;
        g.fillRect(x, y,width, length);
    }
}
