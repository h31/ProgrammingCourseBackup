package datapackage;

/**
 * Класс описывает запись в БД "материалы":
 * ID в базе, имя, единица измерения, цена.
 * @see datapackage.MaterialDatabaseHelper
 */
public class Material {
    
    private long Id;
    private String Name;
    private String Unit;
    private double Price;
    private double RoundingStep;
    private double RoundingBorder;
        
    public Material(long Id, String Name, String Unit, double Price, double RoundingStep, double RoundingBorder) {
        this.Id = Id;
        this.Name = Name;
        this.Unit = Unit;
        this.Price = Price;
        this.RoundingStep = RoundingStep;
        this.RoundingBorder = RoundingBorder;
    }
    
    public long getId() {
        return Id;
    }
    
    public String getName() {
        return Name;
    }
    
    public String getUnit() {
        return Unit;
    }
    
    public double getPrice() {
        return Price;
    }
    
    public double getRoundingStep() {
        return RoundingStep;
    }
    
    public double getRoundingBorder() {
        return RoundingBorder;
    }
    
    public void setName(String Name) {
        this.Name = Name;
    }
    
    public void setUnit(String Unit) {
        this.Unit = Unit;
    }
    
    public void setPrice(double Price) {
        this.Price = Price;
    }
    
    public void setRoundingStep(double RoundingStep) {
        this.RoundingStep = RoundingStep;
    }
    
    public void setRoundingBorder(double RoundingBorder) {
        this.RoundingBorder = RoundingBorder;
    }
}
