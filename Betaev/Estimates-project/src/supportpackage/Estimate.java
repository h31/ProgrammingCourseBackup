/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package supportpackage;

import java.util.ArrayList;

/**
 *
 * @author Sergey
 */
public class Estimate {
    private String Name;
    private ArrayList<Room> Rooms;
    private ArrayList<CalculatedMaterial> TotalOutput;
    
    public Estimate() {
        Name = "Смета";
        Rooms = new ArrayList<Room>();
        TotalOutput = new ArrayList<CalculatedMaterial>();
    }

    /**
     * @return the Name
     */
    public String getName() {
        return Name;
    }

    /**
     * @param Name the Name to set
     */
    public void setName(String Name) {
        this.Name = Name;
    }

    /**
     * @return the Rooms
     */
    public ArrayList<Room> getRooms() {
        return Rooms;
    }

    /**
     * @param Rooms the Rooms to set
     */
    public void setRooms(ArrayList<Room> Rooms) {
        this.Rooms = Rooms;
    }

    /**
     * @return the TotalOutput
     */
    public ArrayList<CalculatedMaterial> getTotalOutput() {
        return TotalOutput;
    }

    /**
     * @param TotalOutput the TotalOutput to set
     */
    public void setTotalOutput(ArrayList<CalculatedMaterial> TotalOutput) {
        this.TotalOutput = TotalOutput;
    }
}
