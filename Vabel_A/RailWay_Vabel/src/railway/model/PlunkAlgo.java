
package railway.model;

/**
 * Алгоритм реализует простой поиск маршрута (перебор)
 */
public class PlunkAlgo extends AbstractAlgo{

    public PlunkAlgo(SearchParams param) throws Exception {
        super(param);
    }


    @Override
    public TrevelPath findTrevelPath() {
        TrevelPath path = new TrevelPath();
        RailwayStation start = param.getStartPoint();

        for(Train train : start.getTrains()){
           //поезд проходит через искомую станцию
            if(train.getTrainPath().contains(param.getEndPoint())){
                //если пункт отправления после пункта назначения в пути следования поезда,
               if(train.getTrainPath().indexOf(start) > train.getTrainPath().indexOf(param.getEndPoint())){
                   //этот поезд нам не подходит
                   continue;
               }

               int startIdx = train.getTrainPath().indexOf(start);
               int endIdx = train.getTrainPath().indexOf(param.getEndPoint());
               TrainPathItem startEq = train.getTrainPath().get(startIdx);
               TrainPathItem endEq = train.getTrainPath().get(endIdx);
               //раз попали сюда, посмотрим, попадаем ли мы в нужное нам время
               if((startEq.getOutcomingTime().equals(param.getOutcomingTimeFrom()) || startEq.getOutcomingTime().after(param.getOutcomingTimeFrom())) &&
                   ((startEq.getOutcomingTime().equals(param.getOutcomingTimeTo()) || startEq.getOutcomingTime().before(param.getOutcomingTimeTo()))) && 
                   (endEq.getIncomingTime().equals(param.getIncomingTimeFrom()) || endEq.getIncomingTime().after(param.getIncomingTimeFrom())) && 
                   ((endEq.getIncomingTime().equals(param.getIncomingTimeTo()) || endEq.getIncomingTime().before(param.getIncomingTimeTo())))){

                   //попали в заданные рамки, можем сказать что этот маршрут нам подходит
                   //заполним маршрут
                   for(int i = startIdx; i <= endIdx; ++i){
                       path.addPathItem(train.getTrainPath().get(i));
                   }
                   //считаем что нашли
                   return path;

               }
           }
        }

        return null;
    }


    
}
