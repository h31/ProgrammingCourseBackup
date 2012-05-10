/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;

import org.jdom.Element;

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
    
    public Element getXMLElement() {
        final Element root = new Element("city");
        root.setAttribute("name", name);
        root.setAttribute("x", String.valueOf(x));
        root.setAttribute("y", String.valueOf(y));
        return root;
    }

    /**
     * Сформировать город по XML-элементу
     * @param element XML-элемент
     * @return соответствующий город
     */
    public static vertice readXML(Element element) {
        return new vertice(element.getAttributeValue("name"),
                Integer.parseInt(element.getAttributeValue("x")),
                Integer.parseInt(element.getAttributeValue("y")));
    }
}
