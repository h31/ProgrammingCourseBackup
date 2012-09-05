
package ball;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;


public class Ball extends SpaceObject {

    static int dx=1, dy=1;
    private int radius;
    private Color color;
    public double c=0;

    public Ball( Vector pos, Vector speed, int radius, Color color) {
        super( pos, speed );
        
        this.radius = radius;
        this.color = color;
    }

    public int getRadius() {
        return radius;
    }

    public Color getColor() {
        return color;
    }
    public void change_color(Color color){this.color=color;}
    
public void check (Racket racket, Score score) {
    if (((pos.x+getRadius() )> racket.pos.x )&&(pos.x < racket.pos.x)&&((pos.y+getRadius())>racket.pos.y)&&(pos.y<racket.pos.y+racket.getLength()))
                        {            
            dx = -dx;
            dy = dy;
            score.amount=score.amount+5;
                        }
                       if (pos.x < getRadius()) {
            pos.x =getRadius();
            dx = -dx;
        }
        if (pos.y < getRadius()) {
            pos.y = getRadius();
            dy = -dy;
        }
    
}
    public void step( Space space ) {

        oldpos = pos.clone();
        pos.add(new Vector( dx, dy ));

        if (pos.x >= space.getWidth() - radius) {
            pos.x = space.getWidth() - radius - 1;
            dx = -dx;
        }
        if (pos.y >= space.getHeight() - radius) {
            pos.y = space.getHeight() - radius - 1;
            dy = -dy;
        }
  
        if (pos.x < radius) {
            pos.x = radius;
            dx = -dx;
        }
        if (pos.y < radius) {
            pos.y = radius;
            dy = -dy;
        }
        updateViews();
    }

  public void check2( int v ) {

      if ((v==1)&&(dx>0))
                        {c=c+0.03;
                        if ((c-1)>0){dx++; c=0;}}
      if ((v==1)&&(dx<0)){v=2;}
      if((v==2)&&(dx<0)){c=c+0.05; 
        if (c-0.8>0){dx++; c=0;}}
      if ((v==2)&&(dx==0)){dx=1; v=1;}
     
      
                    
}
}