
package railway.model;

/**
 *
 * Поезд
 */
public class Train {
    /**
     * Номер поезда
     */
    private int number;
    /**
     * Название поезда
     */
    private String name;

    /**
     * Путь следования
     */
    TrainPath trainPath;

    /**
     * Конструктор по умолчанию
     */
    public Train() {
    }

    /**
     * @return {@link #name}
     */
    public String getName() {
        return name;
    }

    /**
     * Устанавливает {@link #name}
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return {@link #number}
     */
    public int getNumber() {
        return number;
    }

    /**
     * устанавливает {@link #number}
     */
    public void setNumber(int number) {
        this.number = number;
    }

    /**
     * @return {@link #trainPath}
     */
    public TrainPath getTrainPath() {
        return trainPath;
    }

    /**
     * Устанавливает {@link #trainPath}
     */
    public void setTrainPath(TrainPath trainPath) {
        this.trainPath = trainPath;
    }

}
