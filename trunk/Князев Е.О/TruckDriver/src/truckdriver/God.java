package truckdriver;

import java.awt.Image;

public class God {
    
    private String title;
    private double price;
    private Image image;
    
    public God() {
        title = "Noname";
        price = 1.0;
        image = null;
    }
    
    public God(String title, double price, Image image) {
        this.title = title;
        this.price = price;
        this.image = image;
    }
    
    public String getTitle() {
        return title;
    }
    
    public double getPrice() {
        return price;
    }
    
    public Image getImage() {
        return image;
    }
    
    public void setTitle(String title) {
        this.title = title;
    }
    
    public void setPrice(double price) {
        this.price = price;
    }
    
    public void setImage(Image image) {
        this.image = image;
    }
    
    @Override
    public God clone() {
        God tmp = new God();
        tmp.image = this.image;
        tmp.price = this.price;
        tmp.title = this.title;
        return tmp;
    }
    
}