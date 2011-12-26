package DataHandlers;

import BankSystems.Account;
import Sums.InvalidFormatException;
import Sums.Sum;
import java.util.LinkedList;
import java.util.List;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;

/**
 * @author Andrew
 */
public class BankDataHandler extends DefaultHandler{
    List<Account> accounts;
    
    @Override
    public void startDocument(){
        accounts = new LinkedList<Account>();
    }
    
    @Override
    public void startElement(String uri, String name, String qname, Attributes attrs){
        if(qname.equals(Tags.acc))
            try{
                accounts.add(new Account(attrs.getValue("name"), attrs.getValue("number"), Sum.parseSum(attrs.getValue("cash"))));
            }catch(InvalidFormatException e){}
    }
    
    public List<Account> getLoadedAccounts(){
        return accounts;
    }
}
