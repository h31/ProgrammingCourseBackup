
package ball;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.Timer;
import javax.swing.JPanel;


class MainPanel extends JPanel {
    private Space space;
    private Ball ball;
    private Timer timer;
    private Score score;
    private BallViewFull viewFull;
    private Racket racket;
    private RacketViewFull RviewFull;
    private ScoreViewFull SViewFull;
    ActionListener timerListener;



    public MainPanel() {
        super();
        setBackground(Color.BLACK);

        //space = new Space( this.getWidth(), this.getHeight());
        space = new Space( this );
        int s = new Random(System.currentTimeMillis()).nextInt(400 - 0) + 0;
        ball = new Ball( new Vector(5,s), new Vector(100,100), 10, Color.RED);
        racket = new Racket  (new Vector(600,180), new Vector(10,10), 4,50, Color.GREEN);
        score = new Score (new Vector(350,0),new Vector(1,1));
        viewFull = new BallViewFull( ball );
        RviewFull = new RacketViewFull (racket);
        SViewFull = new ScoreViewFull (score);
        ball.registerView(viewFull);
        racket.registerView(RviewFull);
        score.registerView(SViewFull);
        timerListener = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                ball.check(racket, score);         
                    ball.updateViews();
                ball.step( space );
                
              if (ball.pos.x>racket.pos.x)
              {
                     new Dialog(timer , score).setVisible(true);
                     int s1 =new Random(System.currentTimeMillis()).nextInt(400 - 0) + 0;
                 ball.pos=new Vector(5,s1);
                 ball.dx=2; ball.dy=2;
                 score.amount=0;
                 timer.stop();
                 
                
              }
                if ((score.amount==20)||(score.amount==40)||(score.amount==60)){ball.dx++; ball.dy++;}
                
                repaint();
            }
        };
           
        timer = new Timer(5, timerListener);
        timer.start();
      
    }
    
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        viewFull.paint(g);
        RviewFull.paint(g);
        SViewFull.paint(g);
    }
    public  void moveRacket(int dt)
    {racket.step(space,dt);
    }
}
