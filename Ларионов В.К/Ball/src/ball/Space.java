/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ball;

import java.awt.Container;

/**
 *
 * @author Eugene
 */
public class Space {
    Container c;

//    private int width;
//    private int height;
    
    private double gForce;
   
//    public Space( int _width, int _height ) {
//        width = _width;
//        height = _height;
//    }
    public Space( Container _c ) {
        c = _c;
    }
    public int getWidth() {
        return c.getWidth();
    }
    public int getHeight() {
        return c.getHeight();
    }
   
}
