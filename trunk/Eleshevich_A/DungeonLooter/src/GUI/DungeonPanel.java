package GUI;

import Constants.CellStatus;
import Creatures.Monster;
import Dungeon.Cell;
import Dungeon.Dungeon;
import Dungeon.Position;
import Items.ItemStack;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * @author Andrew
 */
public class DungeonPanel extends JPanel implements Updatable{
    Dungeon dungeon;
    int tilesNum = 8;
    
    DungeonPanel(Dungeon dungeon){
        this.dungeon = dungeon;
    }
    
    @Override
    public void paint(Graphics g){
        g.setColor(Color.black);
        g.fillRect(0, 0, getWidth(), getHeight());
        int tileSize = getWidth()/(tilesNum*2+1);
        Position pos = dungeon.getPlayer().getPos();
        Position startPos = new Position(pos.x - tilesNum, pos.y - tilesNum);
        int dy = 0;
        for(int y = startPos.y; y <= startPos.y+tilesNum*2+1; y++, dy++){
            int dx = 0;
            for(int x = startPos.x; x <= startPos.x+tilesNum*2+1; x++, dx++){
                Cell cell = dungeon.getCell(x, y);
                if(cell == null)
                    continue;
                if(cell.getStatus() == CellStatus.UNDISCOVERED)
                    continue;
                g.drawImage(cell.getImg(), dx*tileSize, dy*tileSize, tileSize, tileSize, this);
            }
        }
        int ty, tx;
        for(ItemStack istack: dungeon.getItemStacks()){
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
}
