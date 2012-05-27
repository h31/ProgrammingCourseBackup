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
 * Хелпер для работы с БД "материалы".
 * Соединение держится открытым все время, пока существует объект.
 * Соединение закрывается методом finalize().
 * Однако лучше вручную вызывать метод close(), не дожидаясь срабатывания сборщика мусора.
 * Метод close() также вызывается, когда происходит ошибка.
 * @see datapackage.Material
 */
public class MaterialDatabaseHelper {
    
    private final static String DRIVER = "org.sqlite.JDBC";
    private final static String PROTOCOL = "jdbc:sqlite";
    private final static String FILE_NAME = "db_materials";
    private final static String DATABASE_DIRECTORY = "data";
    
    private final static String TABLE_MATERIALS = "materials";
    private final static String COLUMN_ID = "id";
    private final static String COLUMN_NAME = "name";
    private final static String COLUMN_UNIT = "unit";
    private final static String COLUMN_PRICE = "price";
    private final static String COLUMN_ROUNDING_STEP = "step";
    private final static String COLUMN_ROUNDING_BORDER = "border";
    
    Connection MainConnection = null;
    Statement MainStatement = null;
    
    /**
     * Конструктор.
     * Открывает соединение с БД.
     * @throws ClassNotFoundException в случае ошибки при загрузке драйвера; message = код ошибки для MessageHandler'а
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public MaterialDatabaseHelper() throws ClassNotFoundException, SQLException {
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
     * Метод возвращает массив имен всех материалов БД.
     * @return массив.
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public String[] getMaterialsList() throws SQLException {
        //
        ArrayList<String> ResultList = new ArrayList<String>();
        //
        String[] ResultArray = null;
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_NAME +" FROM "+ TABLE_MATERIALS);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                ResultList.add(result.getString(COLUMN_NAME));
            }
            
            int Amount = ResultList.size();
            ResultArray = new String[Amount];
            ResultArray = ResultList.toArray(ResultArray);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return ResultArray;
    }
    
    /**
     * Метод возвращает список ID всех материалов БД.
     * @return список ID
     * @throws SQLException в случае ошибки при работе с БД; message = код ошибки для MessageHandler'а
     */
    public ArrayList<Long> getIdList() throws SQLException {
        ArrayList<Long> ResultList = new ArrayList<Long>();
        
        try
        {
            //Открываем БД.
            openDatabase();

            //Выполняем.
            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_ID +" FROM "+ TABLE_MATERIALS);
            
            //Перебираем все полученные строки.
            while(result.next())
            {
                ResultList.add(result.getLong(COLUMN_ID));
            }
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return ResultList;
    }
    /*
    public Material getMaterial(String Name) throws SQLException {
        Material mat = null; 
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_NAME +"='"+ Name +"'");
            result.next();
            
            long Id = result.getLong(COLUMN_ID);
            String Unit = result.getString(COLUMN_UNIT);
            double Price = result.getDouble(COLUMN_PRICE);
            double RoundingStep = result.getDouble(COLUMN_ROUNDING_STEP);
            double RoundingBorder = result.getDouble(COLUMN_ROUNDING_BORDER);
                                
            mat = new Material(Id,Name,Unit,Price,RoundingStep,RoundingBorder);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return mat;
    }
    */
    public Material getMaterial(long Id) throws SQLException {
        Material mat = null; 
        ResultSet result;
        
        try
        {
            openDatabase();
            result = MainStatement.executeQuery("SELECT * FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        try
        {       
            result.next();
            
            String Name = result.getString(COLUMN_NAME);
            String Unit = result.getString(COLUMN_UNIT);
            double Price = result.getDouble(COLUMN_PRICE);
            double RoundingStep = result.getDouble(COLUMN_ROUNDING_STEP);
            double RoundingBorder = result.getDouble(COLUMN_ROUNDING_BORDER);
            
            mat = new Material(Id,Name,Unit,Price,RoundingStep,RoundingBorder);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialNotFoundInDatabase);
        }        
        return mat;
    }
    
    public String getName(long Id) throws SQLException {
        String Name;
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_NAME +" FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
            result.next();
            
            Name = result.getString(COLUMN_NAME);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return Name;
    }
    
    public String getUnit(long Id) throws SQLException {
        String Unit;
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_UNIT +" FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
            result.next();
            
            Unit = result.getString(COLUMN_UNIT);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return Unit;
    }
    
    public double getPrice(long Id) throws SQLException {
        double Price;
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_PRICE +" FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
            result.next();
            
            Price = result.getDouble(COLUMN_PRICE);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return Price;
    }
    
    public double getRoundingStep(long Id) throws SQLException {
        double RoundingStep;
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_ROUNDING_STEP +" FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
            result.next();
            
            RoundingStep = result.getDouble(COLUMN_ROUNDING_STEP);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return RoundingStep;
    }
    
    public double getRoundingBorder(long Id) throws SQLException {
        double RoundingBorder;
        
        try
        {
            openDatabase();

            ResultSet result = MainStatement.executeQuery("SELECT "+ COLUMN_ROUNDING_BORDER +" FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"='"+ Id +"'");
            result.next();
            
            RoundingBorder = result.getDouble(COLUMN_ROUNDING_BORDER);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
        
        return RoundingBorder;
    }    
    
    public void setMaterial(Material mat) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(mat.getId());
            String Name = mat.getName();
            String Unit = mat.getUnit();
            String StringPrice = Double.toString(mat.getPrice());
            String StringStep = Double.toString(mat.getRoundingStep());
            String StringBorder = Double.toString(mat.getRoundingBorder());
            
            MainStatement.executeUpdate("INSERT OR REPLACE INTO "+ TABLE_MATERIALS +" VALUES ("+ StringId +",'"+ Name +"','"+ Unit +"',"+ StringPrice +","+ StringStep +","+ StringBorder +")");
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }
    
    public void setName(long Id, String Name) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            MainStatement.executeUpdate("UPDATE "+ TABLE_MATERIALS +" SET "+ COLUMN_NAME +"='"+ Name +"' WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }

    public void setUnit(long Id, String Unit) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            MainStatement.executeUpdate("UPDATE "+ TABLE_MATERIALS +" SET "+ COLUMN_UNIT +"='"+ Unit +"' WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    } 

    public void setPrice(long Id, double Price) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            String StringPrice = Double.toString(Price);
            MainStatement.executeUpdate("UPDATE "+ TABLE_MATERIALS +" SET "+ COLUMN_PRICE +"="+ StringPrice +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }     
    
    public void setRoundingStep(long Id, double RoundingStep) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            String StringStep = Double.toString(RoundingStep);
            MainStatement.executeUpdate("UPDATE "+ TABLE_MATERIALS +" SET "+ COLUMN_ROUNDING_STEP +"="+ StringStep +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }         
    
    public void setRoundingBorder(long Id, double RoundingBorder) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            String StringBorder = Double.toString(RoundingBorder);
            MainStatement.executeUpdate("UPDATE "+ TABLE_MATERIALS +" SET "+ COLUMN_ROUNDING_BORDER +"="+ StringBorder +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }          
    
    public void deleteMaterial(Material mat) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(mat.getId());
            MainStatement.executeUpdate("DELETE FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }
    
    public void deleteMaterial(long Id) throws SQLException {
        try
        {
            openDatabase();
            
            String StringId = Long.toString(Id);
            MainStatement.executeUpdate("DELETE FROM "+ TABLE_MATERIALS +" WHERE "+ COLUMN_ID +"="+ StringId);
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
        }
    }
    
    public long createMaterial(String Name, String Unit, double Price, double RoundingStep, double RoundingBorder) throws SQLException {
        try
        {
            openDatabase();
            
            String StringPrice = Double.toString(Price);
            String StringStep = Double.toString(RoundingStep);
            String StringBorder = Double.toString(RoundingBorder);
            
            MainStatement.executeUpdate("INSERT INTO "+ TABLE_MATERIALS +" ("+ COLUMN_NAME +","+ COLUMN_UNIT +","+ COLUMN_PRICE +","+ COLUMN_ROUNDING_STEP +","+ COLUMN_ROUNDING_BORDER +") VALUES ('"+ Name +"','"+ Unit +"',"+ StringPrice +","+ StringStep +","+ StringBorder +")");
            
            //получаем ID свежесозданной записи
            ResultSet keys = MainStatement.executeQuery("SELECT last_insert_rowid()");
            keys.next();
            long Id = keys.getLong(1);
            
            return Id;
        }
        catch(Exception e)
        {
            close();
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
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
            throw new SQLException(MessageHandler.ERROR_MaterialsDatabaseError);
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
