/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package guipackage;

import datapackage.Algorithm;
import datapackage.DataManager;
import datapackage.AlgorithmDatabaseHelper;
import java.sql.SQLException;
import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;
import supportpackage.FilenameUtils;
import supportpackage.Room;
import supportpackage.Surface;

public class RoomEditingTableModel extends AbstractTableModel {
    //граничные значения
    public final static int NameLengthMax = 100;
    
    public final static double MeasureMin = 1;
    public final static double MeasureMax = 1000000;
    public final static double MeasureDefault = 10; 

    //ссылка на родительское окно
    private RoomEditingDialog PartnerFrame;
    //список поверхностей
    private ArrayList<Surface> Surfaces;    
    //Хелпер для базы данных.
    private AlgorithmDatabaseHelper ADHelper;
    //список алгоритмов
    private ArrayList<Algorithm> Algs;
    //названия столбцов
    private String[] ColumnNames = {"Номер","Название","Тип","Метраж","Способ измерения","Алгоритм"};
    
    /**
     * Конструктор
     * Заполняет таблицу значениями из БД
     * @param Dialog ссылка на родительское окно
     * @throws SQLException при ошибке с работой БД
     */
    public RoomEditingTableModel(RoomEditingDialog Dialog, DataManager dataManager, Room room) throws SQLException {
        PartnerFrame = Dialog;
        Surfaces = room.getSurfaces();
        //создаем хелперы для работы с БД
        ADHelper = dataManager.getAlgorithmsHelper();
        //получаем список алгоритмов от хелпера
        Algs = ADHelper.getAlgorithmsList();
        //TODO если алг нет
    }
    
    public ArrayList<Algorithm> getAlgorithmsList() {
        return Algs;
    }
    
    public void AddSurface() {
        Surfaces.add(new Surface(Algs.get(0).getId()));
        fireTableRowsInserted(Surfaces.size()-1, Surfaces.size()-1);
    }
    
    public void DeleteSurface(int SelectedRow) {
        Surfaces.remove(SelectedRow);
        fireTableRowsDeleted(SelectedRow, SelectedRow);
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
        return Surfaces.size();
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
                return getTypeAt(row);
            case 3:
                return getMeasureAt(row);
            case 4:
                return getMeasuringMethodAt(row);
            case 5:
                return getAlgorithmAt(row);                
            default:
                return null;
        }
    }    
    
    private String getNameAt(int row) {
        return Surfaces.get(row).getName();
    }
    
    private String getTypeAt(int row) {
        return Surface.TYPES[Surfaces.get(row).getType()];
    }
    
    private String getMeasureAt(int row) {
        return Double.toString(Surfaces.get(row).getMeasure());
    }    
    
    private String getMeasuringMethodAt(int row) {
        return Surface.METHODS[Surfaces.get(row).getMeasuringMethod()];
    }
    
    private String getAlgorithmAt(int row) {
        long id = Surfaces.get(row).getAlgorithmId();
        for(int i=0; i<Algs.size(); i++)
        {
            if( Algs.get(i).getId() == id )
            {
                return Algs.get(i).getName();
            }
        }
        return "";
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
        if (col == 0) return false;
        else return true;
    }    
    
    public void setValueAt(Object value, int row, int col) {
        System.err.println("row " + row + " col " + col);
        
        switch (col) {
            case 0:
                break;
            case 1:
                SetNameAt(row, (String)value);
                break;
            case 2:
                SetTypeAt(row, (String)value);
                break;
            case 3:
                SetMeasureAt(row, (String)value);
                break;      
            case 4:
                SetMeasuringMethodAt(row, (String)value);
                break;
            case 5:
                SetAlgorithmAt(row, (String)value);
                break;                     
            default:
                break;
        }
        //перерисовываем ячейку
        fireTableCellUpdated(row, col);
    }    
    
    private void SetNameAt(int row, String InputName) {
        String name;
        
        try{
            //проверяем валидность имени
            name = ValidateName(InputName);
        } catch (IllegalArgumentException e)
        {
            //имя невалидно
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        //заносим имя в список
        Surfaces.get(row).setName(name);
    }    
    
    private void SetTypeAt(int row, String type) {
        for(int i=0; i<Surface.TYPES.length; i++)
        {
            if(Surface.TYPES[i].equals(type))
            {
                Surfaces.get(row).setType(i);
            }
        }
    }
    
    private void SetMeasureAt(int row, String InputMeasure) {
        double measure;
        
        try{
            //проверяем валидность метража
            measure = ValidateMeasure(InputMeasure);
        } catch (IllegalArgumentException e)
        {
            //метраж невалиден
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }        
        Surfaces.get(row).setMeasure(measure);
    }        
    
    private void SetMeasuringMethodAt(int row, String method) {
        for(int i=0; i<Surface.METHODS.length; i++)
        {
            if(Surface.METHODS[i].equals(method))
            {
                Surfaces.get(row).setMeasuringMethod(i);
            }
        }
    }    
    
    private void SetAlgorithmAt(int row, String AlgName) {
        for(int i=0; i<Algs.size(); i++)
        {
            if(Algs.get(i).getName().equals(AlgName))
            {
                Surfaces.get(row).setAlgorithmId(Algs.get(i).getId());
            }
        }
    }    
    
    private String ValidateName (String InputName) throws IllegalArgumentException {
        //чистим от пробелов на концах
        String name = InputName.trim();
        
        //если пусто
        if (name.equals("")) {
            throw new IllegalArgumentException(MessageHandler.ERROR_SurfaceNameIsEmpty);
        }
        
        //Если имя слишком длинное.
        if (name.length() > NameLengthMax) {
            throw new IllegalArgumentException(MessageHandler.ERROR_SurfaceNameIsTooLong);
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
    
    private double ValidateMeasure (String InputMeasure) throws IllegalArgumentException {
        double measure;
        
        try {
            //парсим значение.
            measure = Double.parseDouble(InputMeasure.trim().replaceAll(",", "."));
        } catch (NumberFormatException e)
        {
            //В поле не число.
            throw new IllegalArgumentException(MessageHandler.ERROR_MeasureIsNotNumber);
        }
        
        //Если число вне допустимого диапазона.
        if (measure < MeasureMin || measure > MeasureMax)
        {
            throw new IllegalArgumentException(MessageHandler.ERROR_MeasureIsOutOfRange);
        }
        
        return measure;
    }    
    
   /**
     * Метод закрывает БД
     */
    public void CloseDatabase() {
        //Если БД открыта.
        if(ADHelper != null)
        {
            //Закрываем БД.
            ADHelper.close();
        }
    }    
}
