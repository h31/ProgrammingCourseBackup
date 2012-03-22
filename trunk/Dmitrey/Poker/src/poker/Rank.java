/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package poker;

public enum Rank {
    tw, th, fr, fv, sx, sv, eh, nn, tn, J, Q, K, A;

    public boolean older(Rank r)
    {
        return this.ordinal() > r.ordinal();
    }
    public boolean equals(Rank r)
    {
        return this.ordinal() == r.ordinal();
    }
    public Rank next()
    {
        if(this.ordinal() == tw.ordinal()) return th;
        if(this.ordinal() == th.ordinal()) return fr;
        if(this.ordinal() == fr.ordinal()) return fv;
        if(this.ordinal() == fv.ordinal()) return sx;
        if(this.ordinal() == sx.ordinal()) return sv;
        if(this.ordinal() == sv.ordinal()) return eh;
        if(this.ordinal() == eh.ordinal()) return nn;
        if(this.ordinal() == nn.ordinal()) return tn;
        if(this.ordinal() == tn.ordinal()) return J;
        if(this.ordinal() == J.ordinal()) return Q;
        if(this.ordinal() == Q.ordinal()) return K;
        if(this.ordinal() == K.ordinal()) return A;
        else return tw;
    }
    
}
