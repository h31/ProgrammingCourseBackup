package Creatures;

import Constants.CreatChar;
import Creatures.Player;

/**
 * @author Andrew
 */
public class Effect {
    boolean reversible;
    CreatChar variableChar;
    int value;
    
    public Effect(CreatChar vchar, int value, boolean reversible){
        variableChar = vchar;
        this.value = value;
        this.reversible = reversible;
    }
    
    public CreatChar getVarChar(){
        return variableChar;
    }
    public int getValue(){
        return value;
    }
    public boolean isReversible(){
        return reversible;
    }
    public Effect reverse(){
        if(reversible){
            Effect res = this.clone();
            res.value *= -1;
            return res;
        }else
            return this;
    }
    @Override
    public Effect clone(){
        return new Effect(this.variableChar, this.value, this.reversible);
    }
}

