

package ball;
import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;

public class Racket extends SpaceObject{
    static int dx=0,dy=1;
    private int width , length;
    private Color color;
    
    /** Creates a new instance of Racket */
    public Racket(Vector pos, Vector speed, int width , int length , Color color) {
        super( pos, speed );
        
        this.length = length;
        this.width=width;
        this.color = color;
    }
       public int getLength() {
        return length;
    }

    public Color getColor() {
        return color;
    }
    public int getWidth() {
        return width;
    }

    public void step( Space space , int dt ) {

        oldpos = pos.clone();
        pos.add(new Vector( dx, dy+dt ));
 if (pos.y >= space.getHeight()-length) {
            pos.y = space.getHeight()-length - 1;
        }
if (pos.y<=0) {
            pos.y =1;
        }
        updateViews();
    }
}
