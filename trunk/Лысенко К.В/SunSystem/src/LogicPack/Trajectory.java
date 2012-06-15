package LogicPack;

import java.awt.Point;
import GraphicPack.Screen;

public abstract class Trajectory{
    abstract public Point nextStep();
    public void calcStep(){}
    public void setScreen(Screen screen){}
}