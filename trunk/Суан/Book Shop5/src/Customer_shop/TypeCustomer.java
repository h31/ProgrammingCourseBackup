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
    
//--------------------------Add new customer in the list-----------------
public boolean AddCus(Customer b){
    if(cuslist.contains(b))
        return false;
    return cuslist.add(b);
    }
    
//-------------------------Remove 1 customer in the list----------------------
public boolean RemoveCus(Customer b) {
    //Customer b=new Customer(cusID,"","","");
    //System.out.println(b.toString());
    if(!cuslist.contains(b))
        return false;
    return cuslist.remove(b);
    }
//--------------------------Update information of customer--------------
public boolean UpdateCusInfos(Customer oldCus,Customer newCus) {
     if(!cuslist.contains(oldCus))
        return false;
    Customer old=cuslist.get(cuslist.indexOf(oldCus));
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
//-------------------------------------------------------------
public Customer GetCus(int index){
    if(index<0||index>cuslist.size())
        return null;
    return cuslist.get(index);
    }
//---------------------------------------------------------
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
