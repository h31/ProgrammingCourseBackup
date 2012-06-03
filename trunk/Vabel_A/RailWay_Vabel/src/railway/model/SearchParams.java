package railway.model;

import java.util.Calendar;

/**
 *
 * Параметры поиска
 */
public abstract class SearchParams {

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
    private Calendar outcomingTimeFrom;

    /**
     * Время отправления (до)
     */
    private Calendar outcomingTimeTo;
    /**
     * Время прибытия (от)
     */
    private Calendar incomingTimeFrom;


    /**
     * Время прибытия (до)
     */
    private Calendar incomingTimeTo;

    /**
     * Конструктор
     * @param startPoint станция отправления
     * @param endPoint станция прибытия
     */
    public SearchParams(RailwayStation startPoint, RailwayStation endPoint, Calendar incomingTimeFrom, Calendar outcomingTimeFrom , Calendar incomingTimeTo, Calendar outcomingTimeTo) throws Exception {
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

        this.incomingTimeTo = incomingTimeTo;
        this.outcomingTimeTo = outcomingTimeTo;
        this.incomingTimeFrom = incomingTimeFrom;
        this.outcomingTimeFrom = outcomingTimeFrom;
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

    public Calendar getIncomingTimeFrom() {
        return incomingTimeFrom;
    }

    public void setIncomingTimeFrom(Calendar incomingTimeFrom) {
        this.incomingTimeFrom = incomingTimeFrom;
    }

    public Calendar getIncomingTimeTo() {
        return incomingTimeTo;
    }

    public void setIncomingTimeTo(Calendar incomingTimeTo) {
        this.incomingTimeTo = incomingTimeTo;
    }

    public Calendar getOutcomingTimeFrom() {
        return outcomingTimeFrom;
    }

    public void setOutcomingTimeFrom(Calendar outcomingTimeFrom) {
        this.outcomingTimeFrom = outcomingTimeFrom;
    }

    public Calendar getOutcomingTimeTo() {
        return outcomingTimeTo;
    }

    public void setOutcomingTimeTo(Calendar outcomingTimeTo) {
        this.outcomingTimeTo = outcomingTimeTo;
    }

    


}
