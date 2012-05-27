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
public class Room {
    private String Name;
    private ArrayList<Surface> Surfaces;
    private ArrayList<CalculatedMaterial> CeilingOutput;
    private ArrayList<CalculatedMaterial> WallOutput;
    private ArrayList<CalculatedMaterial> FloorOutput;
    
    public Room() {
        Name = "Новое помещение";
        Surfaces = new ArrayList<Surface>();
        CeilingOutput = new ArrayList<CalculatedMaterial>();
        WallOutput = new ArrayList<CalculatedMaterial>();
        FloorOutput = new ArrayList<CalculatedMaterial>();
    }
    
    public Room(String name) {
        this.Name = name;
        Surfaces = new ArrayList<Surface>();
        CeilingOutput = new ArrayList<CalculatedMaterial>();
        WallOutput = new ArrayList<CalculatedMaterial>();
        FloorOutput = new ArrayList<CalculatedMaterial>();
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
     * @return the Surfaces
     */
    public ArrayList<Surface> getSurfaces() {
        return Surfaces;
    }

    /**
     * @param Surfaces the Surfaces to set
     */
    public void setSurfaces(ArrayList<Surface> Surfaces) {
        this.Surfaces = Surfaces;
    }

    /**
     * @return the CeilingOutput
     */
    public ArrayList<CalculatedMaterial> getCeilingOutput() {
        return CeilingOutput;
    }

    /**
     * @param CeilingOutput the CeilingOutput to set
     */
    public void setCeilingOutput(ArrayList<CalculatedMaterial> CeilingOutput) {
        this.CeilingOutput = CeilingOutput;
    }

    /**
     * @return the WallOutput
     */
    public ArrayList<CalculatedMaterial> getWallOutput() {
        return WallOutput;
    }

    /**
     * @param WallOutput the WallOutput to set
     */
    public void setWallOutput(ArrayList<CalculatedMaterial> WallOutput) {
        this.WallOutput = WallOutput;
    }

    /**
     * @return the FloorOutput
     */
    public ArrayList<CalculatedMaterial> getFloorOutput() {
        return FloorOutput;
    }

    /**
     * @param FloorOutput the FloorOutput to set
     */
    public void setFloorOutput(ArrayList<CalculatedMaterial> FloorOutput) {
        this.FloorOutput = FloorOutput;
    }
}
