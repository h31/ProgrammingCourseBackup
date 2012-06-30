/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;
import org.jdom.output.XMLOutputter;
import Graph.edge.*;

/**
 *
 * @author Vlad
 */
public class graph
{
    
    private ArrayList<edge> Edge;
    private ArrayList<vertice> Vertice;
    
    public ArrayList<ArrayList<vertice>> MinArray;
    
    public graph()
    {
        Edge = new ArrayList<edge>();
        Vertice = new ArrayList<vertice>();
        MinArray = new ArrayList<ArrayList<vertice>>();
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
    public int existEdge(edge _edge)
    {
        for (int i = 0; i<Edge.size();i++)
        {
            // if(Edge.get(i).equals(_edge)) return true;
            if((Edge.get(i).getVert1().equals(_edge.getVert1()) && Edge.get(i).getVert2().equals(_edge.getVert2())) || (Edge.get(i).getVert1().equals(_edge.getVert2()) && Edge.get(i).getVert2().equals(_edge.getVert1()))) return Edge.get(i).getDistance();
        }
        return 0;
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
    
    public void writeXML(final File file) throws IOException {
        final Element root = new Element("graph");
        final Element citiesRoot = new Element("vertices");
        final List<Element> cityElements = new LinkedList<Element>();
        for (vertice city : Vertice) {
            cityElements.add(city.getXMLElement());
        }
        citiesRoot.setContent(cityElements);
        root.addContent(citiesRoot);
        final Element waysRoot = new Element("edges");
        final List<Element> wayElements = new LinkedList<Element>();
        for (edge way: Edge) {
            final Element wayElement = way.getXMLElement();
            final int startIndex = Vertice.indexOf(way.getVert1());
            wayElement.setAttribute("start", String.valueOf(startIndex));
            final int finishIndex = Vertice.indexOf(way.getVert2());
            wayElement.setAttribute("finish", String.valueOf(finishIndex));
            wayElements.add(wayElement);
        }
        waysRoot.setContent(wayElements);
        root.addContent(waysRoot);
        final Document document = new Document(root);
        final XMLOutputter outputter = new XMLOutputter();
        outputter.output(document, new FileOutputStream(file));
    }

    /**
     * Читаем XML-файл
     * @param file XML-файл
     * @throws IOException при ошибке ввода-вывода
     * @throws JDOMException при ошибке разбора XML
     */
    public void readXML(final File file) throws IOException, JDOMException {
        final SAXBuilder builder = new SAXBuilder();
        final Document document = builder.build(file);
        final Element root = document.getRootElement();
        Vertice.clear();
        final Element citiesRoot = root.getChild("vertices");
        for (Object obj: citiesRoot.getChildren()) {
            Vertice.add(vertice.readXML((Element)obj));
        }
        Edge.clear();
        final Element waysRoot = root.getChild("edges");
        for (Object obj: waysRoot.getChildren()) {
            final Element wayElem = (Element)obj;
            final edge way = edge.readXML(wayElem);
            final int startIndex =
                    Integer.parseInt(wayElem.getAttributeValue("start"));
            way.setVert1(Vertice.get(startIndex));
            final int finishIndex =
                    Integer.parseInt(wayElem.getAttributeValue("finish"));
            way.setVert2(Vertice.get(finishIndex));
            Edge.add(way);
        }
    }
    
    public int[][] optimiser(graph gr)
    {
        int d[][] = new int[Vertice.size()][Vertice.size()];
        int g[][] = new int[Vertice.size()][Vertice.size()];
        
        for (int i  = 0; i<Vertice.size();i++)
        {
            for (int n = 0;n<Vertice.size();n++)
            {
                edge ed  = new edge(gr.getVertice().get(i), gr.getVertice().get(n), EdgeKind.NOTORIENTED, 0);
                if (existEdge(ed)!=0) d[i][n] = existEdge(ed);
                else d[i][n] = 20000000;
            }
        }
        
        for(int i = 1;i<Vertice.size()+1;i++)
        {
            for(int j=0; j<Vertice.size();j++)
            {
                for (int k=0;k<Vertice.size();k++)
                {
                    if (d[j][k]>d[j][i-1]+d[i-1][k])
                    {
                         d[j][k]=d[j][i-1]+d[i-1][k];
                         //d[k][j]=d[j][j-1]+d[i-1][k];
                    }
                }
            }
        }
        
        return d;
    }
    
    public int minpath(graph gr, vertice vr1, vertice vr2)
    {
        int min[][] = new int[Vertice.size()+1][Vertice.size()+1];
        
        min = optimiser(gr);        
        int minpth = 0;
        
        int i = Vertice.indexOf(vr1);
        int n = Vertice.indexOf(vr2);
        
        minpth = min[i][n];
        
        return minpth;
    }
}
