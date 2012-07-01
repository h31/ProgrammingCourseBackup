/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package book_shop;
import java.io.Serializable;
import java.util.ArrayList;

/**
 *
 * @author Mit
 */
public class Shelf implements Serializable{
    
    private static final long serialVersionUID=1L;
    private String ShelfID;
    private String ShelfName;
    private ArrayList<Book>booklist;

    public Shelf(String shelfID, String shelfName) {
            ShelfID = shelfID;
            ShelfName = shelfName;
            booklist=new ArrayList<Book>();
        }
    public String getShelfID() {
            return ShelfID;
        }
    public void setShelfID(String shelfID) {
            ShelfID = shelfID;
        }
    public String getShelfName() {
            return ShelfName;
        }
    public void setShelfName(String shelfName) {
            ShelfName = shelfName;
        }
    
//--------------------------add a new book on the shelf-----------------
public boolean AddBook(Book b){
    if(booklist.contains(b))
        return false;
    return booklist.add(b);
    }
    
//-------------------------remove a book off the shelf----------------------
public boolean RemoveBook(Book b) {
   // Book b=new Book(bookID,"","",0.0,0);
    if(!booklist.contains(b))
        return false;
    return booklist.remove(b);
    }
//--------------------------Update information of the book--------------
public boolean UpdateBookInfos(Book oldBook,Book newBook) {
    //Book b=new Book(bookID,"","",0.0,0);
    if(!booklist.contains(oldBook))
        return false;
    Book old=booklist.get(booklist.indexOf(oldBook));
    old.setBookTitle(newBook.getBookTitle());
    old.setAuthorName(newBook.getAuthorName());
    old.setNoPages(newBook.getNoPages());
    return true;
    }
public Book GetBook(String id){
    Book b=new Book(id,"","",0.0,0);
    if(!booklist.contains(b))
        return null;
    return booklist.get(booklist.indexOf(b));
    }
//-------------------------get a book = the serial number------------------
public Book GetBook(int index){
    if(index<0||index>booklist.size())
        return null;
    return booklist.get(index);
    }
//-----------------------------------------------------------------------
public int Count(){
        return booklist.size();
    }
    @Override
public String toString()
{
    return ShelfID+"  "+ShelfName;
}
public ArrayList<Book>getListBook()
{
    return booklist;
}
}
