package datapackage;

public class Algorithm {
    private long Id;
    private String Name;
    
    public Algorithm(long Id, String Name) {
        this.Id = Id;
        this.Name = Name;
    }
    
    public long getId() {
        return Id;
    }
    
    public String getName() {
        return Name;
    }
    
    public void setName(String Name) {
        this.Name = Name;
    }
}
