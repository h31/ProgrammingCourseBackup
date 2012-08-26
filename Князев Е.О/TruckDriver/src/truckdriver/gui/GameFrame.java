package truckdriver.gui;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.WindowConstants;
import truckdriver.City;
import truckdriver.resources.Resources;
import truckdriver.Start;
import truckdriver.Truck;

public class GameFrame extends JFrame {
    
    private JPanel canvas = null;
    private boolean mouseDown = false;
    private Point pos;
    private City city;
    private int steps = 0;
    private final int stepsToRegenerate = 6;
    
    public GameFrame() {
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setTitle("TruckDriver");
        canvas = new MyCanvas();
        canvas.setPreferredSize(new Dimension(720, 480));
        canvas.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                if (mouseDown) {
                    Point p2 = e.getPoint();
                    Point cP = city.getPosition();
                    cP.x += p2.x - pos.x;
                    cP.y += p2.y - pos.y;
                    city.setPosition(cP);
                    pos = p2;
                }
                else for (City item : Resources.cities) {
                    item.mouseMove(e.getX(), e.getY());
                }
                redraw();
            }  
        });
        canvas.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getButton() == MouseEvent.BUTTON1 && !mouseDown) {
                    for (City item : Resources.cities) {
                        if (item.isActive()) {
                            if (item == Start.inter.getTruckCity()) {
                                new CityMarketFrame().start(item);
                            }
                            else {
                                steps++;
                                if (steps >= stepsToRegenerate) {
                                    steps = 0;
                                    Start.inter.generateBuyGods();
                                }
                                Start.inter.setTruckCity(item);
                                redraw();
                            }
                        }
                    }
                }
                if (e.getButton() == MouseEvent.BUTTON3) {
                    for (City item : Resources.cities) {
                        if (item.isOver(e.getX(), e.getY())) {
                            city = item;
                            mouseDown = !mouseDown;
                            pos = e.getPoint();
                        }
                    }
                }
            }  
        });
        add(canvas);
        setResizable(false);
        pack();
    }
    
    public void start() {
        Dimension size = Toolkit.getDefaultToolkit().getScreenSize();
        int x = size.width / 2 - this.getSize().width / 2;
        int y = size.height / 2 - this.getSize().height / 2;
        setLocation(x, y);
        setVisible(true);
    }
    
    public void redraw() {
        canvas.repaint();
    }
    
    private class MyCanvas extends JPanel {
        
        public MyCanvas() {
            super();
            setDoubleBuffered(true); 
        }
        
        @Override
        public void paint(Graphics g) {
            super.paint(g);
            boolean active = false;
            g.clearRect(0, 0, 740, 500);
            g.setColor(Color.GRAY);
            for (int i = 0; i < Resources.cities.size(); i++) {
                for (int j = i; j < Resources.cities.size(); j++) {
                    if (Start.inter.getGraph()[i][j] == 1) {
                        Point p1 = Resources.cities.get(i).getPosition();
                        Point p2 = Resources.cities.get(j).getPosition();
                        int offsetX = City.WIDTH / 2;
                        int offsetY = City.HEIGHT / 2;
                        g.drawLine(p1.x + offsetX, p1.y + offsetY, 
                                p2.x + offsetX, p2.y + offsetY);
                    }
                }
            }
            for (City item : Resources.cities) {
                Point p = item.getPosition();
                if (!item.isActive()) {
                    g.setColor(Color.BLACK);
                }
                else {
                    active = true;
                    g.setColor(Color.BLUE);
                }
                g.fillArc(p.x, p.y, City.WIDTH, City.HEIGHT, 0, 360);
                g.setColor(Color.ORANGE);
                g.fillArc(p.x + 2, p.y + 2, 
                        City.WIDTH - 4, City.HEIGHT - 4, 0, 360);
                String title = item.getTitle();
                g.setFont(new Font("Tahoma", Font.BOLD, 14));
                g.setColor(Color.BLACK);
                g.drawString(title, p.x, p.y - 10);
                Point truckPos = Start.inter.getTruckCity().getPosition();
                int offsetX = (City.WIDTH - Truck.WIDTH) / 2;
                int offsetY = (City.HEIGHT - Truck.HEIGHT) / 2;
                g.drawImage(Resources.truck, 
                        truckPos.x + offsetX, truckPos.y + offsetY, null);
            }
            if (active) {
                setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
            }
            else {
                setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
            }
        }
        
    }
    
}