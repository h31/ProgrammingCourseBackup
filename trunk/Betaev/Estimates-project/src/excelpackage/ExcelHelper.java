package excelpackage;

import guipackage.MessageHandler;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import jxl.Workbook;
import jxl.write.WritableWorkbook;
import jxl.write.WritableSheet;
import jxl.write.Label;
import jxl.write.Formula;
import jxl.write.Number;
import jxl.write.NumberFormat;
import jxl.write.NumberFormats;
import jxl.write.WriteException;
import jxl.write.WritableFont;
import jxl.write.WritableCellFormat;
import jxl.format.Alignment;
import jxl.format.Border;
import jxl.format.BorderLineStyle;

import supportpackage.*;

/**
 * Класс создает итоговый файл xls.
 * @see supportpackage.Material
 */
public class ExcelHelper {
    
    //TODO подгон ширины столбцов
    
    //путь к файлу
    private String AbsolutePath;
    //массив помещений
    private ArrayList<Room> Rooms;
    //текущий массив поверхностей
    private ArrayList<Surface> Surfaces;
    //текущий массив материалов
    private ArrayList<CalculatedMaterial> Materials;
    
    //
    private int EmptyLines;
    //индекс строки, с которой начнется печать текущей таблицы
    private int TableHeadRow;
    
    private WritableWorkbook OutputWorkbook;
    private WritableSheet CurrentSheet;
    private int SheetsAmount;

    private final static int DefaultFontSize = 10;
    
    private WritableCellFormat HeadCellFormat;
    private WritableCellFormat IdCellFormat;
    private WritableCellFormat MaterialCellFormat;
    private WritableCellFormat UnitCellFormat;
    private WritableCellFormat AmountCellFormat;
    private WritableCellFormat PriceCellFormat;
    private WritableCellFormat CostCellFormat;
    private WritableCellFormat TotalCellFormat;
    private WritableCellFormat SimpleTextCellFormat;
    
    private final static int IdColumn = 0;
    private final static int MaterialColumn = 1;
    private final static int UnitColumn = 2;
    private final static int AmountColumn = 3;
    private final static int PriceColumn = 4;
    private final static int CostColumn = 5;
    
    private final static String TEXT_MAINSHEETNAME = "Лист1";
    private final static String TEXT_ID = "№";
    private final static String TEXT_MATERIAL = "Материал";
    private final static String TEXT_UNIT = "Ед. изм.";
    private final static String TEXT_AMOUNT = "Количество";
    private final static String TEXT_PRICE = "Цена";
    private final static String TEXT_COST = "Стоимость";
    private final static String TEXT_TOTAL = "Итого";
    
    private final static String TEXT_CEILING = "Потолок";
    private final static String TEXT_WALLS = "Стены";
    private final static String TEXT_FLOOR = "Пол";    
    
    private final static String ROUBLES_PATTERN = "###,###,##0.00р.";
    
    /**
     * Конструктор.
     * Получает описание задачи,
     * откуда извлекает количество пустых строк в начале сметы,
     * а также массив материалов для печати.
     */
    public ExcelHelper(Estimate Est, EstimateProperties Properties) {
        Rooms = Est.getRooms();
        this.AbsolutePath = Properties.getAbsolutePath();
        this.EmptyLines = Properties.getEmptyLines();
    }
    
    /**
     * Метод выполняет основную работу:
     * создает итоговый файл xls.
     * @throws IOException в случае ошибки ввода-вывода.
     * @throws WriteException в случае ошибки при заполнении ячеек.
     */
    public void DrawEstimates() throws IOException, WriteException {
        try{
            //Создаем книгу.
            CreateOutputWorkbook();
            //Подготавливаем форматы ячеек.
            CreateCellFormats();
            
            for(int i=0; i<Rooms.size(); i++)
            {
                DrawRoom(i);
            }
            
            //TODO итоговая страница
            
            //Сохраняем, закрываем.
            SaveAndCloseWorkbook();
        } catch (IOException e)
        {
            throw new IOException(MessageHandler.ERROR_ExcelOutputError);
        } catch (WriteException e)
        {
            throw new IOException(MessageHandler.ERROR_ExcelOutputError);
        }
    }
    
    /**
     * Метод создает книгу excel и единственный лист в ней.
     * @throws IOException в случае ошибки ввода-вывода.
     */
    private void CreateOutputWorkbook() throws IOException {
        //Создаем книгу.
        OutputWorkbook = Workbook.createWorkbook(new File(FilenameUtils.removeExtension(AbsolutePath) + ".xls"));
        SheetsAmount = 0;
    }
    
    /**
     * Метод создает необходимые форматы ячеек.
     * @throws WriteException в случае ошибки при создании форматов.
     */
    private void CreateCellFormats() throws WriteException {
        //Шрифт.
        WritableFont DefaultFont = new WritableFont(WritableFont.ARIAL, DefaultFontSize); 
        
        SimpleTextCellFormat = new WritableCellFormat (DefaultFont);
        SimpleTextCellFormat.setAlignment(Alignment.LEFT);        
        
        //Ячейки заголовка таблицы.
        HeadCellFormat = new WritableCellFormat (DefaultFont);
        HeadCellFormat.setAlignment(Alignment.LEFT);
        HeadCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);
        
        //Ячейки столбца "номер".
        IdCellFormat = new WritableCellFormat (NumberFormats.INTEGER);
        IdCellFormat.setAlignment(Alignment.CENTRE);
        IdCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);
        
        //Ячейки столбца "имя".
        MaterialCellFormat = new WritableCellFormat (DefaultFont);
        MaterialCellFormat.setAlignment(Alignment.LEFT);
        MaterialCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);
        
        //Ячейки столбца "единица измерения".
        UnitCellFormat = new WritableCellFormat (DefaultFont);
        UnitCellFormat.setAlignment(Alignment.CENTRE);
        UnitCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);
        
        //Ячейки столбца "количество".
        AmountCellFormat = new WritableCellFormat (DefaultFont);
        AmountCellFormat.setAlignment(Alignment.RIGHT);
        AmountCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);
        
        //Числовой формат "рубли".
        NumberFormat RoublesNumberFormat = new NumberFormat(ROUBLES_PATTERN, NumberFormat.COMPLEX_FORMAT); 
        
        //Ячейки столбца "цена".
        PriceCellFormat = new WritableCellFormat(RoublesNumberFormat);
        PriceCellFormat.setAlignment(Alignment.RIGHT);
        PriceCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN);   
        
        //Ячейки столбца "стоимость".
        CostCellFormat = new WritableCellFormat(RoublesNumberFormat);
        CostCellFormat.setAlignment(Alignment.RIGHT);
        CostCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN); 
        
        //Ячейка, содержащая итоговую сумму.
        TotalCellFormat = new WritableCellFormat(RoublesNumberFormat);
        TotalCellFormat.setAlignment(Alignment.RIGHT);
        TotalCellFormat.setBorder(Border.ALL, BorderLineStyle.THIN); 
    }
    
    private void DrawRoom (int index) throws WriteException {
        Room CurrentRoom = Rooms.get(index);
        String name = CurrentRoom.getName();
        
        //Создаем лист.
        CurrentSheet = OutputWorkbook.createSheet(name, SheetsAmount); 
        SheetsAmount++;
        
        TableHeadRow = EmptyLines + 1;
        ArrayList<Integer> TailRows = new ArrayList<Integer>();
        
        Materials = CurrentRoom.getCeilingOutput();
        if(! Materials.isEmpty())
        {
            CurrentSheet.addCell(new Label(IdColumn, TableHeadRow-1, TEXT_CEILING, SimpleTextCellFormat));
            DrawTable();
            TailRows.add(TableHeadRow + Materials.size() + 1); 
            TableHeadRow += Materials.size() + 3;
        }
     
        Materials = CurrentRoom.getWallOutput();
        if(! Materials.isEmpty())
        {
            CurrentSheet.addCell(new Label(IdColumn, TableHeadRow-1, TEXT_WALLS, SimpleTextCellFormat));
            DrawTable();
            TailRows.add(TableHeadRow + Materials.size() + 1); 
            TableHeadRow += Materials.size() + 3;
        }
        
        Materials = CurrentRoom.getFloorOutput();
        if(! Materials.isEmpty())
        {
            CurrentSheet.addCell(new Label(IdColumn, TableHeadRow-1, TEXT_FLOOR, SimpleTextCellFormat));
            DrawTable();
            TailRows.add(TableHeadRow + Materials.size() + 1); 
            TableHeadRow += Materials.size() + 3;
        }
        
        CurrentSheet.addCell(new Label(PriceColumn, TableHeadRow, TEXT_TOTAL, SimpleTextCellFormat));
        
        //если нет ни одной таблицы
        if (TailRows.isEmpty())
        {
            //Ячейка с суммарной стоимостью заполняется нулем
            CurrentSheet.addCell(new Number(CostColumn, TableHeadRow, 0, CostCellFormat)); 
        }
        else if (TailRows.size() == 1)
        {
            String Temp1 = Integer.toString(TailRows.get(0) + 1);
            String formula = "F"+ Temp1;
            //Ячейка с суммарной стоимостью заполняется формулой.
            CurrentSheet.addCell(new Formula(CostColumn, TableHeadRow, formula, CostCellFormat)); 
        }
        else if (TailRows.size() == 2)
        {
            String Temp1 = Integer.toString(TailRows.get(0) + 1);
            String Temp2 = Integer.toString(TailRows.get(1) + 1);
            String formula = "F"+ Temp1 +"+F"+ Temp2;
            //Ячейка с суммарной стоимостью заполняется формулой.
            CurrentSheet.addCell(new Formula(CostColumn, TableHeadRow, formula, CostCellFormat));
        }
        else if (TailRows.size() == 3)
        {
            String Temp1 = Integer.toString(TailRows.get(0) + 1);
            String Temp2 = Integer.toString(TailRows.get(1) + 1);
            String Temp3 = Integer.toString(TailRows.get(2) + 1);
            String formula = "F"+ Temp1 +"+F"+ Temp2 +"+F"+ Temp3;
            //Ячейка с суммарной стоимостью заполняется формулой.
            CurrentSheet.addCell(new Formula(CostColumn, TableHeadRow, formula, CostCellFormat)); 
        }        
    }
    
    private void DrawTable() throws WriteException {
        //Рисуем шапку таблицы.
        DrawTableHead();
        //Рисуем тело таблицы.
        DrawTableBody();
        //Рисуем низ таблицы и итог.
        DrawTableTail();    
    }    
    
    /**
     * Метод добавляет в лист ряд ячеек,
     * составляющих заголовок таблицы.
     * @throws WriteException в случае ошибки при заполнении ячеек.
     */
    private void DrawTableHead() throws WriteException {
        CurrentSheet.addCell(new Label(IdColumn, TableHeadRow, TEXT_ID, HeadCellFormat)); 
        CurrentSheet.addCell(new Label(MaterialColumn, TableHeadRow, TEXT_MATERIAL, HeadCellFormat));
        CurrentSheet.addCell(new Label(UnitColumn, TableHeadRow, TEXT_UNIT, HeadCellFormat));
        CurrentSheet.addCell(new Label(AmountColumn, TableHeadRow, TEXT_AMOUNT, HeadCellFormat));
        CurrentSheet.addCell(new Label(PriceColumn, TableHeadRow, TEXT_PRICE, HeadCellFormat));
        CurrentSheet.addCell(new Label(CostColumn, TableHeadRow, TEXT_COST, HeadCellFormat));
    }
    
    /**
     * Метод добавляет в лист основную часть таблицы.
     * @throws WriteException в случае ошибки при заполнении ячеек.
     */
    private void DrawTableBody() throws WriteException {
        //Построчный цикл
        for(int CurrentMaterial = 0; CurrentMaterial < Materials.size(); CurrentMaterial++) {
            //В каждую строку таблицы заносятся данные об одном материале.
            //Данные берутся из массива материалов, полученного конструктором.
            CurrentSheet.addCell(new Number(IdColumn, TableHeadRow + 1 + CurrentMaterial, CurrentMaterial + 1, IdCellFormat)); 
            CurrentSheet.addCell(new Label(MaterialColumn, TableHeadRow + 1 + CurrentMaterial, Materials.get(CurrentMaterial).getName(), MaterialCellFormat)); 
            CurrentSheet.addCell(new Label(UnitColumn, TableHeadRow + 1 + CurrentMaterial, Materials.get(CurrentMaterial).getUnit(), UnitCellFormat)); 
            CurrentSheet.addCell(new Number(AmountColumn, TableHeadRow + 1 + CurrentMaterial, Materials.get(CurrentMaterial).getAmount(), AmountCellFormat)); 
            CurrentSheet.addCell(new Number(PriceColumn, TableHeadRow + 1 + CurrentMaterial, Materials.get(CurrentMaterial).getPrice(), PriceCellFormat));
            
            //Ячейка "стоимость" заполняется формулой.
            String Temp = Integer.toString(TableHeadRow + 2 + CurrentMaterial);
            CurrentSheet.addCell(new Formula(CostColumn, TableHeadRow + 1 + CurrentMaterial, "D"+Temp+"*E"+Temp, CostCellFormat)); 
        }
    }
    
    /**
     * Метод закрывает таблицу.
     * @throws WriteException в случае ошибки при заполнении ячеек.
     */
    private void DrawTableTail() throws WriteException {
        int TableTailRow = TableHeadRow + 1 + Materials.size();
        //Ячейка с надписью "ИТОГО".
        CurrentSheet.addCell(new Label(PriceColumn, TableTailRow, TEXT_TOTAL, SimpleTextCellFormat));
        
        //если таблица пуста
        if (Materials.isEmpty())
        {
            //Ячейка с суммарной стоимостью заполняется нулем
            CurrentSheet.addCell(new Number(CostColumn, TableTailRow, 0, TotalCellFormat)); 
        }
        //не пуста
        else
        {
            String Temp1 = Integer.toString(TableHeadRow + 2);
            String Temp2 = Integer.toString(TableTailRow);
            //Ячейка с суммарной стоимостью заполняется формулой.
            CurrentSheet.addCell(new Formula(CostColumn, TableTailRow, "SUM(F"+Temp1+":F"+Temp2+")", TotalCellFormat)); 
        }
    }
    
    /**
     * Метод сохраняет и закрывает книгу.
     * @throws IOException в случае ошибки ввода-вывода.
     * @throws WriteException в случае ошибки при заполнении ячеек.
     */
    private void SaveAndCloseWorkbook() throws IOException, WriteException {
        OutputWorkbook.write(); 
        OutputWorkbook.close();
    }
}
