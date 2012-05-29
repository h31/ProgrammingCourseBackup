package sunsystem;

import java.awt.Point;

public abstract class Trajectory{
    abstract public Point nextStep();
    public void calcStep(){}
    public void setScreen(Screen screen){}
}

class TrajCircle extends Trajectory{
    double cycle;
    boolean direction;
    int r;
    double angle;
    double step;
    Screen scr = BaseScreen.getBscreen();
    Point circPos = new Point();
    TrajCircle(int r, boolean dir, double startAngle, double cycle, Point circPos){
        this.r = r;
        direction = dir;
        angle = startAngle;
        this.cycle =cycle*10000;
        calcStep();
        this.circPos = circPos;

    }
    @Override
    public Point nextStep(){
        if(direction){
            angle += step;
            if(angle > 360)
                angle -= 360;
        }
        else{
            angle -= step;
            if(angle < 0)
                angle += 360;
        }
        Point res = new Point(0, 0);
        res.x = (int)(circPos.x + r*Math.cos(Math.toRadians(angle)));
        res.y = (int)(circPos.y + r*Math.sin(Math.toRadians(angle)));
        return res;
    }
    @Override
    final public void calcStep(){
        step = (360.0)/((cycle/scr.getTfact())/scr.getTstep());
    }
    @Override
    public void setScreen(Screen screen){
        scr = screen;
        calcStep();
    }
}

class TrajStat extends Trajectory{
    Point point;
    TrajStat(Point p){
        point = p;
    }
    @Override
    public Point nextStep(){
        return point;
    }
}
