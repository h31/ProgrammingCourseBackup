package railway.model;

import java.util.ArrayList;
import java.util.List;


public class TrevelPath {

    private final List<TrainPathItem> path;

    public TrevelPath() {
        path = new ArrayList<TrainPathItem>();
    }

    public void addPathItem(TrainPathItem item){
        path.add(item);
    }

    public List<TrainPathItem> getItems(){
        return path;
    }

}
