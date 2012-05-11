/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ball;

/**
 *
 * @author Eugene
 */
abstract public class SpaceObjectView {
    protected SpaceObject object;
    public SpaceObjectView( SpaceObject _object ) {
        object = _object;
    }
    abstract void update();
}
