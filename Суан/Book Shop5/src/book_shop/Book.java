/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package book_shop;
import java.io.Serializable;

/**
 *
 * @author Mit
 */
public class Book implements Serializable{
    
    private static final long serialVersionUID=1L;
    private String bookID;
    private String bookTitle;
    private String authorName;
    private double price;
    private int noPages;
    
    public Book (String bookID, String bookTitle, String authorName, double price, int noPages){
        this.authorName= authorName;
        this.bookID= bookID;
        this.bookTitle= bookTitle;
        this.price= price;
        this.noPages= noPages;
    }
    
    public Book(){
        this("", "", "", 0.0 , 0);
    }
//----------------------------------------------------------------------    
    public String getBookID(){
        return bookID;
    }
    public void setBookID(String bookID){
        this.bookID= bookID;
    }
    
//--------------------------------------------------------
    public String getBookTitle(){
        return bookTitle;
    }
    public void setBookTitle(String bookTitle){
        this.bookTitle= bookTitle;
    }
//---------------------------------------------------------
    public String getAuthorName(){
        return authorName;
    }
    public void setAuthorName(String authorName){
        this.authorName= authorName;
    }
    
//------------------------------------------------------------
     public double getPrice(){
        return price;
    }
    public void setNoPages(double price){
        this.price= price;
    }
//------------------------------------------------------------
    public int getNoPages(){
        return noPages;
    }
    public void setNoPages(int noPages){
        this.noPages= noPages;
    }
    
    
    @Override
    public String toString()
    {
        return bookID+"     "+bookTitle+"     "+authorName+"     "+price+"     "+noPages;
    }
   
}
