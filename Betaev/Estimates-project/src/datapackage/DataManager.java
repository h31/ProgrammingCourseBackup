package datapackage;

import java.sql.SQLException;

public class DataManager {
    //хелпер для работы с базой зависимостей
    private DependenciesDatabaseHelper DepHelper;
    //хелпер для работы с базой материалов
    private MaterialDatabaseHelper MatHelper;
    //хелпер для работы с базой алгоритмов
    private AlgorithmDatabaseHelper AlgHelper;
    
    public DataManager() {
    }
    
    public void Init() throws ClassNotFoundException, SQLException{
        DepHelper = new DependenciesDatabaseHelper();
        MatHelper = new MaterialDatabaseHelper();
        AlgHelper = new AlgorithmDatabaseHelper();
    }
    
    public DependenciesDatabaseHelper getDependenciesHelper() {
        return DepHelper;
    }
    
    public MaterialDatabaseHelper getMaterialsHelper() {
        return MatHelper;
    }
    
    public AlgorithmDatabaseHelper getAlgorithmsHelper() {
        return AlgHelper;
    }    
}
