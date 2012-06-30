/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Graph;

import Graph.edge.EdgeKind;
import java.io.File;
import java.util.ArrayList;
import junit.framework.TestCase;

/**
 *
 * @author Vlad
 */
public class graphTest extends TestCase
{
    
    public graphTest(String testName)
    {
        super(testName);
    }
    
    @Override
    protected void setUp() throws Exception
    {
        super.setUp();
    }
    
    @Override
    protected void tearDown() throws Exception
    {
        super.tearDown();
    }
    public void testExistEdge()
    {
        System.out.println("existEdge");
        vertice vr1 = new vertice("1", 0 , 0);
        vertice vr2 = new vertice("2", 1, 0);
        
        edge ed1 = new edge(vr1, vr2, edge.EdgeKind.NOTORIENTED, 10);
        
        graph instance = new graph();
        instance.addVertice(vr1);instance.addVertice(vr2);
        instance.addEdge(ed1);
        int expResult = 10;
        int result = instance.existEdge(ed1);
        
        assertEquals(expResult, result);
    }
    /**
     * Test of minpath method, of class graph.
     */
    public void testMinpath()
    {
        System.out.println("minpath");
        
        graph gr = null;
        vertice vr1 = new vertice("1", 0 , 0);
        vertice vr2 = new vertice("2", 1, 0);
        vertice vr3 = new vertice ("3", 2, 2);
        
        edge ed1 = new edge(vr1, vr2, edge.EdgeKind.NOTORIENTED, 10);
        edge ed2 = new edge(vr1, vr3, edge.EdgeKind.NOTORIENTED, 2);
        edge ed3 = new edge(vr3, vr2, edge.EdgeKind.NOTORIENTED, 2);
        
        graph instance = new graph();
        instance.addVertice(vr1);instance.addVertice(vr2);instance.addVertice(vr3);
        instance.addEdge(ed1);instance.addEdge(ed2);instance.addEdge(ed3);
        
        int expResult = 4;
        
        int result = instance.minpath(instance, vr2, vr1);
        assertEquals(expResult, result);
    }
}
