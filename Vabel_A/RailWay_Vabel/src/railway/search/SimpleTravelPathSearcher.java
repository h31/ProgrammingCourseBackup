package railway.search;

import railway.search.AbstractPathSearcher;
import java.util.ArrayList;
import java.util.List;
import railway.model.RailwayStation;
import railway.model.Time;
import railway.model.Train;
import railway.model.TrainPathItem;
import railway.model.TrevelPath;

/**
 * Алгоритм реализует простой поиск маршрута (перебор)
 */
public class SimpleTravelPathSearcher extends AbstractPathSearcher {

    public SimpleTravelPathSearcher(SearchParams param) throws Exception {
        super(param);
    }

    @Override
    public List<TrevelPath> findTrevelPath() {
        List<TrevelPath> path = new ArrayList<TrevelPath>();
        RailwayStation start = param.getStartPoint();
        RailwayStation end = param.getEndPoint();
        // Поиск прямого поезда
        for (Train trainStart : start.getTrains()) {
            for (Train trainEnd : end.getTrains()) {
                if (trainStart.getNumber() == trainEnd.getNumber()) {

                    Time startTime = trainStart.getTrainPath().getOutcomingTimeByStation(start);
                    Time endTime = trainEnd.getTrainPath().getIncomingTimeByStation(end);
                    if (isCheckedIncoming(endTime) && isCheckedOutcoming(startTime)) {
                        if (trainStart.getTrainPath().getStationNumber(start.getStationName()) < trainStart.getTrainPath().
                                getStationNumber(end.getStationName())) {
                            path.add(new TrevelPath(trainStart.getName(), trainStart.getTrainPath().getItemByStation(start), trainStart.getTrainPath().getItemByStation(end)));
                        }
                    }
                }
            }
        }
        // Если прмой не найден, ищем с пересадками
        if (path.isEmpty()) {
            for (Train trainStart : start.getTrains()) {
                for (Train trainEnd : end.getTrains()) {
                    for (TrainPathItem searchItem : trainStart.getTrainPath().getPathItems()) {
                        TrainPathItem searchedItem = trainEnd.getTrainPath().getItemByStation(searchItem.getStation());
                        //Если найдено пересечение
                        if(searchedItem!=null){
                            //Проверка в том ли направлении двигается стартовый поезд и конечный поезд после пересадки
                            if((trainStart.getTrainPath().getStationNumber(start.getStationName()) < trainStart.getTrainPath().
                                getStationNumber(searchItem.getStation().getStationName()))&&
                                (trainEnd.getTrainPath().getStationNumber(end.getStationName()) > trainEnd.getTrainPath().
                                getStationNumber(searchedItem.getStation().getStationName()))){
                                // Проверяем время отправки
                                Time startTime = trainStart.getTrainPath().getOutcomingTimeByStation(start);
                                Time endTime = trainEnd.getTrainPath().getIncomingTimeByStation(end);
                                if (isCheckedIncoming(endTime) && isCheckedOutcoming(startTime)){
                                    path.add(new TrevelPath(trainStart.getName(),
                                            trainStart.getTrainPath().getItemByStation(start), searchItem));
                                    path.add(new TrevelPath(trainEnd.getName(),
                                            searchedItem, trainEnd.getTrainPath().getItemByStation(end)));
                                }
                            }
                        }
                    }
                }
            }
        }

        return path;
    }

    public boolean isCheckedOutcoming(Time start) {
        if (start != null) {
            if (start.isAfter(param.getOutcomingTimeFrom()) && start.isBefore(param.getOutcomingTimeTo())) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    public boolean isCheckedIncoming(Time end) {
        if (end != null) {
            if (end.isAfter(param.getIncomingTimeFrom()) && end.isBefore(param.getIncomingTimeTo())) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
