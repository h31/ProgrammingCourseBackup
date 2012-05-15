/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package support;

import poker.Player;
import gui.MainFrame;
import java.util.ArrayList;
import junit.framework.Assert;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import javax.swing.JFrame;
import static org.junit.Assert.*;

/**
 *
 * @author Дмитрий
 */
public class CircleArrayTest {
    
    public CircleArrayTest() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception {
        CircleArray test = new CircleArray();
        for(char i = 0; i<15; i++)
        test.add(i);
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }
    
    @Before
    public void setUp() {
        CircleArray test = new CircleArray();
        for(char i = 0; i<15; i++)
        test.add(i);
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of add method, of class CircleArray.
     */
    @Test
    public void testAdd() {
        System.out.println("add");
        char ob = 't';
        CircleArray instance = new CircleArray();
        int size = instance.size();
        instance.add(ob);
        assertEquals(size+1, instance.size());
    }

    /**
     * Test of addAll method, of class CircleArray.
     */
    

    /**
     * Test of setInd method, of class CircleArray.
     */
    @Test
    public void testSetInd() {
        System.out.println("setInd");
        int i = 0;
        CircleArray instance = new CircleArray();
        instance.setInd(i);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of size method, of class CircleArray.
     */
    @Test
    public void testSize() {
        System.out.println("size");
        CircleArray instance = new CircleArray();
        int expResult = 0;
        int result = instance.size();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of resetInd method, of class CircleArray.
     */
    @Test
    public void testResetInd() {
        System.out.println("resetInd");
        CircleArray instance = new CircleArray();
        instance.resetInd();
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of get method, of class CircleArray.
     */
    @Test
    public void testGet() {
        System.out.println("get");
        int i = 2;
        CircleArray<Player> instance = new CircleArray();
        Player fst = new Player(1);
        Player scnd = new Player(2);
        instance.add(fst);
        instance.add(scnd);
        assertEquals(instance.get(i).getId(), fst.getId());
    }

    /**
     * Test of getInd method, of class CircleArray.
     */
    @Test
    public void testGetInd() {
        System.out.println("getInd");
        CircleArray instance = new CircleArray();
        int expResult = 0;
        int result = instance.getInd();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getNext method, of class CircleArray.
     */
    @Test
    public void testGetNext() {
        System.out.println("getNext");
        CircleArray instance = new CircleArray();
        Object expResult = null;
        Object result = instance.getNext();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of remove method, of class CircleArray.
     */
    @Test
    public void testRemove() {
        System.out.println("remove");
        int i = 0;
        CircleArray instance = new CircleArray();
        Object expResult = null;
        Object result = instance.remove(i);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of removeAll method, of class CircleArray.
     */
    @Test
    public void testRemoveAll() {
        System.out.println("removeAll");
        CircleArray instance = new CircleArray();
        instance.removeAll();
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
}
