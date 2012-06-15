package LogicPack;
import java.awt.Point;
public class TrajStat extends Trajectory{
    Point point;
    public TrajStat(Point p){
        point = p;
    }
    @Override
    public Point nextStep(){
        return point;
    }
}
