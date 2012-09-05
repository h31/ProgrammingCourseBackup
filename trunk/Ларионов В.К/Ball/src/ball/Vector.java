
package ball;


public class Vector {
    public int x, y;
    public Vector( int x, int y ) {
        this.x = x;
        this.y = y;
    }
    
    public Vector add( Vector arg ) {
        x += arg.x;
        y += arg.y;
        return this;
    }
    
    public Vector sum( Vector arg ) {
        Vector temp = new Vector( x, y );
        return temp.add(arg);
    }
    
    public Vector mult( int arg ) {
        return new Vector( x*arg, y*arg );
    }

    @Override
    public Vector clone() {
        Vector newVec = new Vector( x, y );
        return newVec;
    }
}
