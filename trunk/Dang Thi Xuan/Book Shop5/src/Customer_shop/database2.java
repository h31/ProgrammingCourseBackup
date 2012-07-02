/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Customer_shop;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 *
 * @author Mit
 */
public class database2 {
    
    public void SerialObject(Object obj,String filename)throws Exception{
            ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(filename));
            oos.writeObject(obj);
            oos.close();
        }

    public Object DeserialObject(String filename)throws Exception{
            Object obj=null;
            ObjectInputStream ois=new ObjectInputStream(new FileInputStream(filename));
            obj=ois.readObject();
            return obj;
        }
    }

