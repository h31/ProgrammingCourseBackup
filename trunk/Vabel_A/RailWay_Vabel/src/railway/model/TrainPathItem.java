package railway.model;

import java.util.Calendar;

/**
 * Остановка поезда на пути следования
 */
public class TrainPathItem {
    /**
     * Время прибытия
     */
    private Calendar incomingTime;
    /**
     * Время отправления
     */
    private Calendar outcomingTime;

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
    public TrainPathItem(Calendar incomingTime, Calendar outcomingTime, RailwayStation station) {
        this.incomingTime = incomingTime;
        this.outcomingTime = outcomingTime;
        this.station = station;
    }

    /**
     * @return {@link #incomingTime}
     */
    public Calendar getIncomingTime() {
        return incomingTime;
    }

    /**
     * Устанавливает {@link #incomgTime}
     * @param incomingTime время прибытия которое необходимо установить
     */
    public void setIncomingTime(Calendar incomingTime) {
        this.incomingTime = incomingTime;
    }

    /**
     * @return {@link #outcomingTime}
     */
    public Calendar getOutcomingTime() {
        return outcomingTime;
    }

    /**
     * устанавливает {@link #outcomingTime}
     * @param outcomingTime время отправления которое необходимо установить
     */
    public void setOutcomingTime(Calendar outcomingTime) {
        this.outcomingTime = outcomingTime;
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
