package railway.model;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

/**
 *Путь поезда (по сути расписание станций)
 */
public class TrainPath implements List<TrainPathItem> {

    /**
     * Остановки поезда на пути следования
     */
    private List<TrainPathItem> pathItems;
    /**
     * Станция отправления (где формируется состав)
     */
    private TrainPathItem startPoint;
    /**
     * Станция окончания пути
     */
    private TrainPathItem endPoint;

    /**
     * Конструктор
     */
    public TrainPath(TrainPathItem startPoint, TrainPathItem endPoint) throws Exception {
        if (startPoint == null) {
            throw new Exception("Станция отправления должна быть задана");
        }
        if (endPoint == null) {
            throw new Exception("Конечная станция должна быть задана");
        }
        if (endPoint == startPoint) {
            throw new Exception("Начальная и конечная станции совпадают");
        }
        this.startPoint = startPoint;
        this.endPoint = endPoint;
        pathItems = new ArrayList<TrainPathItem>();
    }

    public List<TrainPathItem> getPathItems(){
        return pathItems;
    }

    public Time getOutcomingTimeByStation(RailwayStation station) {
        if (startPoint.getStation().equals(station)) {
            return startPoint.getOutcomingTime();
        }
        for (TrainPathItem item : pathItems) {
            if (item.getStation().equals(station)) {
                return item.getOutcomingTime();
            }
        }
        return null;
    }

    public TrainPathItem getItemByStation(RailwayStation station) {
        if (endPoint.getStation().equals(station)) {
            return endPoint;
        }
        if (startPoint.getStation().equals(station)) {
            return startPoint;
        }
        for (TrainPathItem item : pathItems) {
            if (item.getStation().equals(station)) {
                return item;
            }
        }
        return null;
    }

    public Time getIncomingTimeByStation(RailwayStation station) {
        if (endPoint.getStation().equals(station)) {
            return endPoint.getIncomingTime();
        }
        for (TrainPathItem item : pathItems) {
            if (item.getStation().equals(station)) {
                return item.getIncomingTime();
            }
        }
        return null;
    }

    public void setEndPoint(TrainPathItem endPoint) {
        this.endPoint = endPoint;
    }

    public void setStartPoint(TrainPathItem startPoint) {
        this.startPoint = startPoint;
    }

    public TrainPath() {
        pathItems = new ArrayList<TrainPathItem>();
    }

    public TrainPathItem searchItemByStationName(String name) {
        for (TrainPathItem item : pathItems) {
            if (item.getStation().getStationName().equals(name)) {
                return item;
            }
        }
        if(startPoint.getStation().getStationName().equals(name)){
            return startPoint;
        }
        if(endPoint.getStation().getStationName().equals(name)){
            return endPoint;
        }
        return null;
    }

    public int getStationNumber(String name){
        int count=1;
       for (TrainPathItem item : pathItems) {
            if (item.getStation().getStationName().equals(name)) {
                return count+1;
            }
            count++;
        }
        if(startPoint.getStation().getStationName().equals(name)){
            return 0;
        }
        if(endPoint.getStation().getStationName().equals(name)){
            return pathItems.size()+1;
        }
        return -1;
    }

    /**
     * @return {@link #endPoint}
     */
    public TrainPathItem getEndPoint() {
        return endPoint;
    }

    /**
     * @return {@link #startPoint}
     */
    public TrainPathItem getStartPoint() {
        return startPoint;
    }

    /**
     * @return количество остановок на пути следования (не считая стацию отправления и конечную станцию )
     */
    public int size() {
        return pathItems.size();
    }

    /**
     * @return true если нет остановок, иначе false
     */
    public boolean isEmpty() {
        return pathItems.isEmpty();
    }

    /**
     * @return если содержит станцию, то возвращает true
     */
    public boolean contains(Object o) {
        return pathItems.contains(o);
    }

    /**
     * @return итератор по промежуточным остановкам
     */
    public Iterator<TrainPathItem> iterator() {
        return pathItems.iterator();
    }

    /**
     * Конвертирует в массив объектов
     */
    public Object[] toArray() {
        return pathItems.toArray();
    }

    /**
     * В массив (с использованием generic)
     */
    public <T> T[] toArray(T[] a) {
        return pathItems.toArray(a);
    }

    /**
     * Добавляет промежуточную остановку
     */
    public boolean add(TrainPathItem e) {
        return pathItems.add(e);
    }

    /**
     * Удаляет промежуточную остановку
     */
    public boolean remove(Object o) {
        return pathItems.remove(o);
    }

    /**
     * Если содержит все промежуточные остановки из c
     */
    public boolean containsAll(Collection<?> c) {
        return pathItems.containsAll(c);
    }

    /**
     * Добавляет все остановки из c
     */
    public boolean addAll(Collection<? extends TrainPathItem> c) {
        return pathItems.addAll(c);
    }

    /**
     * Вставляет все промежуточные остановки из на позиции начиная с index
     */
    public boolean addAll(int index, Collection<? extends TrainPathItem> c) {
        return pathItems.addAll(index, c);
    }

    public boolean removeAll(Collection<?> c) {
        return pathItems.removeAll(c);
    }

    /**
     * Очищает промежуточные станции
     */
    public void clear() {
        pathItems.clear();
    }

    /**
     * Возвращает промежуточную станцию на позиции
     * @param index позиция
     */
    public TrainPathItem get(int index) {
        return pathItems.get(index);
    }

    /**
     * Устанавливает промежуточную станцию на позицию
     * @param index позиция
     * @param element станция для остановки
     */
    public TrainPathItem set(int index, TrainPathItem element) {
        return pathItems.set(index, element);
    }

    /**
     *
     * @param index
     * @param element
     */
    public void add(int index, TrainPathItem element) {
        pathItems.add(index, element);
    }

    /**
     * Удаляет промежуточную станцию с позиции
     */
    public TrainPathItem remove(int index) {
        return pathItems.remove(index);
    }

    /**
     * возвращает поцзицию станции o
     */
    public int indexOf(Object o) {
        return pathItems.indexOf(o);
    }

    /**
     * возвращает подсписок промежуточных станций
     */
    public List<TrainPathItem> subList(int fromIndex, int toIndex) {
        return pathItems.subList(fromIndex, toIndex);
    }

    /**
     * @deprecated НЕ ИСПОЛЬЗУЕТСЯ
     */
    public int lastIndexOf(Object o) {
        throw new UnsupportedOperationException("Не поддерживается");
    }

    /**
     * @deprecated НЕ ИСПОЛЬЗУЕТСЯ
     */
    public ListIterator<TrainPathItem> listIterator() {
        throw new UnsupportedOperationException("Не поддерживается");
    }

    /**
     *  @deprecated НЕ ИСПОЛЬЗУЕТСЯ
     */
    public ListIterator<TrainPathItem> listIterator(int index) {
        throw new UnsupportedOperationException("Не поддерживается");
    }

    /**
     * @deprecated  НЕ ИСПОЛЬЗУЕТСЯ
     */
    public boolean retainAll(Collection<?> c) {
        throw new UnsupportedOperationException("Не поддерживается");
    }
}
