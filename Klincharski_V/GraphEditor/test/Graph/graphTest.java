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
        vertice vr1 = new vertice("Узел0", 0 , 0);
        vertice vr2 = new vertice("Узел1", 1, 0);
        vertice vr3 = new vertice("Узел2", 1, 0);
        
        
        edge ed1 = new edge(vr1, vr2, edge.EdgeKind.NOTORIENTED, 10);
        edge ed2 = new edge(vr1, vr3, edge.EdgeKind.NOTORIENTED, 24);
        
        graph instance = new graph();
        instance.addVertice(vr1);instance.addVertice(vr2);instance.addVertice(vr3);
        instance.addEdge(ed1);
        int expResult1 = 10;
        int expResult2 = 0;
        int result1 = instance.existEdge(ed1);
        int result2 = instance.existEdge(ed2);
        
        assertEquals(expResult1, result1);
        assertEquals(expResult2, result2);
    }
    /**
     * Test of minpath method, of class graph.
     */
    public void testMinpath()
    {
        System.out.println("minpath");
        
        graph gr = null;
        vertice vr1 = new vertice("Узел0", 0 , 0);
        vertice vr2 = new vertice("Узел1", 1, 0);
        vertice vr3 = new vertice ("Узел2", 2, 2);
        vertice vr4 = new vertice("Узел3", 5, 5);
        
        edge ed1 = new edge(vr1, vr2, edge.EdgeKind.NOTORIENTED, 10);
        edge ed2 = new edge(vr1, vr3, edge.EdgeKind.NOTORIENTED, 2);
        edge ed3 = new edge(vr3, vr2, edge.EdgeKind.NOTORIENTED, 2);
        
        graph instance = new graph();
        instance.addVertice(vr1);instance.addVertice(vr2);instance.addVertice(vr3);instance.addVertice(vr4);
        instance.addEdge(ed1);instance.addEdge(ed2);instance.addEdge(ed3);
        
        int expResult1 = 4;
        int expResult2 = 20000000;
        int expResult3 = 2;
        
        int result1 = instance.minpath(instance, vr2, vr1);
        int result2 = instance.minpath(instance, vr1, vr4);
        int result3 = instance.minpath(instance, vr1, vr3);
        
        assertEquals(expResult1, result1);
        assertEquals(expResult2, result2);
        assertEquals(expResult3, result3);        
    }
    
    public void testAddVerticeNameExist()
    {
        System.out.println("VerticeNameExist");
        
        vertice vr1 = new vertice("Узел0", 0 , 0);
        vertice vr2 = new vertice("Узел1", 1, 0);
        vertice vr3 = new vertice ("Узел2", 2, 2);
        String name1 = "Узел4";
        String name2 = "Узел1";
        
        graph instance = new graph();
        instance.addVertice(vr1);instance.addVertice(vr2);instance.addVertice(vr3);
        
        boolean expResult1 = false;
        boolean expResult2 = true;
        
        boolean result1 = instance.CheckNameExist(name1);
        boolean result2 = instance.CheckNameExist(name2);
        
        assertEquals(expResult1,result1);
        assertEquals(expResult2,result2);
        
    }
}
