
package railway.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Железнодорожная станция
 */
public class RailwayStation {

    /**
     * Название станции
     */
    private String stationName;

    /**
     * Пути от этой станции до других
     */
    private List<Railway> ways;


    /**
     * Поезда этой станции
     */
    private final List<Train> trains;

    public RailwayStation(String stationName) {
        this.stationName = stationName;
        ways = new ArrayList<Railway>();
        trains = new ArrayList<Train>();
    }

    public void addTrain(Train train){
        trains.add(train);
    }

    /**
     * @return {@link #stationName}
     */
    public String getStationName() {
        return stationName;
    }

    /**
     *  sets {@link #stationName}
     */
    public void setStationName(String stationName) {
        this.stationName = stationName;
    }

    /**
     *  Возвращает true если есть путь до станции с названием name
     */
    public boolean isContainsWayTo(RailwayStation station){
        String name = station.getStationName();
        for(Railway way : ways){
            RailwayStation other = getOtherStation(way, this);
            if(other.getStationName().equals(name)){
                return true;
            }
        }
        return false;
    }

    /**
     *  Если current
     * @param railway
     * @param current
     * @return
     */
    public static RailwayStation getOtherStation(Railway railway, RailwayStation current){
        if(railway.getStation1().equals(current)){
            return railway.getStation2();
        }
        return railway.getStation1();
    }


    /**
     * Возвращает true если есть путь до станции с названием name
     */
    public boolean isContainsWayTo(String stationName){
        for(Railway way : ways){
            RailwayStation other = getOtherStation(way, this);
            if(other.getStationName().equals(stationName)){
                return true;
            }
        }
        return false;
    }

    /**
     * Возвращает кратчайший путь
     */
    public Railway getShotestWay(){
        Railway min = null;
        double minLen = Double.MAX_VALUE;
        for(Railway way : ways){
            if(minLen > way.getLenght()){
                minLen = way.getLenght();
                min = way;
            }
        }
        return min;
    }

    /**
     * Возвращает количество ЖД путей идущих от текущей станции
     */
    public int getWaysCount(){
        return ways.size();
    }

    /**
     * Очищает пути
     * @throws Exception
     */
    public void cleanWays() throws Exception{
        for(int idx = ways.size() - 1; idx >= 0; --idx){
            Railway way = ways.get(idx);
            way.cleanStation(this);
            ways.remove(way);
        }
    }

    public  List<Train> getTrains(){
        return trains;
    }

    @Override
    public String toString() {
        return stationName ;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final RailwayStation other = (RailwayStation) obj;
        if ((this.stationName == null) ? (other.stationName != null) : !this.stationName.equals(other.stationName)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 97 * hash + (this.stationName != null ? this.stationName.hashCode() : 0);
        hash = 97 * hash + (this.ways != null ? this.ways.hashCode() : 0);
        hash = 97 * hash + (this.trains != null ? this.trains.hashCode() : 0);
        return hash;
    }
    


}
