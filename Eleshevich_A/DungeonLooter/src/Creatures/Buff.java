package Creatures;


/**
 * @author Andrew
 */
public class Buff { //может другое название?
    Effect[] effects;
    int counter;
    boolean active;
    
    public Buff(Effect[] effects, int duration){
        this.effects = effects;
        counter = duration;
        active = false;
    }
    
    public Effect[] takeEffect() throws BuffExpiredException{
        if(counter != 0){
            active = true;
            counter--;
            return effects;
        }else
            throw new BuffExpiredException();
    }
    public Effect[] getEffect(){
        return effects;
    }
    public boolean expired(){
        return counter == 0;
    }
    public Effect[] getReverse(){
        int count = 0;
        for(Effect eff: effects)
            if(eff.isReversible())
                count++;
        Effect[] res = new Effect[count];
        int d = 0;
        for(int x = 0; x < effects.length; x++){
            if(effects[x].isReversible()){
                res[d] = effects[x].reverse();
                d++;
            }
        }
        return res;
    }
    public boolean isActive(){
        return active;
    }
}

class BuffExpiredException extends Exception{
    @Override
    public String getMessage(){
        return "Buff has expired, and must be deleted";
    }
}