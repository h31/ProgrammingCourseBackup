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
        MyMainUI mainUI=new MyMainUI("Welcome to the bookshop! Please select 1 of the 2 choices");
        mainUI.doShow();
        //new BookMS().setVisible(true);
        //new CustomerMS().setVisible(true);
    }
}
