/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package guipackage;

import java.util.ArrayList;
import java.sql.SQLException;
import javax.swing.table.AbstractTableModel;
import datapackage.MaterialDatabaseHelper;
import datapackage.DependenciesDatabaseHelper;
import datapackage.Material;
import datapackage.DataManager;
import supportpackage.FilenameUtils;

//TODO округление цены, шага, порога?

/**
 * Модель таблицы, содержащей материалы из БД
 */
public class MaterialDatabaseTableModel extends AbstractTableModel {
    
    //граничные значения
    public final static int NameLengthMax = 100;
    public final static int UnitLengthMax = 30;
    public final static double PriceMin = 0;
    public final static double PriceMax = 1000000000;    
    public final static double StepMin = 0;
    public final static double StepMax = 1000000;   
    public final static double BorderMin = 0;
    public final static double BorderMax = 1000000;   
    
    //значения полей по умолчанию
    private final static String DefaultName = "Новый материал";
    private final static String DefaultUnit = "шт.";
    private final static double DefaultPrice = 100.00;
    private final static double DefaultStep = 0;
    private final static double DefaultBorder = 0;
    
    private final static String CopyPrefix = "Копия ";

    //ссылка на родительское окно
    private MaterialDatabaseDialog PartnerFrame;
    
    //Хелперы для баз данных.
    private MaterialDatabaseHelper MDHelper;
    private DependenciesDatabaseHelper DDHelper;
    
    //список id материалов, представленных в таблице
    private ArrayList<Long> IdList = null;
    
    //названия столбцов
    private String[] ColumnNames = {"Номер","Материал","Единица измерения","Цена","Шаг округления","Порог округления"};
    
    /**
     * Конструктор
     * Заполняет таблицу значениями из БД
     * @param Dialog ссылка на родительское окно
     * @throws SQLException при ошибке с работой БД
     */
    public MaterialDatabaseTableModel(MaterialDatabaseDialog Dialog, DataManager dataManager) throws SQLException {
        PartnerFrame = Dialog;
        //создаем хелперы для работы с БД
        MDHelper = dataManager.getMaterialsHelper();
        DDHelper = dataManager.getDependenciesHelper();
        //получаем список ID от хелпера
        IdList = MDHelper.getIdList();
    }
    
    public void AddMaterial() {
        try{
            long NewlyCreatedId = MDHelper.createMaterial(DefaultName, DefaultUnit, DefaultPrice, DefaultStep, DefaultBorder);
            IdList.add(NewlyCreatedId);
            int NewlyCreatedIndex = IdList.lastIndexOf(NewlyCreatedId);
            
            fireTableRowsInserted(NewlyCreatedIndex, NewlyCreatedIndex);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
        }
    }
    
    public void CopyMaterial(int SelectedRow) {
        long SelectedId = IdList.get(SelectedRow);
        try{
            Material SelectedMaterial = MDHelper.getMaterial(SelectedId);
            long NewlyCreatedId = MDHelper.createMaterial(CopyPrefix + SelectedMaterial.getName(), SelectedMaterial.getUnit(), SelectedMaterial.getPrice(), SelectedMaterial.getRoundingStep(), SelectedMaterial.getRoundingBorder());
            IdList.add(SelectedRow + 1, NewlyCreatedId);
            int NewlyCreatedIndex = IdList.lastIndexOf(NewlyCreatedId);
            
            fireTableRowsInserted(NewlyCreatedIndex, NewlyCreatedIndex);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
        }
    }
    
    public void DeleteMaterial(int SelectedRow) {
        long SelectedId = IdList.get(SelectedRow);
        
        try{
            //проверка на использование в алгоритмах
            if (DDHelper.isMaterialBeingUsed(SelectedId))
            {
                MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialCannotBeDeleted);
                return;
            }
            //удаляем
            MDHelper.deleteMaterial(SelectedId);
            IdList.remove(SelectedRow);
            fireTableRowsDeleted(SelectedRow, SelectedRow);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
        }
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
    
    /**
     * Метод возвращает имя материала, содержащееся в ячейке
     * @param row строка
     * @return имя материала
     */
    private String getNameAt(int row) {
        String name = "";
        try{
            //получаем имя у хелпера
            name = MDHelper.getName(IdList.get(row));
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
            unit = MDHelper.getUnit(IdList.get(row));
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
            price = Double.toString( MDHelper.getPrice(IdList.get(row)) );
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
            step = Double.toString( MDHelper.getRoundingStep(IdList.get(row)) );
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
            border = Double.toString( MDHelper.getRoundingBorder(IdList.get(row)) );
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
        if (col == 0) return false;
        else return true;
    }

    /**
     * Метод заносит значение в ячейку
     * @param value значение
     * @param row строка
     * @param col столбец
     */
    public void setValueAt(Object value, int row, int col) {
        System.err.println("row " + row + " col " + col);
        
        switch (col) {
            case 0:
                break;
            case 1:
                SetNameAt(row, (String)value);
                break;
            case 2:
                SetUnitAt(row, (String)value);
                break;
            case 3:
                SetPriceAt(row, (String)value);
                break;      
            case 4:
                SetRoundingStepAt(row, (String)value);
                break;
            case 5:
                SetRoundingBorderAt(row, (String)value);
                break;                     
            default:
                break;
        }
        
        //перерисовываем ячейку
        fireTableCellUpdated(row, col);
    }
    
    /**
     * Метод заносит имя материала в ячейку
     * @param row строка
     * @param InputName имя
     */
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
        try{
            //заносим имя в базу
            MDHelper.setName(IdList.get(row), name);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
    }
    
    /**
     * Метод заносит единицу измерения в ячейку
     * @param row строка
     * @param InputName единица измерения
     */    
    private void SetUnitAt(int row, String InputUnit) {
        String unit;

        try{
            //проверяем валидность единицы измерения
            unit = ValidateUnit(InputUnit);
        } catch (IllegalArgumentException e)
        {
            //единица измерения невалидна
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        try{
            //заносим единицу измерения в базу
            MDHelper.setUnit(IdList.get(row), unit);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
    }

    /**
     * Метод заносит цену материала в ячейку
     * @param row строка
     * @param InputName цена
     */    
    private void SetPriceAt(int row, String InputPrice) {
        double price;
        
        try{
            //проверяем валидность цены
            price = ValidatePrice(InputPrice);
        } catch (IllegalArgumentException e)
        {
            //цена невалидна
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }        
        try{
            //заносим цену в базу
            MDHelper.setPrice(IdList.get(row), price);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
    }    
    
    /**
     * Метод заносит шаг округления в ячейку
     * @param row строка
     * @param InputName шаг округления
     */    
    private void SetRoundingStepAt(int row, String InputStep) {
        double step;
        
        try{
            //проверяем валидность шага
            step = ValidateRoundingStep(InputStep);
        } catch (IllegalArgumentException e)
        {
            //шаг невалиден
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }        
        try{
            //заносим шаг в базу
            MDHelper.setRoundingStep(IdList.get(row), step);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
    }       
    
    /**
     * Метод заносит порог округления в ячейку
     * @param row строка
     * @param InputBorder порог округления
     */    
    private void SetRoundingBorderAt(int row, String InputBorder) {
        double border;
        
        try{
            //проверяем валидность порога
            border = ValidateRoundingBorder(InputBorder);
        } catch (IllegalArgumentException e)
        {
            //порог невалиден
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }        
        try{
            //заносим порог в базу
            MDHelper.setRoundingBorder(IdList.get(row), border);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_MaterialsDatabaseError);
            PartnerFrame.CloseFrame();
        }
    }            
    
    /**
     * Метод форматирует и проверяет имя материала на валидность
     * @param InputName имя
     * @return форматированное имя
     * @throws IllegalArgumentException если имя невалидно; message = код ошибки для MessageHandler'а
     */
    private String ValidateName (String InputName) throws IllegalArgumentException {
        //чистим от пробелов на концах
        String name = InputName.trim();
        
        //если пусто
        if (name.equals("")) {
            throw new IllegalArgumentException(MessageHandler.ERROR_MaterialNameIsEmpty);
        }
        
        //Если имя слишком длинное.
        if (name.length() > NameLengthMax) {
            throw new IllegalArgumentException(MessageHandler.ERROR_MaterialNameIsTooLong);
        }
        
        //Если есть небезопасные символы
        if(name.matches(FilenameUtils.NonSafeSymbolsPattern)) {
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.MESSAGE_SymbolsWillBeReplaced);
            name = FilenameUtils.replaceNonSafeSymbols(name);
        }
        
        return name;
    }
    
    /**
     * Метод форматирует и проверяет единицу измерения на валидность
     * @param InputUnit единица измерения
     * @return форматированная единица измерения
     * @throws IllegalArgumentException если единица измерения невалидна; message = код ошибки для MessageHandler'а
     */    
    private String ValidateUnit (String InputUnit) throws IllegalArgumentException {
        //чистим от пробелов на концах
        String unit = InputUnit.trim();
        
        //если пусто
        if (unit.equals("")) {
            throw new IllegalArgumentException(MessageHandler.ERROR_UnitIsEmpty);
        }
        
        //Если единица измерения слишком длинное.
        if (unit.length() > UnitLengthMax) {
            throw new IllegalArgumentException(MessageHandler.ERROR_UnitIsTooLong);
        }
        
        //Если есть небезопасные символы
        if(unit.matches(FilenameUtils.NonSafeSymbolsPattern)) {
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.MESSAGE_SymbolsWillBeReplaced);
            unit = FilenameUtils.replaceNonSafeSymbols(unit);
        }
        
        return unit;
    }
    
    /**
     * Метод форматирует и проверяет цену материала на валидность
     * @param InputPrice цена в виде строки
     * @return форматированная цена
     * @throws IllegalArgumentException если цена невалидна; message = код ошибки для MessageHandler'а
     */    
    private double ValidatePrice (String InputPrice) throws IllegalArgumentException {
        double price;
        
        try {
            //парсим значение.
            price = Double.parseDouble(InputPrice.trim().replaceAll(",", "."));
        } catch (NumberFormatException e)
        {
            //В поле не число.
            throw new IllegalArgumentException(MessageHandler.ERROR_PriceIsNotNumber);
        }
        
        //Если число вне допустимого диапазона.
        if (price < PriceMin || price > PriceMax)
        {
            throw new IllegalArgumentException(MessageHandler.ERROR_PriceIsOutOfRange);
        }
        
        return price;
    }
    
    /**
     * Метод форматирует и проверяет шаг округления на валидность
     * @param InputStep шаг в виде строки
     * @return форматированный шаг
     * @throws IllegalArgumentException если шаг невалиден; message = код ошибки для MessageHandler'а
     */    
    private double ValidateRoundingStep (String InputStep) throws IllegalArgumentException {
        double step;
        
        try {
            //парсим значение.
            step = Double.parseDouble(InputStep.trim().replaceAll(",", "."));
        } catch (NumberFormatException e)
        {
            //В поле не число.
            throw new IllegalArgumentException(MessageHandler.ERROR_StepIsNotNumber);
        }
        
        //Если число вне допустимого диапазона.
        if (step < StepMin || step > StepMax)
        {
            throw new IllegalArgumentException(MessageHandler.ERROR_StepIsOutOfRange);
        }
        
        return step;
    }    
    
    /**
     * Метод форматирует и проверяет порог округления на валидность
     * @param InputBorder порог в виде строки
     * @return форматированный порог
     * @throws IllegalArgumentException если порог невалиден; message = код ошибки для MessageHandler'а
     */    
    private double ValidateRoundingBorder (String InputBorder) throws IllegalArgumentException {
        double border;
        
        try {
            //парсим значение.
            border = Double.parseDouble(InputBorder.trim().replaceAll(",", "."));
        } catch (NumberFormatException e)
        {
            //В поле не число.
            throw new IllegalArgumentException(MessageHandler.ERROR_BorderIsNotNumber);
        }
        
        //Если число вне допустимого диапазона.
        if (border < BorderMin || border > BorderMax)
        {
            throw new IllegalArgumentException(MessageHandler.ERROR_BorderIsOutOfRange);
        }
        
        return border;
    }        
    
    /**
     * Метод закрывает БД
     */
    public void CloseDatabase() {
        //Если БД открыта.
        if(MDHelper != null)
        {
            //Закрываем БД.
            MDHelper.close();
        }
        //Если БД открыта.
        if(DDHelper != null)
        {
            //Закрываем БД.
            DDHelper.close();
        }        
    }
}
