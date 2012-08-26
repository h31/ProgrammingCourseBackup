package truckdriver;

import truckdriver.resources.Resources;
import java.awt.Image;
import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

public class City {
    
    public static final int WIDTH = 150;
    public static final int HEIGHT = 70;
 
    private String title;
    private Image image;
    private Point position;
    private List<GodCountPair> selGods;
    private List<GodCountPair> buyGods;
    private boolean active = false;
    
    public City() {
        title = "";
        image = null;
        position = new Point(0, 0);
        selGods = new ArrayList<>();
        buyGods = new ArrayList<>();
    }
    
    public City(String title, Image image, Point position, 
            List<GodCountPair> selGods, List<GodCountPair> buyGods) {
        this.title = title;
        this.image = image;
        this.position = position;
        this.selGods = selGods;
        this.buyGods = buyGods;
    }
    
    public void mouseMove(int x, int y) {
        active = false;
        if (x > position.x && x < position.x + WIDTH) {
            if (y > position.y && y < position.y + HEIGHT) {
                int i = Resources.cities.indexOf(Start.inter.getTruckCity());
                int j = Resources.cities.indexOf(this);
                if (Start.inter.getGraph()[i][j] == 1 || i == j) {
                    active = true;
                }
            }
        }
    }
    
    public boolean isOver(int x, int y) {
        boolean res = false;
        if (x > position.x && x < position.x + WIDTH) {
            if (y > position.y && y < position.y + HEIGHT) {
                res = true;
            }
        }
        return res;
    }
    
    public boolean isActive() {
        return active;
    }
    
    public String getTitle() {
        return title;
    }
    
    public Image getImage() {
        return image;
    }
    
    public Point getPosition() {
        return position;
    }
    
    public List<GodCountPair> getSelGods() {
        return selGods;
    }
    
    public List<GodCountPair> getBuyGods() {
        return buyGods;
    }
    
    public void setTitle(String title) {
        this.title = title;
    }
    
    public void setImage(Image image) {
        this.image = image;
    }
    
    public void setPosition(Point position) {
        this.position = position;
    }
    
    public void setSelGods(List<GodCountPair> selGods) {
        this.selGods = selGods;
    }
    
    public void setBuyGods(List<GodCountPair> buyGods) {
        this.buyGods = buyGods;
    }
    
    public int buyGod(God god, int count) {
        int index = -1;
        for (int i = 0; i < selGods.size(); i++) {
            if (selGods.get(i).getGod().getTitle().equals(god.getTitle())) {
                index = i;
                break;
            }
        }
        if (index == -1) return 0;
        int hasCount = selGods.get(index).getCount();
        if (hasCount >= count) {
            selGods.get(index).setCount(hasCount - count);
            return count;
        }
        else {
            selGods.get(index).setCount(0);
            return hasCount;
        }
    }
    
    public int selGod(God god, int count) {
        int index = -1;
        for (int i = 0; i < buyGods.size(); i++) {
            if (buyGods.get(i).getGod().getTitle().equals(god.getTitle())) {
                index = i;
                break;
            }
        }
        if (index == -1) return 0;
        int needCount = buyGods.get(index).getCount();
        if (needCount >= count) {
            buyGods.get(index).setCount(needCount - count);
            return count;
        }
        else {
            buyGods.get(index).setCount(0);
            return needCount;
        }
    }
    
}