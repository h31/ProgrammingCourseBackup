package sunsystem;

import java.util.ArrayDeque;

public class SunSystem{

    public static void main(String[] args){
        ArrayDeque<Planet> planets = PlanetLoader.loadPlanets("Planets");
        new MainFrame("Солнечная система", planets);
    }
}