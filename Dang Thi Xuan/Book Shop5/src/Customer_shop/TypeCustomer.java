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
public class TypeCustomer implements Serializable{
    private static final long serialVersionUID = 3225680073019589887L;
    private String TypeID;
    private String TypeName;
    private ArrayList<Customer>cuslist;

    public TypeCustomer(String typeID, String typeName) {
            TypeID = typeID;
            TypeName = typeName;
            cuslist=new ArrayList<Customer>();
        }
    public String getTypeID() {
            return TypeID;
        }
    public void setTypeID(String typeID) {
            TypeID = typeID;
        }
    public String getTypeName() {
            return TypeName;
        }
    public void setTypeName(String typeName) {
            TypeName = typeName;
        }
    
//--------------------------Them 1 cuon sach vao ke-----------------
public boolean AddCus(Customer b){
    if(cuslist.contains(b))
        return false;
    return cuslist.add(b);
    }
    
//-------------------------Bo 1 cuon sanh khoi ke----------------------
public boolean RemoveCus(String cusID) {
    Customer b=new Customer(cusID,"","","");
    if(!cuslist.contains(b))
        return false;
    return cuslist.remove(b);
    }
//--------------------------Update thong tin sach--------------
public boolean UpdateCusInfos(String cusID,Customer newCus) {
    Customer b=new Customer(cusID,"","","");
    if(!cuslist.contains(b))
        return false;
    Customer old=cuslist.get(cuslist.indexOf(b));
    old.setBookTitle(newCus.getCusName());
    old.setCusAddress(newCus.getCusAddress());
    old.setCusPhone(newCus.getCusPhone());
    return true;
    }
public Customer GetCus(String id){
    Customer b=new Customer(id,"","","");
    if(!cuslist.contains(b))
        return null;
    return cuslist.get(cuslist.indexOf(b));
    }
//-------------------------lay book khi biet stt------------------
public Customer GetCus(int index){
    if(index<0||index>cuslist.size())
        return null;
    return cuslist.get(index);
    }
//------------------------So mau tin co trong tap hop---------------------
public int Count(){
        return cuslist.size();
    }

@Override
public String toString()
{
    return TypeID+"  "+TypeName;
}
public ArrayList<Customer>getCusList()
{
    return cuslist;
}
}
