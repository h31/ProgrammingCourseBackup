
package Interface;

import Graph.edge.*;


public interface InfoListener {

    /**
     * Обработчик изменения имени города
     */
    public void cityNameChanged(String name);
    /**
     * Обработчик изменения типа пути
     */
    public void wayKindChanged(EdgeKind kind);
    /**
     * Обработчик изменения стоимости пути
     */
    public void wayCostChanged(int cost);
    /**
     * Обработчик изменения времени в пути
     */
    public void wayTimeChanged(int time);
}
