package GUI;

import Constants.CellType;
import Constants.CellStatus;
import Creatures.Monster;
import Dungeon.*;
import GUI.Updatable;
import Items.ItemStack;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.awt.image.RescaleOp;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class DungeonPanel extends JPanel implements Updatable{
    Dungeon dungeon;
    int tilesNum = 8;   //отсчитывается от позиции игрока
    Image floorImg = getToolkit().createImage("Data/floor.gif");
    Image wallImg = getToolkit().createImage("Data/wall.gif");
    Image dfloorImg = darken(floorImg);
    Image dwallImg = darken(wallImg);
//    Image dfloorImg = getToolkit().createImage("Data/floordark.gif");
//    Image dwallImg = getToolkit().createImage("Data/walldark.gif");
    DungeonPanel(Dungeon dungeon){
        this.dungeon = dungeon;
    }
    
    @Override
    public void paint(Graphics g){
        g.setColor(Color.black);
        g.fillRect(0, 0, getWidth(), getHeight());
        int tileSize = getWidth()/(tilesNum*2+1);   //Проверка чтоб был квадратный экран, брать наименьшее, хотя это контролируется в bacgroundPanel
        Position pos = dungeon.getPlayer().getPos();
        Position startPos = new Position(pos.x - tilesNum, pos.y - tilesNum);
        int dy = 0;
        for(int y = startPos.y; y <= startPos.y+tilesNum*2+1; y++, dy++){
            int dx = 0;
            for(int x = startPos.x; x <= startPos.x+tilesNum*2+1; x++, dx++){
                Cell cell = dungeon.getCell(x, y);
                if(cell == null)    //проверить будет ли работать в одном if
                    continue;
                if(cell.getStatus() == CellStatus.UNDISCOVERED)
                    continue;
                g.drawImage(cell.getImg(), dx*tileSize, dy*tileSize, tileSize, tileSize, this);
            }
        }
        int ty, tx;
        for(ItemStack istack: dungeon.getItemStacks()){
            System.out.println("istack pos: " + istack.getPos().x + "/" + istack.getPos().y);
            if(dungeon.getCell(istack.getPos()).getStatus() == CellStatus.VISIBLE){
                ty = (istack.getPos().y - startPos.y)*tileSize;
                tx = (istack.getPos().x - startPos.x)*tileSize;
                g.drawImage(istack.getImg(), tx, ty, tileSize, tileSize, this);
            }
        }
        ty = (pos.y - startPos.y)*tileSize;
        tx = (pos.x - startPos.x)*tileSize;
        g.drawImage(dungeon.getPlayer().getImg(), tx, ty, tileSize, tileSize, this);
        for(Monster monster: dungeon.getMonsters()){
            if(dungeon.getCell(monster.getPos()).getStatus() == CellStatus.VISIBLE){
                ty = (monster.getPos().y - startPos.y)*tileSize;
                tx = (monster.getPos().x - startPos.x)*tileSize;
                g.drawImage(monster.getImg(), tx, ty, tileSize, tileSize, this);
            }
        }
    }
    @Override
    public void update(){
        repaint();
    }
    Image darken(Image src){
        try{
            MediaTracker mt = new MediaTracker(this);
            mt.addImage(src, 0);
            mt.waitForID(0);
        }catch(Exception ex){}
        BufferedImage bi = new BufferedImage(src.getWidth(this), src.getHeight(this), BufferedImage.TYPE_INT_RGB);
        Graphics2D big = bi.createGraphics();
        big.drawImage(src, 0, 0, this);
        BufferedImage dbi = new BufferedImage(src.getWidth(this), src.getHeight(this), BufferedImage.TYPE_INT_RGB);
        RescaleOp rop = new RescaleOp(0.3f, 40.0f, null);
        rop.filter(bi, dbi);
        return getToolkit().createImage(dbi.getSource());
    }
}
