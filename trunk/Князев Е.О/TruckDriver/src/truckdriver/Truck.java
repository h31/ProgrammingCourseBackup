package truckdriver;

import java.awt.Image;
import java.util.ArrayList;
import java.util.List;

public class Truck {
    
    public static final int WIDTH = 60;
    public static final int HEIGHT = 32;
    
    private Image image;
    private List<GodCountPair> gods;
    private double money;
    
    public Truck() {
        image = null;
        gods = new ArrayList<>();
        money = 100;
    }
    
    public Truck(Image image, List<GodCountPair> gods, double money) {
        this.image = image;
        this.gods = gods;
        this.money = money;
    }
    
    public Image getImage() {
        return image;
    }
    
    public List<GodCountPair> getGods() {
        return gods;
    }
    
    public double getMoney() {
        return money;
    }
    
    public void setImage(Image image) {
        this.image = image;
    }
    
    public void setGods(List<GodCountPair> gods) {
        this.gods = gods;
    }
    
    public void setMoney(double money) {
        this.money = money;
    }
    
    public void selGod(God god, int count, City city) {
        int index = -1;
        for (int i = 0; i < gods.size(); i++) {
            if (god.getTitle().equals(gods.get(i).getGod().getTitle())) {
                index = i;
                break;
            }
        }
        int selCount = city.selGod(gods.get(index).getGod(), count);
        money += gods.get(index).selCount(selCount);
    }
    
    public void buyGod(God god, int count, City city) {
        int buyCount = city.buyGod(god, count);
        int index = -1;
        for (int i = 0; i < gods.size(); i++) {
            if (god.getTitle().equals(gods.get(i).getGod().getTitle())) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            GodCountPair item = new GodCountPair(god.clone(), 0);
            gods.add(item);
            index = gods.indexOf(item);
        }
        money -= gods.get(index).buyCount(buyCount);
    }
    
}