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
 * Хелпер для работы с БД "зависимости".
 * Соединение держится открытым все время, пока существует объект.
 * Соединение закрывается методом finalize().
 * Однако лучше вручную вызывать метод close(), не дожидаясь срабатывания сборщика мусора.
 * Метод close() также вызывается, когда происходит ошибка.
 * @see datapackage.Dependence
 */
public class DependenciesDatabaseHelper {
    
    private final static String DRIVER = "org.sqlite.JDBC";
    private final static String PROTOCOL = "jdbc:sqlite";
    private final static String FILE_NAME = "db_dependencies";
    private final static String DATABASE_DIRECTORY = "data";
    
    private final static String TABLE_DEPENDENCIES = "dependencies";
    private final static String COLUMN_ID = "id";
    private final static String COLUMN_ALGORITHM_ID = "alg_id";
    private final static String COLUMN_INDEPENDENT_ID = "indep_id";
    private final static String COLUMN_INDEPENDENT_FACTOR = "indep_factor";
    private final static String COLUMN_DEPENDENT_ID = "dep_id";
    private final static String COLUMN_DEPENDENT_FACTOR = "dep_factor";
    
    Connection MainConnection = null;
    Statement MainStatement = null;
    
    /**
     * Конструктор.
     * Открывает соединение с БД.
     * @throws ClassNotFoundException в случае ошибки при загрузке драйвера; message = код ошибки для MessageHandler'а
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public DependenciesDatabaseHelper() throws ClassNotFoundException, SQLException {
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
     * Метод возвращает список всех зависимостей, принадлежащих данному алгоритму.
     * @param AlgorithmId ID алгоритма
     * @return список зависимостей
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public ArrayList<Dependence> getDependencies(long AlgorithmId) throws SQLException {
        ArrayList<Dependence> ResultList = new ArrayList<Dependence>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringId = Long.toString(AlgorithmId);
            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ALGORITHM_ID +"="+ StringId);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                //создаем зависимость, добавляем в результирующий лист
                long Id = result.getLong(COLUMN_ID);
                long IndependentId = result.getLong(COLUMN_INDEPENDENT_ID);
                double IndependentFactor = result.getDouble(COLUMN_INDEPENDENT_FACTOR);
                long DependentId = result.getLong(COLUMN_DEPENDENT_ID);
                double DependentFactor = result.getDouble(COLUMN_DEPENDENT_FACTOR);
                ResultList.add(new Dependence(Id,AlgorithmId,IndependentId,IndependentFactor,DependentId,DependentFactor));
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
        
        return ResultList;
    }
    
    public ArrayList<Dependence> getDependenciesByDependentId(long AlgorithmId, long DependentId) throws SQLException {
        ArrayList<Dependence> ResultList = new ArrayList<Dependence>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringAlgId = Long.toString(AlgorithmId);
            String StringDepId = Long.toString(DependentId);
            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ALGORITHM_ID +"="+ StringAlgId +" AND "+ COLUMN_DEPENDENT_ID +"="+ StringDepId);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                //создаем зависимость, добавляем в результирующий лист
                long Id = result.getLong(COLUMN_ID);
                long IndependentId = result.getLong(COLUMN_INDEPENDENT_ID);
                double IndependentFactor = result.getDouble(COLUMN_INDEPENDENT_FACTOR);
                double DependentFactor = result.getDouble(COLUMN_DEPENDENT_FACTOR);
                ResultList.add(new Dependence(Id,AlgorithmId,IndependentId,IndependentFactor,DependentId,DependentFactor));
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
        
        return ResultList;
    }
    
    public ArrayList<Dependence> getDependenciesByIndependentId(long AlgorithmId, long IndependentId) throws SQLException {
        ArrayList<Dependence> ResultList = new ArrayList<Dependence>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringAlgId = Long.toString(AlgorithmId);
            String StringIndepId = Long.toString(IndependentId);
            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ALGORITHM_ID +"="+ StringAlgId +" AND "+ COLUMN_INDEPENDENT_ID +"="+ StringIndepId);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                //создаем зависимость, добавляем в результирующий лист
                long Id = result.getLong(COLUMN_ID);
                long DependentId = result.getLong(COLUMN_DEPENDENT_ID);
                double IndependentFactor = result.getDouble(COLUMN_INDEPENDENT_FACTOR);
                double DependentFactor = result.getDouble(COLUMN_DEPENDENT_FACTOR);
                ResultList.add(new Dependence(Id,AlgorithmId,IndependentId,IndependentFactor,DependentId,DependentFactor));
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
        
        return ResultList;
    }    
    
    public ArrayList<Long> getDependentMaterialsIdList(long AlgorithmId) throws SQLException {
        ArrayList<Long> ResultList = new ArrayList<Long>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringId = Long.toString(AlgorithmId);
            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_DEPENDENT_ID +" FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ALGORITHM_ID +"="+ StringId);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                Long DependentId = result.getLong(COLUMN_DEPENDENT_ID);
                if(!ResultList.contains(DependentId))
                {
                    ResultList.add(DependentId);
                }
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
        
        return ResultList;
    }
    
    public void deleteDependencies(long AlgorithmId) throws SQLException {
        try
        {
            openDatabase();
            
            String StringAlgId = Long.toString(AlgorithmId);
            MainStatement.executeUpdate("DELETE FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ALGORITHM_ID +"="+ StringAlgId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
    }    
    
    public void deleteDependence(Dependence dep) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(dep.getId());
            MainStatement.executeUpdate("DELETE FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
    }        
    
    public Dependence createDependence(long AlgorithmId, long IndependentId, double IndependentFactor, long DependentId, double DependentFactor) throws SQLException {
        try
        {
            openDatabase();
            
            String StringAlgId = Double.toString(AlgorithmId);
            String StringIndepId = Double.toString(IndependentId);
            String StringIndepFact = Double.toString(IndependentFactor);
            String StringDepId = Double.toString(DependentId);
            String StringDepFact = Double.toString(DependentFactor);

            MainStatement.executeUpdate("INSERT INTO "+ TABLE_DEPENDENCIES +" ("+ COLUMN_ALGORITHM_ID +","+ COLUMN_INDEPENDENT_ID +","+ COLUMN_INDEPENDENT_FACTOR +","+ COLUMN_DEPENDENT_ID +","+ COLUMN_DEPENDENT_FACTOR +") VALUES ('"+ StringAlgId +"','"+ StringIndepId +"',"+ StringIndepFact +","+ StringDepId +","+ StringDepFact +")");
            
            ResultSet keys = MainStatement.executeQuery("SELECT last_insert_rowid()");
            keys.next();
            long Id = keys.getLong(1);
            
            return new Dependence(Id,AlgorithmId,IndependentId,IndependentFactor,DependentId,DependentFactor);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
        }
    }    
    
    public boolean isMaterialBeingUsed(long materialId) throws SQLException {
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            String StringId = Long.toString(materialId);
            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_DEPENDENCIES +" WHERE "+ COLUMN_DEPENDENT_ID +"="+ StringId);
            
            while( result.next() ) {
                //результат не пустой
                return true;
            }
            //результат пустой
            return false;
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
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
            throw new SQLException(MessageHandler.ERROR_DependenciesDatabaseError);
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
