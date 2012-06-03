package railway.model;

/**
 * ЖД между двумя станциями
 */
public class Railway {
    /**
     * Станция 1
     */
    private RailwayStation station1;
    /**
     * Станция 2
     */
    private RailwayStation station2;
    /**
     * Расстояние
     */
    private double lenght;

    /**
     *Конструктор
     */
    public Railway(RailwayStation station1, RailwayStation station2, double lenght) {
        this.station1 = station1;
        this.station2 = station2;
        this.lenght = lenght;
    }

    /**
     * Выставляет station в null
     */
    public void cleanStation(RailwayStation station) throws Exception{
        if(station1 == station){
            station1 = null;
        } else if(station2 == station){
            station2 = null;
        } else {
            throw new Exception("Station not on this way");
        }
    }
    

    /**
     * @return {@link #lenght}
     */
    public double getLenght() {
        return lenght;
    }

    /**
     * sets {@link #lenght}
     */
    public void setLenght(double lenght) {
        this.lenght = lenght;
    }

    /**
     * @return {@link #station1}
     */
    public RailwayStation getStation1() {
        return station1;
    }

    /**
     * {@link #station1}
     */
    public void setStation1(RailwayStation station1) {
        this.station1 = station1;
    }

    /**
     * @return {@link #station2}
     */
    public RailwayStation getStation2() {
        return station2;
    }

    /**
     * see {@link #station2}
     */
    public void setStation2(RailwayStation station2) {
        this.station2 = station2;
    }

}
