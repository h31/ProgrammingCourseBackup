
package railway.model;

/**
 * Абстрактный класс для алгоритма поиска <br>
 */

public abstract class AbstractAlgo {

    protected SearchParams param;

    public AbstractAlgo(SearchParams param) throws Exception {
        if(param == null){
            throw new Exception("Param required!!!");
        }
        this.param = param;
    }


    public abstract TrevelPath findTrevelPath();

}
