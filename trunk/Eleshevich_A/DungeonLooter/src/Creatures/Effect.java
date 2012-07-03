package Creatures;

import Constants.CreatChar;

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
    public boolean equals(Object obj){
        if(obj.getClass().equals(this.getClass())){
            Effect eff = (Effect)obj;
            return reversible == eff.reversible && variableChar.equals(eff.variableChar) && value == eff.value;
        }else
            return false;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + (this.reversible ? 1 : 0);
        hash = 97 * hash + (this.variableChar != null ? this.variableChar.hashCode() : 0);
        hash = 97 * hash + this.value;
        return hash;
    }
    @Override
    public Effect clone(){
        return new Effect(this.variableChar, this.value, this.reversible);
    }
}

