package guipackage;

import datapackage.MaterialDatabaseHelper;
import java.sql.SQLException;
import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;

public class DependentMaterialsTableModel extends AbstractTableModel {
    //ссылка на родительское окно
    private DependenceDialog PartnerFrame;
    //Хелпер для базы данных.
    private MaterialDatabaseHelper DbHelper;
    //список id материалов, представленных в таблице
    private ArrayList<Long> IdList;
    //названия столбцов
    private String[] ColumnNames = {"Номер","Материал","Единица измерения","Цена","Шаг округления","Порог округления"};
    
    /**
     * Конструктор
     * Заполняет таблицу значениями из БД
     * @param Dialog ссылка на родительское окно
     * @throws ClassNotFoundException при ошибке с подгрузкой драйвера JDBC
     * @throws SQLException при ошибке с работой БД
     */
    public DependentMaterialsTableModel(DependenceDialog Dialog, MaterialDatabaseHelper helper) throws SQLException {
        PartnerFrame = Dialog;
        //хелпер для работы с БД
        DbHelper = helper;
        //получаем список ID от хелпера
        IdList = DbHelper.getIdList();
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
        return IdList.size();
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
        switch (col) {
            case 0:
                return row + 1;
            case 1:
                return getNameAt(row);
            case 2:
                return getUnitAt(row);
            case 3:
                return getPriceAt(row);
            case 4:
                return getRoundingStepAt(row);
            case 5:
                return getRoundingBorderAt(row);                
            default:
                return null;
        }
    }
    
    public long getIdAt(int row) {
        return IdList.get(row).longValue();
    }    
    
     /**
     * Метод возвращает имя материала, содержащееся в ячейке
     * @param row строка
     * @return имя материала
     */
    private String getNameAt(int row) {
        String name = "";
        try{
            //получаем имя у хелпера
            name = DbHelper.getName(IdList.get(row));
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
        return name;
    }
    
    /**
     * Метод возвращает единицу измерения, содержащуюся в ячейке
     * @param row строка
     * @return имя единица измерения
     */
    private String getUnitAt(int row) {
        String unit = "";
        try{
            //получаем единицу измерения у хелпера
            unit = DbHelper.getUnit(IdList.get(row));
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
        return unit;
    }   

    /**
     * Метод возвращает цену материала, содержащуюся в ячейке
     * @param row строка
     * @return цена материала
     */    
    private String getPriceAt(int row) {
        String price = "";
        try{
            //получаем цену у хелпера
            price = Double.toString( DbHelper.getPrice(IdList.get(row)) );
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
        return price;
    }   
    
    /**
     * Метод возвращает шаг округления, содержащийся в ячейке
     * @param row строка
     * @return шаг округления
     */    
    private String getRoundingStepAt(int row) {
        String step = "";
        try{
            //получаем шаг у хелпера
            step = Double.toString( DbHelper.getRoundingStep(IdList.get(row)) );
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
        return step;
    }       
 
    /**
     * Метод возвращает порог округления, содержащийся в ячейке
     * @param row строка
     * @return порог округления
     */    
    private String getRoundingBorderAt(int row) {
        String border = "";
        try{
            //получаем порог у хелпера
            border = Double.toString( DbHelper.getRoundingBorder(IdList.get(row)) );
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
        return border;
    }     
    
    /**
     * Метод возвращает класс объектов, содержащихся в столбце
     * @param c номер столбца 0-...
     * @return класс
     */
    public Class getColumnClass(int c) {
        switch(c) {
            case 0:
                return new Integer(0).getClass();
            default:
                return "string".getClass();
        }
   }

    /**
     * Метод проверяет, является ли ячейка редактируемой
     * @param row строка
     * @param col столбец
     * @return true если ячейка редактируемая; false иначе
     */
    public boolean isCellEditable(int row, int col) {
        return false;
    }
    
 
    /**
     * Метод закрывает БД
     */
    public void CloseDatabase() {
        //Если БД открыта.
        if(DbHelper != null)
        {
            //Закрываем БД.
            DbHelper.close();
        }
    }    
}
