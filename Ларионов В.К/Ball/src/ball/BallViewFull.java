
package ball;

import java.awt.Graphics;


public class BallViewFull extends BallView {
    public BallViewFull( Ball ball ) {
        super( ball );
    }
    @Override
    public void update() {

    }
    public void paint(Graphics g) {
        Ball ball = (Ball) object;
        g.setColor(ball.getColor());
        int radius = ball.getRadius();
        int x = ball.getPosition().x;
        int y = ball.getPosition().y;
        g.fillOval(x-radius, y-radius, 2*radius, 2*radius);
    }
}
