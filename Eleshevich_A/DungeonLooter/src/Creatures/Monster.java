package Creatures;

import Dungeon.Cell;
import Dungeon.Dungeon;
import Dungeon.Percenter;
import Dungeon.Position;
import java.awt.Toolkit;

/**
 * @author Andrew
 */
public class Monster extends Creature{
    int damage;
    AI ai;
    public Monster(String name, int maxhealth, int damage, int defence, int strength, int dexterity, int sightradius){
        super(name, maxhealth, defence, strength, dexterity, sightradius);
        this.damage = damage;
        img = Toolkit.getDefaultToolkit().createImage("Data/monster1.gif");
    }
    @Override
    public Damage getDamage(){
        return new Damage(damage, strength, dexterity);
    }
    public void AIturn(Dungeon dungeon){
        boolean inSight = false;
        for(Position p: dungeon.calcVision(pos, sightradius))
            if(dungeon.getPlayer().getPos().equals(p))
                inSight = true;
        if(inSight){
            
        }else{  //надо переписать чтоб через константы и чтоб проверка на препятствия была здесть чтоб монстр других монстров не атаковал
            int[] values = (new Percenter(1, 1, 1, 1)).getMultiChance(4);
            for(int val: values){
                Position npos = new Position(pos);
                switch(val){
                    case 1: npos.y--; break;
                    case 2: npos.x--; break;
                    case 3: npos.x++; break;
                    case 4: npos.y++; break;
                }
                boolean flag;
                try{
                    dungeon.findMonster(npos);
                    flag = true;
                }catch(Exception ex){   //посмотреть что тут ловить
                    flag = false;
                }
                if((dungeon.getCell(npos) != null) && !flag && (dungeon.getCell(npos).getType() == Cell.FLOOR)){
                    dungeon.moveCreature(this, val);    //соотнести цифры с константами(может быть) и может нужно больше контроля
                    break;
                }
            }
        }
    }
}
