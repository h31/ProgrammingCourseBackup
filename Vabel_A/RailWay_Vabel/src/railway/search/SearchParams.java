package railway.search;

import java.util.Calendar;
import railway.model.RailwayStation;
import railway.model.Time;

/**
 *
 * Параметры поиска
 */
public class SearchParams {

    /**
     * Станция отправления
     */
    private RailwayStation startPoint;

    /**
     * Станция назначения
     */
    private RailwayStation endPoint;

    /**
     * Время отправления (от)
     */
    private Time outcomingTimeFrom;

    /**
     * Время отправления (до)
     */
    private Time outcomingTimeTo;
    /**
     * Время прибытия (от)
     */
    private Time incomingTimeFrom;


    /**
     * Время прибытия (до)
     */
    private Time incomingTimeTo;

    /**
     * Конструктор
     * @param startPoint станция отправления
     * @param endPoint станция прибытия
     */
    public SearchParams(RailwayStation startPoint, RailwayStation endPoint, String incomingTimeFrom, String outcomingTimeFrom , String incomingTimeTo, String outcomingTimeTo) throws Exception {
        if(startPoint == null){
            throw new Exception("Start point is required");
        }
        if(endPoint == null){
            throw new Exception("End point is required");
        }
        if(startPoint.equals(endPoint)){
            throw new Exception("The start point can't be equal to the end point");
        }

        if(incomingTimeTo == null){
            throw new Exception("incoming time can't be null");
        }

        if(outcomingTimeTo == null){
            throw new Exception("outcoming time can't be null");
        }


        if(incomingTimeFrom == null){
            throw new Exception("incoming time can't be null");
        }

        if(outcomingTimeFrom == null){
            throw new Exception("outcoming time can't be null");
        }

        this.incomingTimeTo = new Time(incomingTimeTo);
        this.outcomingTimeTo = new Time(outcomingTimeTo);
        this.incomingTimeFrom = new Time(incomingTimeFrom);
        this.outcomingTimeFrom = new Time(outcomingTimeFrom);
        this.startPoint = startPoint;
        this.endPoint = endPoint;
    }

    /**
     * @return {@link #endPoint}
     */
    public RailwayStation getEndPoint() {
        return endPoint;
    }

    /**
     * Устанавливает {@link #endPoint}
     * @param endPoint конечная точка которую необходимо установить
     */
    public void setEndPoint(RailwayStation endPoint) throws Exception {
        if(endPoint == null){
            throw new Exception("Can't set null as end point ");
        }
        if(endPoint.equals(this.startPoint)){
            throw new Exception("End point can't be the same as start point");
        }
        this.endPoint = endPoint;
    }

    /**
     * @return {@link #startPoint}
     */
    public RailwayStation getStartPoint() {
        return startPoint;
    }

    /**
     * Устанавливает начальную точку маршрута
     * @param startPoint начальная точка, которую необходимо установить
     */
    public void setStartPoint(RailwayStation startPoint) throws Exception {
        if(startPoint == null){
            throw new Exception("Can't set null as start point");
        }
        if(startPoint.equals(this.endPoint)){
            throw new Exception("start point can't be the same as end point");
        }
        this.startPoint = startPoint;
    }

    public Time getIncomingTimeFrom() {
        return incomingTimeFrom;
    }

    public void setIncomingTimeFrom(String incomingTimeFrom) {
        this.incomingTimeFrom.parseToTime(incomingTimeFrom);
    }

    public Time getIncomingTimeTo() {
        return incomingTimeTo;
    }

    public void setIncomingTimeTo(String incomingTimeTo) {
        this.incomingTimeTo.parseToTime(incomingTimeTo);
    }

    public Time getOutcomingTimeFrom() {
        return outcomingTimeFrom;
    }

    public void setOutcomingTimeFrom(String outcomingTimeFrom) {
        this.outcomingTimeFrom.parseToTime(outcomingTimeFrom);
    }

    public Time getOutcomingTimeTo() {
        return outcomingTimeTo;
    }

    public void setOutcomingTimeTo(String outcomingTimeTo) {
        this.outcomingTimeTo.parseToTime(outcomingTimeTo);
    }

    


}
