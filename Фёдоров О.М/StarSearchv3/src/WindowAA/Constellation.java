/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package WindowAA;

import WindowAA.Line;
import WindowAA.Star;
import javax.swing.*;
import java.awt.*;
/**
 *
 * @author Odar
 */
public class Constellation{
    int ID;
    String Name;
    Star Stars[];
    Line Lines[];    
    public Constellation(int _ID, String _Name, Star _Stars[],Line _Lines[])
    {
        ID=_ID;
        Name=_Name;
        Stars= new Star[_Stars.length];
        for(int i = 0; i < _Stars.length;i++)
            Stars[i] = new Star(_Stars[i]);
        Lines= new Line[_Lines.length];
        if(_Lines ==null)
        {
            //System.out.println("GAVNO");
        }
        for(int i = 0; i < _Lines.length;i++){
            if(_Lines[i] ==null)
        {
            //System.out.println("GAVNO");
        }
            Lines[i] = new Line(_Lines[i].Star1,_Lines[i].Star2);
        }
    }
}

