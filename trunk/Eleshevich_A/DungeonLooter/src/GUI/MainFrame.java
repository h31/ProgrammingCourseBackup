package GUI;

import Creatures.Player;
import Dungeon.Dungeon;
import Dungeon.DungeonGenerator;
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
        String pname = "Player";
        //String pname = JOptionPane.showInputDialog(rootPane, "Введите имя игрока");
        dungeon = DungeonGenerator.generateDungeon(pname);
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
    }
}

class MyKeyListener extends KeyAdapter{
    Dungeon dungeon;
    MyKeyListener(Dungeon dungeon){
        this.dungeon = dungeon;
    }
    @Override
    public void keyPressed(KeyEvent e){
        switch(e.getKeyCode()){
            case KeyEvent.VK_UP: dungeon.movePlayer(Dungeon.UP); break;
            case KeyEvent.VK_LEFT: dungeon.movePlayer(Dungeon.LEFT); break;
            case KeyEvent.VK_RIGHT: dungeon.movePlayer(Dungeon.RIGHT); break;
            case KeyEvent.VK_DOWN: dungeon.movePlayer(Dungeon.DOWN); break;
            case KeyEvent.VK_SPACE: dungeon.passTurn(); break;
        }
    }
}
