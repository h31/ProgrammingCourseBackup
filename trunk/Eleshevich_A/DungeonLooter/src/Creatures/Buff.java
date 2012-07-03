package Creatures;


/**
 * @author Andrew
 */
public class Buff {
    Effect[] effects;
    int counter;
    int duration;
    boolean active;
    
    public Buff(Effect[] effects, int duration){
        this.effects = effects;
        this.duration = duration;
        counter = duration;
        active = false;
    }
    public int getDuration(){
        return duration;
    }
    public Effect[] takeEffect() throws BuffExpiredException{
        if(counter == duration-1)
            active = true;
        if(counter != 0){
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
    @Override
    public Buff clone(){
        return new Buff(effects, duration);
    }
}

class BuffExpiredException extends Exception{
    @Override
    public String getMessage(){
        return "Buff has expired, and must be deleted";
    }
}