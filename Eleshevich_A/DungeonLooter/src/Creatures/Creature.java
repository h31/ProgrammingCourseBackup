package Creatures;

import Dungeon.Position;
import java.awt.Image;

/**
 * @author Andrew
 */
public abstract class Creature {
    String name;
    int health;
    protected int maxhealth;
    protected int defence;
    protected int dexterity;
    protected int strength;
    protected int sightradius;
    protected Position pos;
    protected Image img;
    
    Creature(String name, int maxhealth, int defence, int strength, int dexterity, int sightradius){
        this.name = name;
        this.maxhealth = maxhealth;
        this.defence = defence;
        this.strength = strength;
        this.dexterity = dexterity;
        this.sightradius = sightradius;
        health = maxhealth;
    }
    
    public abstract Damage getDamage();
    
    public int attack(Damage damage){
        int dam = damage.val - defence;
        health -= dam;
        return dam;
    }
    public Position getPos(){ return pos; }
    public void move(Position npos){ pos = npos; }
    public int getHealth(){ return health; }
    public int getMaxHealth(){ return maxhealth; }
    public int getSightRad(){ return sightradius; }
    public String getName(){ return name; }
    public Image getImg(){ return img; }
    public int getDefence(){ return defence; }
}
