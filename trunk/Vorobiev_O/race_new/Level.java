
package race;


import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

public class Level {
    
    private ArrayList<Block> mass;
    private Car test_car;
    private Road test_road;
    private int last_pos=0;
    Random r_generator = new Random();
    private int last_index1=0;
    private int last_index2=0;
    private int last_index3=0;
    private int last_index4=0;
    
    private int ver[]= new int[6];
    Random r_gen1 = new Random();
    Random r_gen2 = new Random();
    
    Blockview block_v;
    int difficultly;
    Color color;
    int space;
    
    public Level()
    {
        mass = new ArrayList<Block>();
        test_car=new Car(0,0,20,40,Color.BLACK);
        test_road = new Road();
        
        
        Block block=new Block(test_road.get_x()+ 146,0,50,70,Color.RED);
        block.set_speed(0, 4);
        mass.add(block);
        //this.space=0;
        
        for(int i=0;i<6;i++) this.ver[i]=1;
    }
    
    void set_difficultly(int s)
    {
        this.difficultly=s;
    }
    
    boolean is_space(Block bl)
    {
        boolean otv=true;
        
        for(Block block: mass)
        {
         if ((block.get_x()-test_car.get_width()-10 < bl.get_x()+bl.get_width()) && 
            (block.get_x()+block.get_width()+test_car.get_width()+10 > bl.get_x()) &&
            (block.get_y()-test_car.get_heigth()-90-difficultly< bl.get_y()+bl.get_heigth()) &&
            (block.get_y()+block.get_heigth()+test_car.get_heigth()+90+difficultly > bl.get_y()))
            {
                otv=false;
                break;
            }
        }
        return otv;
    }
      
    private boolean collision(int car_x,int car_y,Block block)
    {
        
        return (car_x+test_car.get_width() >= block.get_x()) && 
               (car_x <= block.get_x() + block.get_width()) && 
               (car_y <= block.get_y() + block.get_heigth()) &&
               (car_y+test_car.get_heigth() >= block.get_y());
    }
    
    boolean crash(int car_x,int car_y)
    {
        boolean otv=false;
        
        for(Block block: mass)
        {
            if(collision(car_x,car_y,block))
            {
                otv=true;
                break;
            }
        }
        
        return otv;
    }
    
    void add_block()//не используется в данный момент.
    {
        Block new_block;
        
        int index=r_gen1.nextInt(3);
        if(index==0) this.color=Color.BLUE;
        if(index==1) this.color=Color.GREEN;
        if(index==2) this.color=Color.RED;
   
        index=r_generator.nextInt(6);
        
        if ((index != last_index1) && (index != last_index2))
        {
            new_block= new Block(test_road.get_x()+6+70*index,0,50,70,color);
            if ((index==0) || (index==1) || (index ==2)) new_block.set_speed(0, 4);
            else new_block.set_speed(0,2);
            if(is_space(new_block)) 
            {
                mass.add(new_block);
                last_index2=last_index1;
                last_index1 = index;
                
                
            }
        }
    }
    
    void creation()
    {
        Block new_block;
        
        int index=r_gen1.nextInt(4);
        if(index==0) this.color=Color.BLUE;
        if(index==1) this.color=Color.GREEN;
        if(index==2) this.color=Color.RED;
        if(index==2) this.color=Color.BLACK;
        
        int index1= r_gen1.nextInt(6);
        int index2= r_gen2.nextInt(5);
        
        
        if(index2 <= ver[index1])
        {
            if ((index1 != last_index1) && (index1 != last_index2) && (index1 != last_index3))
            {
                new_block= new Block(test_road.get_x()+6+70*index1,0,50,70,color);
                if ((index1==0) || (index1==1) || (index1 ==2)) new_block.set_speed(0, 4);
                else new_block.set_speed(0,2);
                if(is_space(new_block)) 
                {
                    mass.add(new_block);
                    last_index4=last_index3;
                    last_index3=last_index2;
                    last_index2=last_index1;
                    last_index1 = index1;
                    this.space=0;
                }
            }    
        }
    }
    
    void level_step()
    {
        for(Block block: mass)
        {
            block.step();
        }
        
        creation();
    }
    
    void paint(Graphics g)
    {
        for(Block block: mass)
        {
            if(block.get_y()>= 480) mass.remove(block);
            else
            {
                block_v=new Blockview(block);
                block_v.paint(g);
            }
        }
    }
}