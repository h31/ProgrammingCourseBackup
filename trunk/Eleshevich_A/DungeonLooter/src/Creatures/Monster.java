package Creatures;

import Constants.Direction;
import Constants.InvalidConstantException;
import Dungeon.Dungeon;
import Dungeon.Percenter;
import Dungeon.Position;
import Items.Item;
import Items.ItemBase;
import java.awt.Image;

/**
 * @author Andrew
 */
public class Monster extends Creature{
    int damage;
    String descr;
    int xpreward;
    int ID;
    
    public Monster(String name, Image img, int maxhealth, int damage, int defence, int strength,
            int dexterity, int sightradius, int hregen, int xpreward, String descr, int ID){
        super(name, img, maxhealth, defence, strength, dexterity, hregen, sightradius);
        this.damage = damage;
        this.xpreward = xpreward;
        this.ID = ID;
    }
    
    @Override
    public Damage getDamage(){
        return new Damage(damage, strength, dexterity);
    }
    public int getID(){
        return ID;
    }
    public void AIturn(Dungeon dungeon){
        boolean inSight = false;
        Position ppos = dungeon.getPlayer().getPos();
        for(Position p: dungeon.calcVision(pos, sightradius))
            if(ppos.equals(p))
                inSight = true;
        if(inSight){
            int dx = pos.x - ppos.x;
            int dy = pos.y - ppos.y;
            Direction dirx, diry;
            if(dx < 0)
                dirx = Direction.RIGHT;
            else
                dirx = Direction.LEFT;
            if(dy < 0)
                diry = Direction.DOWN;
            else
                diry = Direction.UP;
            dx = Math.abs(dx);
            dy = Math.abs(dy);
            int[] order;
            if(dx == dy)
                order = new Percenter(1,1).getMultiChance(2);
            else if(dx > dy)
                order = new int[] {0, 1};
            else
                order = new int[] {1, 0};
            for(int d: order){
                    if(d == 0){
                        if(dungeon.moveCreature(this, dirx))
                            break;
                    }
                    else
                        if(dungeon.moveCreature(this, diry))
                            break;
            }
        }else{
            int[] values = (new Percenter(1, 1, 1, 1)).getMultiChance(4);
            for(int val: values){
                try{
                    Position npos = pos.getNewPos(Direction.getDir(val));
                    boolean flag;
                    try{
                        dungeon.findMonster(npos);
                        flag = true;
                    }catch(Exception ex){
                        flag = false;
                    }
                    if((dungeon.getCell(npos) != null) && !flag && !(dungeon.getCell(npos).isSolid())){
                        dungeon.moveCreature(this, Direction.getDir(val));
                        break;
                    }
                }catch(InvalidConstantException icex){
                    System.err.println(icex.getMessage());
                }
            }
        }
    }
    public int getXPreward(){
        return xpreward;
    }
    public Item[] getDrop(){
        Item[] res = null;
        if(new Percenter(1,1).getChance() == 1){
            res = new Item[1];
            res[0] = ItemBase.getItemRandom();
        }
        return res;
    }
    @Override
    public Monster clone(){
        return new Monster(name, img, maxhealth, damage, defence, strength, dexterity, sightradius, hregen, xpreward, descr, ID);
    }
}
