
package railway.search;

import java.util.List;
import railway.model.TrevelPath;

/**
 * Абстрактный класс для алгоритма поиска <br>
 */

public abstract class AbstractPathSearcher {

    protected SearchParams param;

    public AbstractPathSearcher(SearchParams param) throws Exception {
        if(param == null){
            throw new Exception("Param required!!!");
        }
        this.param = param;
    }


    public abstract List<TrevelPath> findTrevelPath();

}
