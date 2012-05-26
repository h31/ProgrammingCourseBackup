package GUI;

import Constants.PlayerSlot;
import Constants.SlotType;
import Items.*;
import java.awt.Component;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

/**
 * @author Andrew
 */
public class SimpleDialog {
    static int dialogItem(Item item, SlotType stype, Component comp){
        String option = "";
        StringBuilder message = new StringBuilder(item.getName());
        String title = "";
        switch(item.getType()){
            case ARMOR:{
                title = "Броня";
                Armor arm = (Armor)item;
                message.append("\nЗащита: ").append(arm.getDefence());
                String aclass = "";
                switch(arm.getArmClass()){
                    case HEAVY: aclass = "Тяжёлый"; break;
                    case LIGHT: aclass = "Лёгкий"; break;
                }
                message.append("\nКласс брони: ").append(aclass);
                switch(arm.getArmType()){
                    case SHIELD: message.append("\nТип: щит"); break;
                    case BODY_ARMOR:{
                        String type = "";
                        switch(((BodyArmor)arm).getSlotType()){
                            case HEAD: type = "Шлем"; break;
                            case BODY: type = "Нагрудник"; break;
                            case LEGS: type = "Поножи"; break;
                        }
                        message.append("\nТип: ").append(type);
                    }
                }
                break;
            }
            case WEAPON:{
                title = "Оружие";
                Weapon wep = (Weapon)item;
                String wtype = "";
                switch(wep.getWtype()){
                    case SWORD: wtype = "Меч"; break;
                    case MACE: wtype = "Булава"; break;
                    case STAFF: wtype = "Посох"; break;
                }
                message.append("\nТип: ").append(wtype).append("\nАтака: ").append(wep.getDamage());
                break;
            }
            case POTION:{
                title = "Зелье";
                break;
            }
            case MISC:{
                title = "Разное";
            }    
        }
        message.append("\n").append(item.getDescr());
        switch(item.getUseType()){
            case USABLE: option = "Использовать"; break;
            case PUTABLE:
                if(stype == SlotType.EQUIPPED)
                    option = "Снять";
                else option = "Надеть";
                break;
            case WIELDABLE:
                if(stype == SlotType.EQUIPPED)
                    option = "Убрать из руки";
                else
                    option = "Взять в руку";
                break;  
            case NONE: option = "Тут тоже Ок";
        }
        String[] vars = {"Ок", option};
        ImageIcon ic = new ImageIcon(item.getImg());
        return JOptionPane.showOptionDialog(comp, message, title, JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, ic, vars, "Ок");
    }
    static int levelUpDialog(int level, Component comp){
        String title = "Повышение уровня";
        String message = "Поздравляю, вы достигли " + level + "уровня\nвыберите характеристику, которую хотите увеличить";
        String[] vars = {"Запас жизни", "Сила", "Ловкость"};
        return JOptionPane.showOptionDialog(comp, message, title, JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, vars, "Запас жизни");
    }
    static PlayerSlot handDialog(Component comp){
        String[] options = {"В правую", "В левую"};
        switch(JOptionPane.showOptionDialog(comp, "В какую руку взять предмет",
                "Выбор руки", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE,
                null, options, "В правую")){
            case 0: return PlayerSlot.RIGHT_HAND;
            case 1: return PlayerSlot.LEFT_HAND;
            default: return PlayerSlot.RIGHT_HAND;  //ну точно нужно исключение
        }
    }
}
