package GUI;

import Creatures.Player;
import Dungeon.Direction;
import Dungeon.Dungeon;
import Dungeon.DungeonGenerator;
import Dungeon.LoadingException;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class MainFrame extends JFrame{
    Dungeon dungeon;
    DungeonPanel Dpanel;
    PlayerPanel Ppanel;
    MessagePanel Mpanel;
    public MainFrame(String s){
        super(s);
        try{
            String pname = "Player";
            //String pname = JOptionPane.showInputDialog(rootPane, "Введите имя игрока");
            dungeon = DungeonGenerator.loadDungeon(pname);
            setSize(915, 765);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            Dpanel = new DungeonPanel(dungeon);
            Ppanel = new PlayerPanel(dungeon);
            Mpanel = new MessagePanel();
            dungeon.addScreens(Dpanel, Ppanel, Mpanel);
            add(Dpanel);
            add(Ppanel);
            add(Mpanel);
            add(new BackgroundPanel(Dpanel, Ppanel, Mpanel));
            addKeyListener(new MyKeyListener(dungeon));
            setVisible(true);
        }catch(LoadingException lex){
            JOptionPane.showMessageDialog(rootPane, lex.getMessage(), "Ошибка при загрузке", JOptionPane.ERROR_MESSAGE);
            System.exit(-5);
        }
    }
}

class MyKeyListener extends KeyAdapter{
    Dungeon dungeon;
    boolean closing = false;
    
    MyKeyListener(Dungeon dungeon){
        this.dungeon = dungeon;
    }
    @Override
    public void keyPressed(KeyEvent e){
        switch(e.getKeyCode()){
            case KeyEvent.VK_W:
            case KeyEvent.VK_UP:
                if(closing){
                    closing = false;
                    dungeon.playerCloseDoor(Direction.UP);
                }
                else
                    dungeon.movePlayer(Direction.UP);
                break;
            case KeyEvent.VK_A:
            case KeyEvent.VK_LEFT:
                if(closing){
                    closing = false;
                    dungeon.playerCloseDoor(Direction.LEFT);
                }
                else
                    dungeon.movePlayer(Direction.LEFT);
                break;
            case KeyEvent.VK_D:
            case KeyEvent.VK_RIGHT:
                if(closing){
                    closing = false;
                    dungeon.playerCloseDoor(Direction.RIGHT);
                }
                else
                    dungeon.movePlayer(Direction.RIGHT);
                break;
            case KeyEvent.VK_S:
            case KeyEvent.VK_DOWN:
                if(closing){
                    closing = false;
                    dungeon.playerCloseDoor(Direction.DOWN);
                }
                else
                    dungeon.movePlayer(Direction.DOWN);
                break;
            case KeyEvent.VK_SPACE: dungeon.passTurn(); break;
            case KeyEvent.VK_F: dungeon.playerUseStair(); break;
            case KeyEvent.VK_C: closing = true; break;
        }
    }
}
