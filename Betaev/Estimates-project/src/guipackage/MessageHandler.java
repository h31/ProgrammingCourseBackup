package guipackage;

import javax.swing.JOptionPane;
import java.awt.Component;

/**
 * Статический класс.
 * Выводит поверх всех окон сообщения об ошибках и уведомления.
 */
public class MessageHandler {
    //TODO добавить ошибки: отсутствует материал такой-то, зависимость, алгоритм. случаи бросания.
    //TODO если материал отсутствует при открытии алгоритма, либо при создании сметы - чистка. надпись: "удален"?
    //TODO упаковать в один jar, исправить тексты ошибок
    //Коды ошибок и уведомлений
    public final static String ERROR_UnknownError = "0";
    public final static String ERROR_AbsolutePathIsEmpty = "1";
    public final static String ERROR_EmptyLinesIsNotNumber = "2";
    public final static String ERROR_EmptyLinesIsOutOfRange = "3";
    public final static String ERROR_MeasureIsNotNumber = "4";
    public final static String ERROR_MeasureIsOutOfRange = "5";
    public final static String ERROR_JdbcError = "6";
    public final static String ERROR_MaterialsDatabaseError = "7";
    public final static String ERROR_ExcelOutputError = "8";
    public final static String ERROR_WrongTypeOfFile = "9";
    public final static String ERROR_MaterialNameIsEmpty = "10";
    public final static String ERROR_IllegalMaterialName = "11";
    public final static String ERROR_MaterialNameIsTooLong = "12";
    public final static String ERROR_UnitIsEmpty = "13";
    public final static String ERROR_IllegalUnit = "14";
    public final static String ERROR_UnitIsTooLong = "15";
    public final static String ERROR_PriceIsNotNumber = "16";
    public final static String ERROR_PriceIsOutOfRange = "17";
    public final static String ERROR_NameAlreadyExists = "18";
    public final static String ERROR_DependenciesDatabaseError = "19";
    public final static String ERROR_StepIsNotNumber = "20";
    public final static String ERROR_StepIsOutOfRange = "21";
    public final static String ERROR_BorderIsNotNumber = "22";
    public final static String ERROR_BorderIsOutOfRange = "23";
    public final static String ERROR_AlgorithmDatabaseError = "24";
    public final static String ERROR_MaterialNotFoundInDatabase = "25";
    public final static String ERROR_AlgorithmNameIsEmpty = "26";
    public final static String ERROR_AlgorithmNameIsTooLong = "27";
    public final static String ERROR_ChooseDependentMaterial = "28";
    public final static String ERROR_FieldsAreNotNumbers = "29";
    public final static String ERROR_FieldsAreOutOfRange = "30";
    public final static String ERROR_ChooseIndependentMaterial = "31";
    public final static String ERROR_MaterialCannotBeDeleted = "32";
    public final static String ERROR_RoomNameIsEmpty = "33";
    public final static String ERROR_RoomNameIsTooLong = "34";    
    public final static String ERROR_SurfaceNameIsEmpty = "35";
    public final static String ERROR_SurfaceNameIsTooLong = "36";    
    
    public final static String MESSAGE_Success = "-1";
    public final static String MESSAGE_FileAlreadyExists = "-2";
    public final static String MESSAGE_SymbolsWillBeReplaced = "-3";
    
    //Тексты ошибок и уведомлений.
    private static String[] ErrorTexts = {
        "Неизвестная ошибка.",  
        "Выберите файл.",       
        "Введите желаемое число пустых строк в начале файла.",
        "Число пустых строк должно лежать в диапазоне 0-"+ MainFrame.EmptyLinesMax +".",
        "Введите метраж поверхности.",
        "Метраж должен лежать в диапазоне "+ String.format("%1$.0f",RoomEditingTableModel.MeasureMin) +"-"+ String.format("%1$.0f",RoomEditingTableModel.MeasureMax) +".",
        "Ошибка при загрузке драйвера JDBC. Убедитесь, что файл sqlitejdbc[...].jar присутствует в папке lib.",
        "Ошибка при работе с базой материалов. Убедитесь, что SQLite-база db_materials в папке data не повреждена.",
        "Ошибка при создании файла сметы. Убедитесь, что диск не переполнен и не защищен от записи.",
        "Выбранный файл не является книгой Excel 2003 (.xls).",
        "Введите название материала.",
        "Недопустимые символы в названии материала.",
        "Длина имени материала не должна превышать "+ MaterialDatabaseTableModel.NameLengthMax +".",
        "Введите единицу измерения.",
        "Недопустимые символы в единице измерения.",
        "Длина единицы измерения не должна превышать "+ MaterialDatabaseTableModel.UnitLengthMax +".",
        "Введите цену материала.",
        "Цена материала должна лежать в диапазоне "+ String.format("%1$.0f",MaterialDatabaseTableModel.PriceMin) +"-"+ String.format("%1$.0f",MaterialDatabaseTableModel.PriceMax) +".",
        "Материал с таким названием уже существует.",
        "Ошибка при работе с базой зависимостей. Убедитесь, что SQLite-база db_dependencies в папке data не повреждена.",
        "Введите шаг округления.",
        "Шаг округления должен лежать в диапазоне "+ String.format("%1$.0f",MaterialDatabaseTableModel.StepMin) +"-"+ String.format("%1$.0f",MaterialDatabaseTableModel.StepMax) +".",
        "Введите порог округления.",
        "Порог округления должен лежать в диапазоне "+ String.format("%1$.0f",MaterialDatabaseTableModel.BorderMin) +"-"+ String.format("%1$.0f",MaterialDatabaseTableModel.BorderMax) +".",
        "Ошибка при работе с базой алгоритмов. Убедитесь, что SQLite-база db_algorithms в папке data не повреждена.",
        "Запрашиваемый материал не найден а базе db_materials. Возможно, он был удален.",
        "Введите имя алгоритма.",
        "Длина имени алгоритма не должна превышать "+ AlgorithmsListTableModel.NameLengthMax +".",
        "Выберите материал из верхнего списка.",
        "Заполните числовые поля.",
        "Значения полей должны больше нуля и меньше "+ String.format("%1$.0f",DependenceDialog.AmountMax) +".",
        "Выберите материал из нижнего списка.",
        "Данный материал используется в алгоритмах и не может быть удален.",
        "Введите имя помещения.",
        "Длина имени помещения не должна превышать "+ RoomsTableModel.NameLengthMax +".",
        "Введите имя поверхности.",
        "Длина имени поверхности не должна превышать "+ RoomEditingTableModel.NameLengthMax +".",
    };
    
    private static String[] MessageTexts = {
        "",
        "Смета успешно создана.",
        "Файл с выбранным именем уже существует. При создании сметы он будет утерян.",
        "Символы   *   -   '   будут заменены на пробелы.",
    };
    
    /**
     * Метод принимает и интерпретирует код, показывает диалоговое окно.
     * @param ParentFrame вызвавшее окно.
     * @param MessageCodeString код ошибки или уведомления.
     */
    public static void ShowDialog(Component ParentFrame, String MessageCodeString) {
        //Код в виде числа.
        int MessageCodeInt;
        //Текст сообщения.
        String MessageText;
        //Тип сообщения - ошибка или уведомление.
        int MessageType;
        
        try{
            //Парсим текстовый код в числовой код.
            MessageCodeInt = Integer.parseInt(MessageCodeString);
        } catch (Exception e)
        {
            //Неизвестная ошибка.
            MessageCodeInt = 0;
        }
        
        //Если код неотрцателен, значит сообщение - ошибка.
        if(MessageCodeInt >= 0) {
            MessageType = JOptionPane.ERROR_MESSAGE;
            //Получаем текст. Код ошибки является индексом текста в массиве.
            MessageText = ErrorTexts[MessageCodeInt];
        //Если отрицателен - уведомление.
        } else {
            MessageType = JOptionPane.INFORMATION_MESSAGE;
            //Получаем текст.
            //Необходимо сменить знак, что использовать код уведомления
            //как индекс текста в массиве.
            MessageText = MessageTexts[-MessageCodeInt];
        }
        
        //Показываем окно.
        JOptionPane.showMessageDialog(ParentFrame, MessageText, "", MessageType);
    }
}
