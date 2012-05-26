package Creatures;

/**
 * @author Andrew
 */
public class Damage {
    int val;
    int power;
    int speed;
    Damage(int value, int power, int speed){
        val = value;
        this.power = power;
        this.speed = speed;
    }
    
    public int getPower(){ return power; }
    public int getSpeed(){ return speed; }
    public int getValue(){ return val; }
}
