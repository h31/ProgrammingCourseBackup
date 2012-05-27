package logicpackage;

import supportpackage.CalculatedMaterial;
import supportpackage.EstimateProperties;
import excelpackage.ExcelHelper;
import datapackage.*;
import java.io.IOException;
import jxl.write.WriteException;
import java.sql.SQLException;
import java.util.ArrayList;
import supportpackage.Estimate;
import supportpackage.Room;
import supportpackage.Surface;

//TODO переписать комментарии
//TODO сообщение о зацикленности?
//TODO итоговый массив

/**
 * Класс получает описание задания,
 * рассчитывает количество всех материалов в смете
 * и передает результат ЭксельХелперу.
 * @see excelpackage.ExcelHelper
 * @see supportpackage.TaskDescription
 * @see supportpackage.Material
 */
public class LogicHelper {
   
    //хелпер для работы с базой зависимостей
    private DependenciesDatabaseHelper DepHelper;
    //хелпер для работы с базой материалов
    private MaterialDatabaseHelper MatHelper;
    //проверка
    private long CheckingId;
    private int Depth;
    private int MaterialsAmount;
    
    /**
     * Конструктор.
     */
    public LogicHelper(DataManager data) {
        DepHelper = data.getDependenciesHelper();
        MatHelper = data.getMaterialsHelper();
    }
    
    /**
     * Метод выполняет основную работу:
     * рассчитывает количество всех материалов в смете
     * и передает результат ЭксельХелперу.
     * @throws IOException в случае ошибки в работе ЭксельХелпера.
     * @throws WriteException в случае ошибки в работе ЭксельХелпера.
     */
    public void CalculateEstimates(Estimate Est, EstimateProperties Properties) throws IOException, WriteException, SQLException {
        //берем массив помещений из сметы
        ArrayList<Room> Rooms = Est.getRooms();        
        for(int i=0; i<Rooms.size(); i++)
        {
            //рассчитываем каждое помещение
            CalculateRoom(Rooms.get(i));
        }
        
        //составляем общий итоговый массив
        ComposeTotalOutput(Est);
        
        //закрываем БД-хелперы
        CloseDatabaseHelpers();
        //Создаем ЭксельХелпер, передаем ему рассчитанную смету
        ExcelHelper ExcHelper = new ExcelHelper(Est, Properties);
        ExcHelper.DrawEstimates();
    }
    
    public boolean isAlgorithmLooped(long AlgId) throws SQLException{
        CheckingId = AlgId;
        MaterialsAmount = DepHelper.getDependentMaterialsIdList(CheckingId).size();

        try {
            //получаем список зависимостей от "ничего"
            ArrayList<Dependence> DependenciesOnNothing = DepHelper.getDependenciesByIndependentId(CheckingId, Dependence.DEPEND_ON_NOTHING_ID);
            //цикл для каждой из зависимостей
            for (int i=0; i<DependenciesOnNothing.size(); i++)
            {
                CheckDependenceOnNothing(DependenciesOnNothing.get(i));
            }

            //получаем список зависимостей от поверхности
            ArrayList<Dependence> DependenciesOnSurface = DepHelper.getDependenciesByIndependentId(CheckingId, Dependence.DEPEND_ON_SURFACE_ID);
            //цикл для каждой из зависимостей
            for (int i=0; i<DependenciesOnSurface.size(); i++)
            {
                CheckDependenceOnSurface(DependenciesOnSurface.get(i));
            }    
        }
        catch(IllegalArgumentException e)
        {
            return true;
        }
        return false;
    }
    
    private void CalculateRoom(Room CurrentRoom) throws SQLException{
        //обнуляем массивы материалов текущей комнаты
        CurrentRoom.getCeilingOutput().clear();
        CurrentRoom.getFloorOutput().clear();
        CurrentRoom.getWallOutput().clear();
        
        //берем список поверхностей текущей комнаты
        ArrayList<Surface> Surfaces = CurrentRoom.getSurfaces();        

        for(int i=0; i<Surfaces.size(); i++)
        {
            //рассчитываем каждую поверхность
            CalculateSurface(Surfaces.get(i), CurrentRoom);
        }
        
        //округляем массивы материалов
        RoundRoomOutputArrays(CurrentRoom);
    }
    
    private void CalculateSurface(Surface CurrentSurface, Room CurrentRoom) throws SQLException{
        //берем ID алгоритма, назначенного текущей поверхности
        long AlgorithmId = CurrentSurface.getAlgorithmId();
        //ссылка на выходной массив материалов
        ArrayList<CalculatedMaterial> Output;
        
        //определяем тип поверхности
        switch(CurrentSurface.getType())
        {
            //если потолок
            case Surface.TYPE_CEILING:
                //материалы будут добавлены в массив материалов для потолков текущей комнаты
                Output = CurrentRoom.getCeilingOutput();
                break;
                
            //если пол
            case Surface.TYPE_FLOOR:
                //материалы будут добавлены в массив материалов для полов текущей комнаты
                Output = CurrentRoom.getFloorOutput();
                break;
                
            //если стена    
            case Surface.TYPE_WALL:
            default:
                //материалы будут добавлены в массив материалов для стен текущей комнаты
                Output = CurrentRoom.getWallOutput();
        }
        
        //получаем список ID материалов, задействованных в используемом алгоритме
        ArrayList<Long> MaterialsIdList = DepHelper.getDependentMaterialsIdList(AlgorithmId);
        //добавляем их в выходной массив
        AddMaterialsToOutputArray(MaterialsIdList, Output);
        
        //проверяем, не зациклен ли алгоритм
        if(isAlgorithmLooped(AlgorithmId))
        {
            return;
        }
        
        //рассчитываем алгоритм
        CalculateAlgorithm(Output, CurrentSurface, AlgorithmId);
    }
    
    private void AddMaterialsToOutputArray(ArrayList<Long> MaterialsIdList, ArrayList<CalculatedMaterial> Output) throws SQLException {
        //цикл для каждого материала в алгоритме
        for(int CurrentMaterialIndex = 0; CurrentMaterialIndex < MaterialsIdList.size(); CurrentMaterialIndex++)
        {
            long CurrentMaterialId = MaterialsIdList.get(CurrentMaterialIndex);
            //если он уже есть в текущем массиве - возврат
            for (int i=0; i<Output.size(); i++)
            {
                if (Output.get(i).getId() == CurrentMaterialId)
                {
                    return;
                }
            }
            
            //если нет - получаем описание материала из БД
            Material mat = MatHelper.getMaterial(CurrentMaterialId);
            //добавляем описание в выходной массив
            Output.add(new CalculatedMaterial(mat.getId(), mat.getName(), mat.getUnit(), 0, mat.getPrice()));
        }        
    }
  
    private void CalculateAlgorithm(ArrayList<CalculatedMaterial> Output, Surface CurrentSurface, long AlgorithmId) throws SQLException {
        //получаем список зависимостей от "ничего"
        ArrayList<Dependence> DependenciesOnNothing = DepHelper.getDependenciesByIndependentId(AlgorithmId, Dependence.DEPEND_ON_NOTHING_ID);
        //цикл для каждой из зависимостей
        for (int i=0; i<DependenciesOnNothing.size(); i++)
        {
            //рассчитываем зависимость
            CalculateDependenceOnNothing(Output, DependenciesOnNothing.get(i), AlgorithmId);
        }
        
        //получаем список зависимостей от поверхности
        ArrayList<Dependence> DependenciesOnSurface = DepHelper.getDependenciesByIndependentId(AlgorithmId, Dependence.DEPEND_ON_SURFACE_ID);
        //цикл для каждой из зависимостей
        for (int i=0; i<DependenciesOnSurface.size(); i++)
        {
            //рассчитываем зависимость
            CalculateDependenceOnSurface(Output, CurrentSurface, DependenciesOnSurface.get(i), AlgorithmId);
        }        
    }
    
    private void CalculateDependenceOnNothing(ArrayList<CalculatedMaterial> Output, Dependence CurrentDependence, long AlgorithmId) throws SQLException {
        //количество материала (вес ребра) = фиксированная величина
        double Weight = CurrentDependence.getDependentFactor();
        
        //ID зависимого материала
        long DependentMaterialId = CurrentDependence.getDependentId();
        //увеличиваем количество зависимого материала
        IncreaseOutputAmount(Output, DependentMaterialId, Weight);
        
        //получаем список материалов, в свою очередь зависящих от данного зависимого материала
        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(AlgorithmId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            //передаем каждому из них вес данного ребра
            CalculateDependenceOnOther(Output, DependenciesOnThis.get(i), AlgorithmId, Weight);
        }
    }
    
    private void CalculateDependenceOnSurface(ArrayList<CalculatedMaterial> Output, Surface CurrentSurface, Dependence CurrentDependence, long AlgorithmId) throws SQLException {
        //количество материала (вес ребра) зависит от метража текущей поверхности
        double Weight = CurrentSurface.getMeasure() * CurrentDependence.getDependentFactor() / CurrentDependence.getIndependentFactor();
        
        //ID зависимого материала
        long DependentMaterialId = CurrentDependence.getDependentId();
        //увеличиваем количество зависимого материала
        IncreaseOutputAmount(Output, DependentMaterialId, Weight);

        //получаем список материалов, в свою очередь зависящих от данного зависимого материала
        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(AlgorithmId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            //передаем каждому из них вес данного ребра
            CalculateDependenceOnOther(Output, DependenciesOnThis.get(i), AlgorithmId, Weight);
        }
    }    
    
    private void CalculateDependenceOnOther(ArrayList<CalculatedMaterial> Output, Dependence CurrentDependence, long AlgorithmId, double InputWeight) throws SQLException {
        //количество материала (вес ребра) зависит от количества вышестоящего материала (вес предыдущего ребра) согласно коэффицентам
        double Weight = InputWeight * CurrentDependence.getDependentFactor() / CurrentDependence.getIndependentFactor();
        
        //ID зависимого материала
        long DependentMaterialId = CurrentDependence.getDependentId();
        //увеличиваем количество зависимого материала
        IncreaseOutputAmount(Output, DependentMaterialId, Weight);
        
        //получаем список материалов, в свою очередь зависящих от данного зависимого материала
        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(AlgorithmId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            //передаем каждому из них вес данного ребра
            CalculateDependenceOnOther(Output, DependenciesOnThis.get(i), AlgorithmId, Weight);
        }
    }    
    
    private void IncreaseOutputAmount(ArrayList<CalculatedMaterial> Output, long MaterialId, double inc) throws SQLException {
        //ищем данный материал в текущем выходном массиве
        for (int i=0; i<Output.size(); i++)
        {
            if (Output.get(i).getId() == MaterialId)
            {
                //увеличиваем количество
                Output.get(i).IncreaseAmount(inc);
                return;
            }
        }
    }
    
    private void RoundRoomOutputArrays(Room CurrentRoom) throws SQLException {
        ArrayList<CalculatedMaterial> Output;
        //округляем массив материалов для потолков
        Output = CurrentRoom.getCeilingOutput();
        RoundOutputArray(Output);
        //округляем массив материалов для полов
        Output = CurrentRoom.getFloorOutput();
        RoundOutputArray(Output);
        //округляем массив материалов для стен
        Output = CurrentRoom.getWallOutput();
        RoundOutputArray(Output);
    }
    
    private void RoundOutputArray(ArrayList<CalculatedMaterial> Output) throws SQLException {
        //цикл для каждого материала в итоговом массиве
        for(int CurrentMaterialIndex = 0; CurrentMaterialIndex < Output.size(); CurrentMaterialIndex++)
        {
            CalculatedMaterial OutputMat = Output.get(CurrentMaterialIndex);
            //получаем описание материала из БД
            Material mat = MatHelper.getMaterial(OutputMat.getId());
            //берем шаг округления материала
            double RoundingStep = mat.getRoundingStep();
            //если требуется округление
            if (RoundingStep != 0)
            {
                //берем порог округления материала
                double RoundingBorder = mat.getRoundingBorder();
                //округляем согласно шагу и порогу
                OutputMat.RoundAmount(RoundingStep, RoundingBorder);
            }
        }        
    }
    
    private void CheckDependenceOnNothing(Dependence CurrentDependence) throws SQLException, IllegalArgumentException {
        Depth = 0;
        long DependentMaterialId = CurrentDependence.getDependentId();
        
        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(CheckingId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            CheckDependenceOnOther(DependenciesOnThis.get(i));
        }
    }
    
    private void CheckDependenceOnSurface(Dependence CurrentDependence) throws SQLException, IllegalArgumentException {
        Depth = 0;
        long DependentMaterialId = CurrentDependence.getDependentId();

        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(CheckingId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            CheckDependenceOnOther(DependenciesOnThis.get(i));
        }
    }    
    
    private void CheckDependenceOnOther(Dependence CurrentDependence) throws SQLException, IllegalArgumentException {
        Depth += 1;
        if (Depth == MaterialsAmount) throw new IllegalArgumentException();
        long DependentMaterialId = CurrentDependence.getDependentId();
        
        ArrayList<Dependence> DependenciesOnThis = DepHelper.getDependenciesByIndependentId(CheckingId, DependentMaterialId);
        for (int i=0; i<DependenciesOnThis.size(); i++)
        {
            CheckDependenceOnOther(DependenciesOnThis.get(i));
        }
        Depth -= 1;
    } 
    
    private void ComposeTotalOutput(Estimate Est) {
        //TODO
    }

    private void CloseDatabaseHelpers() {
        DepHelper.close();
        MatHelper.close();
    }
}
