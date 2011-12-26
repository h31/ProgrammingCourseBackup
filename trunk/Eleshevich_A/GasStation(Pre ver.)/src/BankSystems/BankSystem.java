package BankSystems;

/**
 * @author Andrew
 */

import Sums.Sum;
import Payments.PaymentException;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

/**
 * Класс, имитирующий банковскую систему 
 */
public class BankSystem {
    /**
     * Коллекция, содержащая банковские счета
     */
    List<Account> accounts;
    
    public BankSystem(){
        accounts = new LinkedList<Account>();
    }
    public BankSystem(Collection<Account> accounts){
        this.accounts = new LinkedList<Account>();
        this.accounts.addAll(accounts);
    }
    public void add(Account acc){
        accounts.add(acc);
    }
    public void addAccounts(Collection<Account> accounts){
        this.accounts.addAll(accounts);
    }
    
    /**
     * Метод симулирует проведение операции снятия денежной суммы со счёта
     * @param CardNumber Номер банковской карты
     * @param sum сумма, которую необходимо снять
     * @throws BankException исключение, содержащее сообщение о причине ошибки операции:
     * О несуществовании счёта с таким номером или недостатке средств на счёте
     */
    public void MkPayment(String CardNumber, Sum sum) throws PaymentException{
        Account account = null;
        for(Account acc: accounts){
            if(acc.CardNumber.contentEquals(CardNumber)){
                account = acc;
                break;
            }
        }
        if(account == null)
            throw new BankException(BankException.error.NotFound);
        if(sum.greater(account.CashAmount))
            throw new BankException(BankException.error.NotEnought);
        account.CashAmount = account.CashAmount.sub(sum);
    }
    public List<Account> getAccounts(){
        return accounts;
    }
}

/**
 * Класс исключения, необходимый для сообщения пользователю причины неудачи снятия денег
 */
class BankException extends PaymentException{
    enum error { NotFound, NotEnought }
    error err;
    @Override
    public String getMessage(){
        switch(err){
            case NotFound: return "Счёт с таким номером не найден";
            case NotEnought: return "Недостаточно средств на счёте";
        }
        return "Неизвестная ошибка";
    }
    BankException(error err){
        this.err = err;
    }
}