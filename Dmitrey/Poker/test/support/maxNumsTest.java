/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package support;

import java.util.ArrayList;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Дмитрий
 */
public class maxNumsTest {
    
    public maxNumsTest() {
    }

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of maxn method, of class maxNums.
     */
    @Test
    public void testMaxn() {
        System.out.println("maxn");
        ArrayList n = new ArrayList();
        n.add(1);
        n.add(2);
        n.add(3);
        n.add(3);
        n.add(4);
        n.add(3);
        
        int expResult = 3;
        int result = maxNums.maxn(n);
        assertEquals(expResult, result);
    }
}
