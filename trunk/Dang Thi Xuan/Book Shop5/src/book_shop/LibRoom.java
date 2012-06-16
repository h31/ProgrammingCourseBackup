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
public class LibRoom implements Serializable{
    private static final long serialVersionUID = -8865071229701963561L;
    private String RoomID;
    private String Location;
    private ArrayList<Shelf> shelfList;

    public void setRoomID(String RoomID){
            this.RoomID=RoomID;
        }
    public String getRoomID(){
        return RoomID;
        }
    public void setLocation(String Location){
        this.Location=Location;
        }
    public String getLocation(){
        return Location;
        }
    public LibRoom(String location, String roomID) {
        Location = location;
        RoomID = roomID;
        shelfList=new ArrayList<Shelf>();
        }

    //------------------------------them 1 ke mowi vao phong true- neu them dc----------------
    public boolean AddShelf(Shelf s){
        if(shelfList.contains(s))
            return false;
        return shelfList.add(s);
        }
    //------------------Lay ke trong phong khi biet ma so return null neu ko co ke--
    public Shelf GetShelf(String sID){
        Shelf s=new Shelf(sID,"");
        if(!shelfList.contains(s))
            return null;
        return shelfList.get(shelfList.indexOf(s));
        }

    public Shelf getShelf(int index){
        if(index<0||index>shelfList.size())
            return null;
        return shelfList.get(index);
        }
    //-------------------Xoa bo 1 shelf trong room--------
    public boolean RemoveShelf(String sID){
        Shelf s=new Shelf(sID,"");
        if(!shelfList.contains(s))
            return false;
        return shelfList.remove(s);
        }
    //---------------------So ke co trong room----------------
    public int Count(){
            return shelfList.size();
        }
    public ArrayList<Shelf>getShelfList()
    {
        return shelfList;
    }
    }
