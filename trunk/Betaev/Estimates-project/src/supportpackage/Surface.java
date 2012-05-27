/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package supportpackage;

import java.util.ArrayList;

public class Surface {
    
    public final static int TYPE_CEILING = 0;
    public final static int TYPE_WALL = 1;
    public final static int TYPE_FLOOR = 2;
    public static String[] TYPES = {"Потолок","Стена","Пол"};
    
    public final static int METHOD_SQUARE = 0;
    public final static int METHOD_RUNNING = 1;
    public static String[] METHODS = {"Квадратный метр","Погонный метр"};
    
    private String Name;
    private int Type;
    private double Measure;
    private int MeasuringMethod;
    private long AlgorithmId;
    //private ArrayList<CalculatedMaterial> Output;
    
    public Surface(long AlgId) {
        Name = "Новая поверхность";
        Type = TYPE_CEILING;
        Measure = 10;
        MeasuringMethod = METHOD_SQUARE;
        AlgorithmId = AlgId;
        //Output = new ArrayList<CalculatedMaterial>();
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
     * @return the Type
     */
    public int getType() {
        return Type;
    }

    /**
     * @param Type the Type to set
     */
    public void setType(int Type) {
        this.Type = Type;
    }

    /**
     * @return the Measure
     */
    public double getMeasure() {
        return Measure;
    }

    /**
     * @param Measure the Measure to set
     */
    public void setMeasure(double Measure) {
        this.Measure = Measure;
    }

    /**
     * @return the MeasuringMethod
     */
    public int getMeasuringMethod() {
        return MeasuringMethod;
    }

    /**
     * @param MeasuringMethod the MeasuringMethod to set
     */
    public void setMeasuringMethod(int MeasuringMethod) {
        this.MeasuringMethod = MeasuringMethod;
    }

    /**
     * @return the AlgorithmId
     */
    public long getAlgorithmId() {
        return AlgorithmId;
    }

    /**
     * @param AlgorithmId the AlgorithmId to set
     */
    public void setAlgorithmId(long AlgorithmId) {
        this.AlgorithmId = AlgorithmId;
    }
/*
    /**
     * @return the Output
     */
    /*public ArrayList<CalculatedMaterial> getOutput() {
        return Output;
    }*/

    /**
     * @param Output the Output to set
     *//*
    public void setOutput(ArrayList<CalculatedMaterial> Output) {
        this.Output = Output;
    }
    */
}
