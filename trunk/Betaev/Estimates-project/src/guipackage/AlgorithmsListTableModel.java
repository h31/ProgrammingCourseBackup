/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package guipackage;

import datapackage.*;
import java.sql.SQLException;
import java.util.ArrayList;
import javax.swing.table.AbstractTableModel;
import supportpackage.FilenameUtils;

public class AlgorithmsListTableModel extends AbstractTableModel {

    //граничные значения
    public final static int NameLengthMax = 100;    
    
    private static String TITLE_AlgorithmEditingDialog = "Редактирование алгоритма: "; 
    
    //ссылка на родительское окно
    private AlgorithmsListDialog PartnerFrame;     
    //значения полей по умолчанию
    private final static String DefaultName = "Новый алгоритм";       
    //БД хелперы
    private AlgorithmDatabaseHelper ADHelper;
    private DependenciesDatabaseHelper DDHelper;
    private MaterialDatabaseHelper MDHelper;
    //список алгоритмов, представленных в таблице
    private ArrayList<Algorithm> Algs;
    //названия столбцов
    private String[] ColumnNames = {"Алгоритм"};    
    
    public AlgorithmsListTableModel(AlgorithmsListDialog Dialog, DataManager data) throws SQLException {
        PartnerFrame = Dialog;
        //создаем БД хелперы
        ADHelper = data.getAlgorithmsHelper();
        DDHelper = data.getDependenciesHelper();
        MDHelper = data.getMaterialsHelper();
        //получаем список алгоримов
        Algs = ADHelper.getAlgorithmsList();
    }    
    
    public void AddAlgorithm() {
        Algorithm created;
        
        try {
            created = ADHelper.createAlgorithm(DefaultName);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        
        Algs.add(created);
        //перерисовываем таблицу
        fireTableRowsInserted(Algs.size()-1, Algs.size()-1);
    }
    
    public void EditAlgorithm(int SelectedRow) {
        Algorithm SelectedAlg = Algs.get(SelectedRow);
        
        //Новое окно.
        AlgorithmEditingDialog dialog;
        
        try
        {
            //Создаем новое окно
            dialog = new AlgorithmEditingDialog(PartnerFrame, true, SelectedAlg, MDHelper, DDHelper);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        
        //Задаем положение, модальность, заголовок. Показываем.
        dialog.setLocationRelativeTo(PartnerFrame);
        dialog.setModal(true);
        dialog.setTitle(TITLE_AlgorithmEditingDialog + SelectedAlg.getName());
        dialog.setVisible(true);    
    }
    
    public void DeleteAlgorithm(int SelectedRow) {
        Algorithm SelectedAlg = Algs.get(SelectedRow);
        
        try {
            //удаляем зависимости из БД
            DDHelper.deleteDependencies(SelectedAlg.getId());
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        
        try {
            //удаляем алгоритм из БД
            ADHelper.deleteAlgorithm(SelectedAlg);
        } catch (SQLException e)
        {
            MessageHandler.ShowDialog(PartnerFrame, e.getMessage());
            return;
        }
        
        //удаляем из списка алгоритмов
        Algs.remove(SelectedRow);
        //перерисовываем таблицу
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
        return Algs.size();
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
        return (String) Algs.get(row).getName();
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

        //меняем имя в списке алгоритмов
        Algorithm CurrentAlg = Algs.get(row);
        CurrentAlg.setName(name);
        
        try{
            //заносим имя в базу
            ADHelper.setAlgorithm(CurrentAlg);
        } catch (SQLException e)
        {
            //если ошибка при работе с SQL
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.ERROR_AlgorithmDatabaseError);
            PartnerFrame.CloseFrame();
        }
        
        //перерисовываем ячейку
        fireTableCellUpdated(row, col);
    }    
    
    /**
     * Метод форматирует и проверяет имя алгоритма на валидность
     * @param InputName имя
     * @return форматированное имя
     * @throws IllegalArgumentException если имя невалидно; message = код ошибки для MessageHandler'а
     */
    private String ValidateName (String InputName) throws IllegalArgumentException {
        //чистим от пробелов на концах
        String name = InputName.trim();
        
        //если пусто
        if (name.equals("")) {
            throw new IllegalArgumentException(MessageHandler.ERROR_AlgorithmNameIsEmpty);
        }
        
        //Если имя слишком длинное.
        if (name.length() > NameLengthMax) {
            throw new IllegalArgumentException(MessageHandler.ERROR_AlgorithmNameIsTooLong);
        }
        
        //Если есть небезопасные символы
        if(name.matches(FilenameUtils.NonSafeSymbolsPattern)) {
            MessageHandler.ShowDialog(PartnerFrame, MessageHandler.MESSAGE_SymbolsWillBeReplaced);
            name = FilenameUtils.replaceNonSafeSymbols(name);
        }
        
        return name;
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
        //Если БД открыта.
        if(DDHelper != null)
        {
            //Закрываем БД.
            DDHelper.close();
        }
    }    
}
