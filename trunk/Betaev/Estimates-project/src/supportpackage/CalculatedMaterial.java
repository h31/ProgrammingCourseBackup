/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package supportpackage;

/**
 *
 * @author Sergey
 */
public class CalculatedMaterial {
    private long Id;
    private String Name;
    private String Unit;
    private double Amount;
    private double Price;

    public CalculatedMaterial() {
        Id = 0;
        Name = "";
        Unit = "";
        Amount = 0;
        Price = 0;
    }
    
    public CalculatedMaterial(long Id, String Name, String Unit, double Amount, double Price) {
        this.Id = Id;
        this.Name = Name;
        this.Unit = Unit;
        this.Amount = Amount;
        this.Price = Price;
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
    
    public double getAmount() {
        return Amount;
    }
    
    public double getPrice() {
        return Price;
    }
    
    public void IncreaseAmount(double inc) {
        Amount += inc;
    }
    
    public void RoundAmount(double RoundingStep, double RoundingBorder) {
        double Remainder = Amount % RoundingStep;
        Amount -= Remainder;
        if (Remainder > RoundingBorder)
        {
            Amount += RoundingStep;
        }
    }    
}

