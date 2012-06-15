package LogicPack;

import java.awt.Component;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;

public class SpaceObject {
    Point position;
    Trajectory traj;
    int radius;
    Image img;
    
    SpaceObject(Image img, int radius, Trajectory trajectory){
        this.radius = radius;
        traj = trajectory;
        position = new Point(50, 50);
        this.img = img;
    }
    public void paint(Graphics g, Component comp, double Sfact){
        Point pos = getFactPos(Sfact);
        int rad = getFactRad(Sfact);
        g.drawImage(img, pos.x - rad, pos.y - rad, rad*2, rad*2, comp);
    }
    public Point getFactPos(double Sfact){
        return new Point((int)(position.x*Sfact), (int)(position.y*Sfact));
    }
    public int getFactRad(double Sfact){
        return (int)(radius*Sfact);
    }
    
    public int getRadius(){
        return radius;
    }
    
    public Point getPosition(){
        return position;
    }
    
    public void CalcStep(){
        position = traj.nextStep();
    }
    public boolean liesIn(Point p, double Sfact){
        Point pos = getFactPos(Sfact);
        int rad = getFactRad(Sfact);
        return (p.x-pos.x)*(p.x-pos.x)+(p.y-pos.y)*(p.y-pos.y)<= rad*rad;
    }
    public Trajectory getTrajectory(){
        return traj;
    }
}
