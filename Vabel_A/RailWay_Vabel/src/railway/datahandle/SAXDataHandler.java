/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package railway.datahandle;

import java.util.ArrayList;
import java.util.List;
import org.xml.sax.Attributes;
import org.xml.sax.helpers.DefaultHandler;
import railway.model.RailwayStation;
import railway.model.Train;
import railway.model.TrainPath;
import railway.model.TrainPathItem;

/**
 *
 * @author RemiX
 */
public class SAXDataHandler extends DefaultHandler {

    private List<RailwayStation> railwayStationList = new ArrayList<RailwayStation>();
    private List<RailwayStation> tempStationList = new ArrayList<RailwayStation>();
    private String currentElement;
    private Train currentTrain;
    private TrainPath currentTrainPath;

    public List<RailwayStation> getRailwayStationList() {
        return railwayStationList;
    }

    public void startElement(String uri, String localName, String qName, Attributes attrs) {
        currentElement = qName;
        if ("train".equals(currentElement)) {
            currentTrain = new Train();
            currentTrain.setName(attrs.getValue("name"));
            currentTrain.setNumber(Integer.parseInt(attrs.getValue("number")));
        }
        if ("station".equals(currentElement)) {
            String stationName = attrs.getValue("name");
            String incommingTime = attrs.getValue("incommingTime");
            String outcommingTime = attrs.getValue("outcommingTime");
            TrainPathItem pathItem = new TrainPathItem();
            RailwayStation station = new RailwayStation(stationName);
            pathItem.setStation(station);
            tempStationList.add(station);
            if (incommingTime == "") {
                currentTrainPath = new TrainPath();
                pathItem.setOutcomingTime(outcommingTime);
                currentTrainPath.setStartPoint(pathItem);
                currentTrain.setTrainPath(currentTrainPath);
            } else {
                if (outcommingTime == "") {
                    pathItem.setIncomingTime(incommingTime);
                    currentTrainPath.setEndPoint(pathItem);
                    currentTrain.setTrainPath(currentTrainPath);
                    updateStationList();
                } else {
                    pathItem.setOutcomingTime(outcommingTime);
                    pathItem.setIncomingTime(incommingTime);
                    currentTrainPath.add(pathItem);
                    currentTrain.setTrainPath(currentTrainPath);
                }
            }
        }
    }

    public void updateStationList() {
        if (!railwayStationList.isEmpty()) {
            for (RailwayStation tempStation : tempStationList) {
                boolean isHas = false;
                for (RailwayStation station : railwayStationList) {
                    if (tempStation.getStationName().equals(station.getStationName())) {
                        station.addTrain(currentTrain);
                        isHas = true;
                        break;
                    }
                }
                if (isHas == false) {
                    tempStation.addTrain(currentTrain);
                    railwayStationList.add(tempStation);
                }
            }
        } else {
            for (RailwayStation st : tempStationList) {
                st.addTrain(currentTrain);
                railwayStationList.add(st);
            }
        }
        tempStationList.clear();
    }

    public void endElement(String uri, String localName, String qName) {
    }

    public void characters(char[] ch, int start, int length) {
    }
}
