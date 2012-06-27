/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;

import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectOutput;
import org.jdom.Element;

/**
 *
 * @author Vlad
 */
public class edge
{
    private vertice vert1, vert2;
    private int colour;
    private int distance;
    private int flag;
    private EdgeKind kind;
    
    public enum EdgeKind
    {
        ORIENTED,
        NOTORIENTED;
        
        @Override
        public String toString()
        {
            switch(this)
            {
                case ORIENTED : return "ориентированный";
                case NOTORIENTED : return "неориентированный";
                default: return "....";
            }
        }
        static public EdgeKind parse(final String string) {
            for (EdgeKind kind: EdgeKind.values()) {
                if (kind.toString().equals(string))
                    return kind;
            }
            return null;
        }
        
        
    }
    
    public EdgeKind getEdgeKind()
    {
        return kind;
    }
    
    public edge(vertice _vert1, vertice _vert2, EdgeKind _kind, int _distance)
    {
        vert1 = _vert1;
        vert2 = _vert2;
        kind = _kind;
        distance = _distance;
    }
    
    // Получение первой вершины
    public vertice getVert1()
    {
        return vert1;
    }
    
    // Получение второй вершины
    public vertice getVert2()
    {
        return vert2;
    }
    
    // Получение названия второй дуги
    public String getVert1Name()
    {
        return vert1.getName();
    }
    
    // Получение название второй дуги
    public String getVert2Name()
    {
        return vert2.getName();
    }
    
    // Установка первой вершины
    public void setVert1(vertice _vert1)
    {
        vert1 = _vert1;
    }
    
    // Установка второй вершины
    public void setVert2(vertice _vert2)
    {
        vert2 = _vert2;
    }
    
    // Получение цвета
    public int getColour()
    {
        return colour;
    }
    
    // Установка цвета
    public void setColour(int _colour)
    {
        colour = _colour;
    }
    
    // Получение длины дуги
    public int getDistance()
    {
        return distance;
    }
    
    // Установка длины дуги
    public void setDistance(int _distance)
    {
        distance = _distance;
    }
    
    public boolean isInside(int x, int y) {
        int x1 = vert1.getX(), x2 = vert2.getX();
        int y1 = vert1.getY(), y2 = vert2.getY();
        if ((x-x1)*(x-x2) > 0)
            return false;
        if ((y-y1)*(y-y2) > 0)
            return false;
        return Math.abs((x2-x)*(x2-x1) + (y2-y)*(y2-y1)) > 
                0.9*Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*
                    Math.sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y));
    }
    
    public void setKind(EdgeKind _kind)
    {
        kind = _kind;
    }
    
    public void setFlag(int _flag)
    {
        flag = _flag;
    }
    
    public int getFlag()
    {
        return flag;
    }
    
    public void writeExternal(ObjectOutput out) throws IOException {
        // Версия
        out.writeInt(1);
        // Информация
        out.writeInt(kind.ordinal());
        out.writeInt(distance);
        out.writeInt(flag);
    }

    /**
     * Чтение пути из объектного потока
     * @param in объектный поток
     * @throws IOException если происходит ошибка ввода-вывода
     */
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        // Версия
        final int version = in.readInt();
        if (version > 1)
            throw new IOException("Ожидалась версия пути 1, а получили " + version);
        // Информация
        final int kindNum = in.readInt();
        for (EdgeKind wk: EdgeKind.values()) {
            if (wk.ordinal()==kindNum) {
                kind = wk;
                break;
            }
        }
        distance = in.readInt();
        flag = in.readInt();
    }

    /**
     * Сформировать XML-элемент по пути
     * @return соответствующий XML-элемент
     */
    public Element getXMLElement() {
        final Element root = new Element("egde");
        root.setAttribute("kind", kind.toString());
        root.setAttribute("flag", String.valueOf(flag));
        root.setAttribute("distance", String.valueOf(distance));
        return root;
    }

    /**
     * Сформировать путь по XML-элементу
     * @param element XML-элемент
     * @return соответствующий путь
     */
    public static edge readXML(Element element) {
        return new edge(null, null,
                EdgeKind.parse(element.getAttributeValue("kind")),
                Integer.parseInt(element.getAttributeValue("distance")));
    }
}
