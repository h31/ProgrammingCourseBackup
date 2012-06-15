package sunsystem;

import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

public class PlanetFrame extends JFrame{
    
    PlanetFrame(Planet planet){
        super(planet.name);
        setSize(500, 500);
        addWindowListener(new FrameCloser(this));
        PlanetPanel ppanel = new PlanetPanel(planet);
        Container contentPane = getContentPane();
        ppanel.setBounds(0, 0, contentPane.getWidth(), contentPane.getHeight());
        add(ppanel);
        setVisible(true);
    }
}

class FrameCloser extends WindowAdapter{
    JFrame frame;
    FrameCloser(JFrame frame){
        this.frame = frame;
    }
    @Override
    public void windowClosing(WindowEvent ev){
        frame.dispose();
    }
}