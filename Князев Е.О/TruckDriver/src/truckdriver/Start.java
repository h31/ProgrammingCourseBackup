package truckdriver;

import truckdriver.resources.Resources;
import truckdriver.gui.SettingsFrame;

public class Start {
    
    public static Interpreter inter = new Interpreter();
    
    public static void main(String[] args) {
        Resources.initialize();
        new SettingsFrame().start();
    }
}