package LogicPack;

import java.awt.Image;

public class Planet extends SpaceObject{
    String name;
    Image BigImg;
    String description;
    
    public Planet(String name, Image SmallImg, Image BigImg, String desc, int radius, Trajectory trajectory){
        super(SmallImg, radius, trajectory);
        this.name = name;
        this.BigImg = BigImg;
        description = desc;
    }
    
    public String getName(){
        return name;
    }
    public Image getBigImage(){
        return BigImg;
    }
    public String getDiscr(){
        return description;
    }
}
