/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package ChosseInterface;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import Customer_shop.*;
import book_shop.*;

/**
 *
 * @author Mit
 */
public class MyMainUI extends JFrame{
    private static final long serialVersionUID = 1L;
    public MyMainUI(String title)
        {
        setTitle(title);
        }

    public void doShow()
        {
        setSize(500,100);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        addControl();
        setVisible(true);
        }

    public void addControl()
        {
        JPanel pnBox=new JPanel();
        JButton btn1=new JButton("Open List Books");
        JButton btn2=new JButton("Open List Customers");
        pnBox.add(btn1);
        pnBox.add(btn2);
        btn1.addActionListener(new ActionListener() {

                    @Override
        public void actionPerformed(ActionEvent arg0) {

        new BookMS().setVisible(true);
        }

        });

        btn2.addActionListener(new ActionListener() {

                    @Override
        public void actionPerformed(ActionEvent arg0) {
        new CustomerMS().setVisible(true);
        }

        });

        Container con=getContentPane();
        con.add(pnBox);

        }

    /*public static void main(String[] args) {
        MyMainUI mainUI=new MyMainUI("Demo OPen Another Windows");
        mainUI.doShow();
        }*/

    }
