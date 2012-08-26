package truckdriver;

import truckdriver.resources.Resources;
import java.awt.Point;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

public class Interpreter {
    
    private Truck truck;
    private List<City> cities;
    private City truckCity;
    private int[][] graph;
    
    public Interpreter() {
        this.cities = Resources.cities;
        this.truck = new Truck();
        truck.setImage(Resources.truck);
    }
    
    public void generateBuyGods() {
        Random random = new Random();
        for (int i = 0; i < cities.size(); i++) {
            for (GodCountPair item : cities.get(i).getSelGods()) {
                item.setCount(random.nextInt(10) + 2);
            }
        }
        for (int i = 0; i < cities.size(); i++) {
            cities.get(i).getBuyGods().clear();
            List<GodCountPair> selGods = cities.get(i).getSelGods();
            Set<God> set = new HashSet<>();
            for (int j = 0; j < selGods.size(); j++) {
                set.add(selGods.get(j).getGod());
            }
            
            for (int j = 0; j < Resources.gods.length; j++) {
                if (!set.contains(Resources.gods[j])) {
                    cities.get(i).getBuyGods().add(new GodCountPair(
                            Resources.gods[j], random.nextInt(10) + 2));
                }
            }
        }
    }
    
    public void initialize() {
        truckCity = cities.get(0);
        generateBuyGods();
        graph = new int[cities.size()][cities.size()];
        for (int i = 0; i < cities.size(); i++) {
            int count = 0;
            for (int k = 0; k < cities.size(); k++) {
                count += graph[i][k];
            }
            if (count >= 2) continue;
            Point p1 = cities.get(i).getPosition();
            int min1, min2;
            min1 = min2 = Integer.MAX_VALUE;
            for (int j = 0; j < cities.size(); j++) {
                if (i == j) continue;
                if (graph[i][j] == 1) continue;
                count = 0;
                for (int k = 0; k < cities.size(); k++) {
                    count += graph[j][k];
                }
                if (count >= 2) continue;
                Point p2 = cities.get(j).getPosition();
                double lenght = Math.sqrt(Math.pow(p2.x - p1.x, 2.0) + 
                        Math.pow(p2.y - p1.y, 2.0));
                if (lenght <= min1) {
                    min1 = j;
                }
                else if (lenght <= min2) {
                    min2 = j;
                }
            }
            if (min1 != Integer.MAX_VALUE) {
                graph[i][min1] = 1;
                graph[min1][i] = 1;
            }
            if (min2 != Integer.MAX_VALUE) {
                graph[i][min2] = 1;
                graph[min2][i] = 1;
            }
        }
    }
    
    public Truck getTruck() {
        return truck;
    }
    
    public City getTruckCity() {
        return truckCity;
    }
    
    public int[][] getGraph() {
        return graph;
    }
    
    public void setTruckCity(City city) {
        this.truckCity = city;
    }
    
}