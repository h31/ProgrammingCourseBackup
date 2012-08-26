package truckdriver;

import truckdriver.gui.CityMarketFrame;

public class GodCountPair {
    
    private God god;
    private int count;
    
    public GodCountPair() {
        god = new God();
        count = 0;
    }
    
    public GodCountPair(God god, int count) {
        this.god = god;
        this.count = count;
    }
    
    public God getGod() {
        return god;
    }
    
    public int getCount() {
        return count;
    }
    
    public void setGod(God god) {
        this.god = god;
    }
    
    public void setCount(int count) {
        this.count = count;
    }
    
    public double selCount(int count) {
        if (count > this.count) {
            int tmpCount = this.count;
            this.count = 0;
            return tmpCount * god.getPrice()* CityMarketFrame.add;
        }
        else {
            this.count -= count;
            return count * god.getPrice() * CityMarketFrame.add;
        }
    }
    
    public double buyCount(int count) {
        this.count += count;
        return count * god.getPrice();
    }
    
}