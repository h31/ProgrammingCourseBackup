
package race;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.io.File;

public class Carview

{
    private Car car;
    //private Image image;
    
    public Carview(Car car_)
    {
        this.car=car_;
        
    }
    
    void paint(Graphics g)
    {
        g.setColor(car.get_color());
        g.fillRect(car.get_x(),car.get_y(),car.get_width(),car.get_heigth());
        //g.drawImage(image, car.get_x(), y, null);
        
    }
}
