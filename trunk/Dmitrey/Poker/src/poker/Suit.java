/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package poker;

public enum Suit {
    SPADE, HEART, DIAMOND, CLUB;

    public Suit next()
    {
        if(this.ordinal() == SPADE.ordinal()) return HEART;
        if(this.ordinal() == HEART.ordinal()) return DIAMOND;
        if(this.ordinal() == DIAMOND.ordinal()) return CLUB;
        else return SPADE;
    }

}