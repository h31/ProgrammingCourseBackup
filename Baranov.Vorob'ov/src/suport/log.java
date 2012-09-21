/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package suport;

/**
 *
 * @author Дмитрий
 */
public class log {
   
    public static void main(String[] args)
    {
        for(int i = 10; i<1020; i+=10){
            System.out.println((((int)(Math.log(i) / Math.log( 2 )))+1));
        }
    }
}
