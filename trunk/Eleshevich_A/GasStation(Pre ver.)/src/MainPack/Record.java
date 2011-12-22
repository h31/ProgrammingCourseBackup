package MainPack;

import java.util.Date;

/**
 * @author Andrew
 */
public class Record {
    Date date;
    DataBase base;
    
    public Record(Date date){
        this.date = date;
        base = new DataBase();
    }
    public Record(Date date, DataBase base){
        this.base = base;
        this.date = date;
    }
    
    public Date getDate(){
        return date;
    }
    public DataBase getDataBase(){
        return base;
    }
    
    @Override
    public boolean equals(Object obj){
        if(obj.getClass().equals(this.getClass())){
            return date.equals(((Record)obj).getDate());
        }else return false;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 43 * hash + (this.date != null ? this.date.hashCode() : 0);
        return hash;
    }
}
