/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ball;

import java.util.ArrayList;
import java.util.Collection;

/**
 *
 * @author Eugene
 */
abstract public class SpaceObject {
    private ArrayList<SpaceObjectView> views = new ArrayList<SpaceObjectView>();

    protected Vector pos;
    protected Vector oldpos;
    protected Vector speed;
    protected int mass = 1;
    
    protected SpaceObject( Vector pos, Vector speed ) {
        this.oldpos = pos;
        this.pos = pos;
        this.speed = speed;
    }
    
//    abstract boolean hasContact( SpaceObject obj );
//    abstract void resolveContact( Collection<SpaceObject> c );
//    abstract boolean isOutside( Space spc );

    public void registerView( BallView view ) {
        views.add(view);
    }
     public void registerView( RacketView view ) {
        views.add(view);
    }
     public void registerView (ScoreView view) {
         views.add(view);
     }

    public void updateViews() {
        for( SpaceObjectView view: views ) {
            view.update();
        }
    }
    public void move( int dt, Vector force  ) {
        oldpos = pos.clone();
        pos.add(speed.mult(dt));
        speed.add(force.mult(dt/mass));
        updateViews();
    }

    public Vector getPosition() {
        return pos;
    }

    public Vector getOldPosition() {
        return oldpos;
    }
}
