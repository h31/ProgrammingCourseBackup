

package Interface;

import Graph.*;

/**
 */
public interface CurrentListener 
{
    /**
     * Обработчик выбора текущего города
     */
    public void currentCityChanged(vertice city);
    /**
     * Обработчик выбора текущего пути
     */
    public void currentWayChanged(edge way);
}
