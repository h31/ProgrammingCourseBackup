/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;
import java.util.ArrayList;

/**
 *
 * @author Vlad
 */
public class graph
{
    
    private ArrayList<edge> Edge;
    private ArrayList<vertice> Vertice;
    
    public graph()
    {
        Edge = new ArrayList<edge>();
        Vertice = new ArrayList<vertice>();
    }
    
    // Добавление дуги
    public void addEdge(edge _edge)
    {
        Edge.add(_edge);
    }
    
    // Удаление дуги
    public void removeEdge(edge _edge)
    {
        Edge.remove(_edge);
    }
    
    // Получение всех дуг
    public ArrayList<edge> getEdges()
    {
        return Edge;
    }
    
    // Вывод всех вершин
    public void printEdge()
    {
        for (int i = 0; i < Edge.size()-1; i++)
        {
            System.out.println(Edge.get(i));
        }       
    }
    
    
    //Проверка существования дуги
    public boolean existEdge(edge _edge)
    {
        for (int i = 0; i<Edge.size();i++)
        {
            if(Edge.get(i).equals(_edge)) return true;
        }
        return false;
    }
    
    // Добавление вершины
    public void addVertice(vertice _vertice)            
    {
        Vertice.add(_vertice);
    }
    
    // Удаление вершины
    public void removeVertice(vertice _vertice)    
    {
        Vertice.remove(_vertice);
    }
    
    // Получение всех вершин
    public ArrayList<vertice> getVertice()
    {
        return Vertice;
    }
    // Вывод все вершин
    public void printVertice()
    {
        for (int i = 0; i < Vertice.size(); i++)
        {
            System.out.println(Vertice.get(i).getName() + " " + Vertice.get(i).getX() + " " +  Vertice.get(i).getY());
        }        
    }
    
    public vertice getNearestPoint(int x, int y)           
    {
        vertice result = null;
        int minDist = Integer.MAX_VALUE;
        for (vertice _Vertice: Vertice) {
            int dist = _Vertice.getDistanceSquare(x, y);
            if (dist < minDist) {
                minDist = dist;
                result = _Vertice;
            }
        }
        return result;
    }    
    public edge getWayByCoord(int x, int y) {
        for (edge way: Edge) {
            if (way.isInside(x, y)) {
                return way;
            }
        }
        return null;
    }
    
    public edge getWayByCities(vertice start, vertice finish, edge.EdgeKind kind) {
        edge origWay = new edge(start, finish, kind, 0);
        for (edge way: Edge) {
            if (way.equals(origWay))
                return way;
        }
        return null;
    }
}
