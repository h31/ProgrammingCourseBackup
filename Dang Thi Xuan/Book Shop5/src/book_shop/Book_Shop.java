/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package book_shop;
//import Customer_shop.*;
import ChosseInterface.*;

/**
 *
 * @author Mit
 */
public class Book_Shop {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        MyMainUI mainUI=new MyMainUI("Well come to BOOK SHOP! Please choose your choise!!!");
        mainUI.doShow();
        //new BookMS().setVisible(true);
        //new CustomerMS().setVisible(true);
    }
}
