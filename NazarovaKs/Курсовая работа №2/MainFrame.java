package demography;
import javax.swing.*;

public class MainFrame extends JFrame {
    public MainFrame(String s){
        super(s);
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationByPlatform(true);
        setVisible(true);
    }
}
