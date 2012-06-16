/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Customer_shop;
import java.io.Serializable;

/**
 *
 * @author Mit
 */
public class Customer implements Serializable{
    
    private static final long serialVersionUID=1L;
    private String cusID;
    private String cusName;
    private String cusAddress;
    private String cusPhone;
    
    public Customer (String cusID, String cusName, String cusAddress, String cusPhone){
        this.cusID= cusID;
        this.cusName= cusName;
        this.cusAddress= cusAddress;
        this.cusPhone= cusPhone;
    }
    
    public Customer(){
        this("", "", "", "");
    }
//----------------------------------------------------------------------    
    public String getCusID(){
        return cusID;
    }
    public void setCusID(String cusID){
        this.cusID= cusID;
    }
    
//--------------------------------------------------------
    public String getCusName(){
        return cusName;
    }
    public void setBookTitle(String cusName){
        this.cusName= cusName;
    }
//---------------------------------------------------------
    public String getCusAddress(){
        return cusAddress;
    }
    public void setCusAddress(String cusAddress){
        this.cusAddress= cusAddress;
    }
    
//------------------------------------------------------------
     public String getCusPhone(){
        return cusPhone;
    }
    public void setCusPhone(String cusPhone){
        this.cusPhone= cusPhone;
    }
    
    
    @Override
    public String toString()
    {
        return cusID+"  "+cusName+"  "+cusAddress+"  "+cusPhone;
    }
}

