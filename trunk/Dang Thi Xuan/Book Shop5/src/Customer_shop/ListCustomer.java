/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Customer_shop;
import java.io.Serializable;
import java.util.ArrayList;

/**
 *
 * @author Mit
 */
public class ListCustomer implements Serializable{
    private static final long serialVersionUID = -8865071229701963561L;
    private String ListCusID;
    private String Location;
    private ArrayList<TypeCustomer> TypeCusList;

    public void setListCusID(String ListCusID){
            this.ListCusID=ListCusID;
        }
    public String getListCusID(){
        return ListCusID;
        }
    public void setLocation(String Location){
        this.Location=Location;
        }
    public String getLocation(){
        return Location;
        }
    public ListCustomer(String location, String ListCusID) {
        Location = location;
        ListCusID = ListCusID;
        TypeCusList=new ArrayList<TypeCustomer>();
        }

    //----------------------------------------------------------
    public boolean AddType(TypeCustomer s){
        if(TypeCusList.contains(s))
            return false;
        return TypeCusList.add(s);
        }
    //-----------------------------------------------------------
    public TypeCustomer GetTypeCus(String sID){
        TypeCustomer s=new TypeCustomer(sID," ");
        if(!TypeCusList.contains(s))
            return null;
        return TypeCusList.get(TypeCusList.indexOf(s));
        }

    public TypeCustomer getTypeCus(int index){
        if(index<0||index>TypeCusList.size())
            return null;
        return TypeCusList.get(index);
        }
    //-------------------Remove 1 type customer in the list--------
    public boolean RemoveTypeCus(String sID){
        TypeCustomer s=new TypeCustomer(sID," ");
        if(!TypeCusList.contains(s))
            return false;
        return TypeCusList.remove(s);
        }
    //--------------------------------------------------------
    public int Count(){
            return TypeCusList.size();
        }
    
    public ArrayList<TypeCustomer>getTypeCusList()
    {
        return TypeCusList;
    }
}
