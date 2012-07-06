
package race;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Font;
import java.io.IOException;



public class World 
{
    private Car car;
    private Road road;
    private Level level;
    private Score score;
    private Carview car_v;
    private RecordList rec_list;
    
    public World() 
    {
        car= new Car(350,380,20,40,Color.BLACK);
        road= new Road();
        level= new Level();
        score= new Score();
        road.fill_road();
        car_v=new Carview(car);
        
    }
    
    Score get_score() {return score;}
    
    void move_car(int dx,int dy)
    {
        car.move(dx, dy);
    }
    
    void set_difficultly(int s)
    {
        level.set_difficultly(s);
        
    }
    
    boolean collision()
    {
        return level.crash(car.get_x(), car.get_y());
    }
     
    
    void world_step()
    {
        level.level_step();
        road.road_step();
        score.raise_score(car);
    }
     
    void paint(Graphics g)
    {
        road.paint(g);
        car_v.paint(g);
        level.paint(g);
        score.paint(g,car);
    }
}
