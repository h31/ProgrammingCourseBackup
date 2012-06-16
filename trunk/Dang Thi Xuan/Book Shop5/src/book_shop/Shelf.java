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
    
//--------------------------Them 1 cuon sach vao ke-----------------
public boolean AddBook(Book b){
    if(booklist.contains(b))
        return false;
    return booklist.add(b);
    }
    
//-------------------------Bo 1 cuon sanh khoi ke----------------------
public boolean RemoveBook(String bookID) {
    Book b=new Book(bookID,"","",0.0,0);
    if(!booklist.contains(b))
        return false;
    return booklist.remove(b);
    }
//--------------------------Update thong tin sach--------------
public boolean UpdateBookInfos(String bookID,Book newBook) {
    Book b=new Book(bookID,"","",0.0,0);
    if(!booklist.contains(b))
        return false;
    Book old=booklist.get(booklist.indexOf(b));
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
//-------------------------lay book khi biet stt------------------
public Book GetBook(int index){
    if(index<0||index>booklist.size())
        return null;
    return booklist.get(index);
    }
//------------------------So mau tin co trong tap hop---------------------
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
