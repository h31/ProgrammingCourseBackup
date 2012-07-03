package Creatures;

import Dungeon.Percenter;
import Dungeon.Position;
import java.awt.Image;
import java.util.ArrayDeque;
import java.util.Iterator;

/**
 * @author Andrew
 */
public abstract class Creature {
    protected String name;
    protected int health;
    protected int maxhealth;
    protected int defence;
    protected int dexterity;
    protected int strength;
    protected int sightradius;
    protected int hregen;
    protected int hrcount = 0;
    protected Position pos;
    protected Image img;
    ArrayDeque<Buff> buffs;
    
    Creature(String name, Image img, int maxhealth, int defence, int strength, int dexterity, int hregen, int sightradius){
        this.name = name;
        this.maxhealth = maxhealth;
        this.defence = defence;
        this.strength = strength;
        this.dexterity = dexterity;
        this.sightradius = sightradius;
        health = maxhealth;
        this.img = img;
        this.hregen = hregen;
        buffs = new ArrayDeque<Buff>();
    }
    
    public abstract Damage getDamage();
    
    public Position getPos(){ return pos; }
    public void move(Position npos){ pos = npos; }
    public int getHealth(){ return health; }
    public int getMaxHealth(){ return maxhealth; }
    public int getSightRad(){ return sightradius; }
    public String getName(){ return name; }
    public Image getImg(){ return img; }
    public int getDefence(){ return defence; }
    public int getHealthRegen(){ return hregen; }
    public int getStrength(){ return strength; }
    public int getDexterity(){ return dexterity; }
    public boolean isPlayer(){ return false; }
    
    public void passTurn(){
        if(health < maxhealth && hregen > 0){
            hrcount ++;
            if(hrcount >= 10 - Math.min(Math.round(hregen*0.7d), 10)){
                hrcount = 0;
                health++;
            }
        }
        Iterator<Buff> itt = buffs.iterator();
        while(itt.hasNext()){
            Buff buff = itt.next();
            try{
                for(Effect eff: buff.takeEffect())
                    if(!(eff.isReversible() && buff.isActive()))
                        takeEffect(eff);
            }catch(Exception ex){
                for(Effect eff: buff.getReverse())
                    takeEffect(eff);
                itt.remove();
            }
        }
    }
    public void takeEffect(Effect effect){
        switch(effect.getVarChar()){
            case HEALTH: health += effect.getValue(); if(health > maxhealth) health = maxhealth; break;
            case MAXHEALTH: maxhealth += effect.getValue(); break;
            case DEXTERITY: dexterity += effect.getValue(); break;
            case STRENGTH: strength += effect.getValue(); break;
            case HREGEN: hregen += effect.getValue(); break;
            case SRADIUS: sightradius += effect.getValue(); break;
        }
    }
    public int takeDamage(Damage damage){
        if(new Percenter(damage.getSpeed(), dexterity - (int)(dexterity/3d)).getChance() == 1){
            int dam = damage.getValue() - defence;
            if(dam < 0)
                dam = 0;
            health -= dam;
            return dam;
        }else
            return -1;
    }
}
