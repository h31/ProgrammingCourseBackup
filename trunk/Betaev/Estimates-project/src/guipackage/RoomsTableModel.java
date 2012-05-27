package guipackage;

import datapackage.*;
import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;
import supportpackage.Room;
import supportpackage.Estimate;
import java.sql.SQLException;

public class RoomsTableModel extends AbstractTableModel {

    //граничные значения
    public final static int NameLengthMax = 100;    
    
    private static String TITLE_RoomEditingDialog = "Редактирование помещения: "; 
    
    //ссылка на родительское окно
    private MainFrame PartnerFrame;     
    //БД хелперы
    private DataManager dataManager;
    //список помещений, представленных в таблице
    private ArrayList<Room> Rooms;
    //названия столбцов
    private String[] ColumnNames = {"Помещение"};    
    
    public RoomsTableModel(MainFrame Frame, DataManager data, Estimate Est) {
        PartnerFrame = Frame;
        //создаем БД хелперы
        dataManager = data;
        //получаем список помещений
        Rooms = Est.getRooms();
    }    
    
    public void AddRoom() {
        int Temp1 = Rooms.size() + 1;
        Rooms.add(new Room("Помещение" + Temp1));
        fireTableRowsInserted(Rooms.size()-1, Rooms.size()-1);
    }
    
    public void EditRoom(int SelectedRow) {
        Room SelectedRoom = Rooms.get(SelectedRow);
        
        //Новое окно.
        RoomEditingDialog dialog;
        
        try
        {
            //Создаем новое окно
            dialog = new RoomEditingDialog(PartnerFrame, true, dataManager, SelectedRoom);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        
        //Задаем положение, модальность, заголовок. Показываем.
        dialog.setLocationRelativeTo(PartnerFrame);
        dialog.setModal(true);
        dialog.setTitle(TITLE_RoomEditingDialog + SelectedRoom.getName());
        dialog.setVisible(true);    
    }
    
    public void DeleteRoom(int SelectedRow) {
        //удаляем из списка помещений
        Rooms.remove(SelectedRow);
        //перерисовываем таблицу
        fireTableRowsDeleted(SelectedRow, SelectedRow);
    }
    
    public void ClearTable() {
        int size = Rooms.size();
        Rooms.clear();
        fireTableRowsDeleted(0, size-1);
    }
    
    /**
     * Метод возвращает количество столбцов таблицы
     * @return количество столбцов
     */
    public int getColumnCount() {
        return ColumnNames.length;
    }

    /**
     * Метод возвращает количество строк таблицы
     * @return  количество строк
     */
    public int getRowCount() {
        return Rooms.size();
    }

    /**
     * Метод возвращает имя столбца
     * @param col номер колонки 0-...
     * @return имя
     */
    public String getColumnName(int col) {
        return ColumnNames[col];
    }

    /**
     * Метод возвращает содержимое ячейки
     * @param row строка
     * @param col столбец
     * @return значение
     */
    public Object getValueAt(int row, int col) {
        System.err.println("get row " + row + " col " + col);
        return (String) Rooms.get(row).getName();
    }    
    
    /**
     * Метод возвращает класс объектов, содержащихся в столбце
     * @param c номер столбца 0-...
     * @return класс
     */
    public Class getColumnClass(int c) {
        return "string".getClass();
    }

    /**
     * Метод проверяет, является ли ячейка редактируемой
     * @param row строка
     * @param col столбец
     * @return true если ячейка редактируемая; false иначе
     */
    public boolean isCellEditable(int row, int col) {
        return true;
    }    
    
    /**
     * Метод заносит значение в ячейку
     * @param value значение
     * @param row строка
     * @param col столбец
     */
    public void setValueAt(Object value, int row, int col) {
        System.err.println("row " + row + " col " + col);
        String name;
        
        try{
            //проверяем валидность имени
            name = ValidateName((String)value);
        } catch (IllegalArgumentException e)
        {
            //имя невалидно
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }

        //меняем имя в списке помещений
        Rooms.get(row).setName(name);
        //перерисовываем ячейку
        fireTableCellUpdated(row, col);
    }    
    
    /**
     * Метод форматирует и проверяет имя помещения на валидность
     * @param InputName имя
     * @return форматированное имя
     * @throws IllegalArgumentException если имя невалидно; message = код ошибки для MessageHandler'а
     */
    private String ValidateName (String InputName) throws IllegalArgumentException {
        //чистим от пробелов на концах
        String name = InputName.trim();
        
        //если пусто
        if (name.equals("")) {
            throw new IllegalArgumentException(MessageHandler.ERROR_RoomNameIsEmpty);
        }
        
        //Если имя слишком длинное.
        if (name.length() > NameLengthMax) {
            throw new IllegalArgumentException(MessageHandler.ERROR_RoomNameIsTooLong);
        }
        /*
        //Если есть небезопасные символы
        if(name.matches(FilenameUtils.NonSafeSymbolsPattern)) {
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.MESSAGE_SymbolsWillBeReplaced);
            name = FilenameUtils.replaceNonSafeSymbols(name);
        }
        */
        return name;
    }    
}