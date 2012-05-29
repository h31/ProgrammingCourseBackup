package sunsystem;


import java.awt.Graphics;
import java.awt.event.*;
import java.util.ArrayDeque;
import java.util.Deque;
import javax.swing.JComboBox;
import javax.swing.JPanel;
import javax.swing.Timer;


class MainPanel extends JPanel implements Screen{
    ArrayDeque<Planet> planets;
    private Timer timer;
    double Sfact;
    double Tfact;
    int Tstep;
    double BaseSize;
    JComboBox choice;

    public MainPanel(ArrayDeque<Planet> tplanets){
        super();
        Sfact = 1;
        Tfact = 1;
        Tstep = 15;
        BaseSize = 800;
        planets = tplanets;
        for(Planet planet: planets)
            planet.getTrajectory().setScreen(this);
        timer = new Timer(Tstep, new TimerListener(planets, this));
        addMouseListener(new MListener(planets, this));
        choice = new JComboBox(new Speed[] {new Speed(1.0), new Speed(2.0), new Speed(0.5), new Speed(1000.0), new Speed(0.01)});
        choice.setBounds(100, 200, 100, 20);
        choice.addItemListener(new SelectMonitor(this));
        add(choice);
        timer.start();
    }

    @Override
    public void paint(Graphics g){
        super.paint(g);
        int width = getWidth();
        int height = getHeight();
        int size = width < height ? width : height;
        Sfact = (double)size/BaseSize;
        for(Planet planet: planets)
            planet.paint(g, this, Sfact);
    }
    @Override
    public void setSfact(double nSfact){
        Sfact = nSfact;
    }
    @Override
    public void setTfact(double nTfact){
        Tfact = nTfact;
        for(Planet planet: planets){
            planet.getTrajectory().calcStep();
        }
    }
    @Override
    public void setTstep(int nTstep){
        Tstep = nTstep;
    }
    @Override
    public double getSfact(){
        return Sfact;
    }
    @Override
    public double getTfact(){
        return Tfact;
    }
    @Override
    public int getTstep(){
        return Tstep;
    }
}

class TimerListener implements ActionListener{
    Deque<Planet> planets;
    MainPanel panel;
    TimerListener(Deque<Planet> tplanets, MainPanel tpanel){
        planets = tplanets;
        panel = tpanel;
    }
    @Override
    public void actionPerformed(ActionEvent e){
        for(Planet planet: planets)
            planet.CalcStep();
        panel.repaint();
    }
}

class MListener extends MouseAdapter{
    Deque<Planet> planets;
    Screen scr;
    MListener(Deque<Planet> planets, Screen screen){
        this.planets = planets;
        scr = screen;
    }
    @Override
    public void mouseClicked(MouseEvent e){
        for(Planet planet: planets){
            if(planet.liesIn(e.getPoint(), scr.getSfact())){
                new PlanetFrame(planet);
                break;
            }
        }
    }
}

class SelectMonitor implements ItemListener{
    Screen scr;
    SelectMonitor(Screen screen){
        scr = screen;
    }
    @Override
    public void itemStateChanged(ItemEvent e){
        if(e.getStateChange() == ItemEvent.SELECTED){
            scr.setTfact(((Speed)e.getItem()).getVal());
        }
    } 
}

class Speed{
    double val;
    Speed(double val){
        this.val = val;
    }
    double getVal(){
        return val;
    }
    @Override
    public String toString(){
        return val + "x";
    }
}