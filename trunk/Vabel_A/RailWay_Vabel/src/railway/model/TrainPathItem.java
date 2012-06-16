package railway.model;

import java.util.Calendar;

/**
 * Остановка поезда на пути следования
 */
public class TrainPathItem {

    /**
     * Время прибытия
     */
    private Time incomingTime;
    /**
     * Время отправления
     */
    private Time outcomingTime;
    /**
     * Станция на которую прибывает и с которой отправляется
     */
    private RailwayStation station;

    /**
     * Конструктор
     * @param incomingTime  Время прибытия
     * @param outcomingTime Время отправления
     * @param station       Станция
     */
    public TrainPathItem(RailwayStation station) {
        this.station = station;
    }

    public TrainPathItem() {
        incomingTime = new Time();
        outcomingTime = new Time();
    }

    /**
     * @return {@link #incomingTime}
     */
    public Time getIncomingTime() {
        return incomingTime;
    }

    /**
     * Устанавливает {@link #incomgTime}
     * @param incomingTime время прибытия которое необходимо установить
     */
    public void setIncomingTime(String incomingTimeString) {
        this.incomingTime.parseToTime(incomingTimeString);
    }

    /**
     * @return {@link #outcomingTime}
     */
    public Time getOutcomingTime() {
        return outcomingTime;
    }

    /**
     * устанавливает {@link #outcomingTime}
     * @param outcomingTime время отправления которое необходимо установить
     */
    public void setOutcomingTime(String outcomingTime) {
        this.outcomingTime.parseToTime(outcomingTime);
    }

    /**
     * @return {@link #station}
     */
    public RailwayStation getStation() {
        return station;
    }

    /**
     * Устанавливает {@link AbstractMethodError#station}
     * @param station станция которую необходимо установить
     */
    public void setStation(RailwayStation station) {
        this.station = station;
    }
}
