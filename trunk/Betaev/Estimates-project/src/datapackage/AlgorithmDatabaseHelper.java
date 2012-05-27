package datapackage;

import guipackage.MessageHandler;
import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

/**
 * Хелпер для работы с БД "алгоритмы".
 * Соединение держится открытым все время, пока существует объект.
 * Соединение закрывается методом finalize().
 * Однако лучше вручную вызывать метод close(), не дожидаясь срабатывания сборщика мусора.
 * Метод close() также вызывается, когда происходит ошибка.
 * @see datapackage.Algorithm
 */
public class AlgorithmDatabaseHelper {
    
    private final static String DRIVER = "org.sqlite.JDBC";
    private final static String PROTOCOL = "jdbc:sqlite";
    private final static String FILE_NAME = "db_algorithms";
    private final static String DATABASE_DIRECTORY = "data";
    
    private final static String TABLE_ALGORITHMS = "algorithms";
    private final static String COLUMN_ID = "id";
    private final static String COLUMN_NAME = "name";
    
    Connection MainConnection = null;
    Statement MainStatement = null;
    
    /**
     * Конструктор.
     * Открывает соединение с БД.
     * @throws ClassNotFoundException в случае ошибки при загрузке драйвера; message = код ошибки для MessageHandler'а
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public AlgorithmDatabaseHelper() throws ClassNotFoundException, SQLException {
        try
        {
            //Подгружаем драйвер для работы с SQLite.
            Class.forName(DRIVER);
        } catch (ClassNotFoundException e)
        {
            throw new ClassNotFoundException(MessageHandler.ERROR_JdbcError);
        }
        
        //Открываем БД.
        openDatabase();
    }
    
    /**
     * Метод возвращает список всех алгоритмов
     * @return список алгоритмов
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public ArrayList<Algorithm> getAlgorithmsList() throws SQLException {
        ArrayList<Algorithm> ResultList = new ArrayList<Algorithm>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_ALGORITHMS);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                //создаем зависимость, добавляем в результирующий лист
                long Id = result.getLong(COLUMN_ID);
                String Name = result.getString(COLUMN_NAME);
                ResultList.add(new Algorithm(Id,Name));
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_AlgorithmDatabaseError);
        }
        
        return ResultList;
    }
    
    public Algorithm createAlgorithm(String Name) throws SQLException {
        try
        {
            openDatabase();
            MainStatement.executeUpdate("INSERT INTO "+ TABLE_ALGORITHMS +" ("+ COLUMN_NAME +") VALUES ('"+ Name +"')");
            
            //получаем ID свежесозданной записи
            ResultSet keys = MainStatement.executeQuery("SELECT last_insert_rowid()");
            keys.next();
            long Id = keys.getLong(1);
            
            Algorithm alg = new Algorithm(Id, Name);
            return alg;
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_AlgorithmDatabaseError);
        }
    }    
    
    public void setAlgorithm(Algorithm alg) throws SQLException {
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringId = Long.toString(alg.getId());
            String Name = alg.getName();
            MainStatement.executeUpdate("INSERT OR REPLACE INTO "+ TABLE_ALGORITHMS +" VALUES ("+ StringId +",'"+ Name +"')");
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_AlgorithmDatabaseError);
        }
    }
    
    public void deleteAlgorithm(Algorithm alg) throws SQLException {
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringId = Long.toString(alg.getId());
            MainStatement.executeUpdate("DELETE FROM "+ TABLE_ALGORITHMS +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_AlgorithmDatabaseError);
        }
    }
    
    private void openDatabase() throws SQLException{
        try
        {
            if(MainConnection == null)
            {
                MainConnection = DriverManager.getConnection(PROTOCOL + ":" + DATABASE_DIRECTORY + File.separatorChar + FILE_NAME);
                System.err.println("connection opened");
                MainStatement = MainConnection.createStatement();
                MainStatement.setQueryTimeout(10);
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_AlgorithmDatabaseError);
        }
    }
    
    public void close() {
        try
        {
            if(MainConnection != null)
            MainConnection.close();
            MainConnection = null;
            System.err.println("connection closed");
        }
        catch(Exception e)
        {
            System.err.println("connection close failed");
        }
    }
    
    @Override
    protected void finalize() throws Throwable{
        close();
        super.finalize();
    }    
}
