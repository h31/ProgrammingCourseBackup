package railway.model;

import java.util.ArrayList;
import java.util.List;


public class TrevelPath {

private String trainName;
private TrainPathItem outcomingItem;
private TrainPathItem incomingItem;

    public TrevelPath(){
        
    }
    public TrainPathItem getIncomingItem() {
        return incomingItem;
    }

    public void setIncomingItem(TrainPathItem incomingItem) {
        this.incomingItem = incomingItem;
    }

    public TrainPathItem getOutcomingItem() {
        return outcomingItem;
    }

    public void setOutcomingItem(TrainPathItem outcomingItem) {
        this.outcomingItem = outcomingItem;
    }

    public String getTrainName() {
        return trainName;
    }

    public void setTrainName(String trainName) {
        this.trainName = trainName;
    }

    public TrevelPath(String trainName, TrainPathItem outcomingItem, TrainPathItem incomingItem) {
        this.trainName = trainName;
        this.outcomingItem = outcomingItem;
        this.incomingItem = incomingItem;
    }
    

}
