/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;

/**
 *
 * @author Vlad
 */
public class vertice
{
    public vertice(String _name, int _x, int _y)
    {
        name = _name;
        x = _x;
        y = _y;
    }
    private int x, y;
    
    private String name;
    
    public void setName(String _name)
    {
        name = _name;
    }
    
    
    // Флаг для технических нужд
    private int flag;
    public void setFlag(int _flag)
    {
        flag = _flag;
    }
    public int getFlag()
    {
        return flag;
    }
    
    
    public int getY()
    {
        return y;
    }
    public int getX()
    {
        return x;
    }
    public String getName()
    {
        return name;
    }
    
    public int getDistanceSquare(int x, int y) 
    {
        return (x-this.x)*(x-this.x)+(y-this.y)*(y-this.y);
    }
}
