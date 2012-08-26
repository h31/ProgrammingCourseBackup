package truckdriver.resources;

import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import javax.imageio.ImageIO;
import truckdriver.City;
import truckdriver.God;

public class Resources {
    
    public static List<City> cities = new ArrayList();
    public static God[] gods;
    public static String[] cityNames;
    public static BufferedImage[] images = new BufferedImage[8];
    public static BufferedImage truck;
    
    public static void initialize() {
        gods = new God[] {
            new God("Золото", 90.0, null),
            new God("Дерево", 20.0, null),
            new God("Уголь",  30.0, null),
            new God("Железо", 50.0, null),
            new God("Еда",    15.0, null),
            new God("Вода",   15.0, null),
            new God("Камень", 32.0, null),
            new God("Одежда", 24.0, null)
        };
        cityNames = new String[] {
            "Outlaw Town",
            "Pallet Town",
            "Log Tawn",
            "Marinford City",
            "Arabasta City",
            "Vermilion Town",
            "New Bark Town",
            "Whiteleaf Town",
            "Greensphare City",
            "Elizabeth Town",
            "Orange Town",
            "Enies-Lobby City"
        };
        Class cls = new Resources().getClass();
        try {
            URL url = cls.getResource("gold.png");
            images[0] = ImageIO.read(url);
            url = cls.getResource("tree.png");
            images[1] = ImageIO.read(url);
            url = cls.getResource("coal.png");
            images[2] = ImageIO.read(url);
            url = cls.getResource("iron.png");
            images[3] = ImageIO.read(url);
            url = cls.getResource("food.png");
            images[4] = ImageIO.read(url);
            url = cls.getResource("water.png");
            images[5] = ImageIO.read(url);
            url = cls.getResource("stone.png");
            images[6] = ImageIO.read(url);
            url = cls.getResource("clothes.png");
            images[7] = ImageIO.read(url);
            url = cls.getResource("truck.png");
            truck = ImageIO.read(url);
        } catch (IOException ex) {
            System.err.println(ex.toString());
        }
    }
    
}