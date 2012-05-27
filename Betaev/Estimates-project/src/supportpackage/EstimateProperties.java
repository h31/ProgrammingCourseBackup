/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package supportpackage;

/**
 *
 * @author Sergey
 */
public class EstimateProperties {
    private String AbsolutePath;
    private int EmptyLines;
    
    public EstimateProperties(String AbsolutePath, int EmptyLines) {
        this.AbsolutePath = AbsolutePath;
        this.EmptyLines = EmptyLines;
    }

    /**
     * @return the AbsolutePath
     */
    public String getAbsolutePath() {
        return AbsolutePath;
    }

    /**
     * @param AbsolutePath the AbsolutePath to set
     */
    public void setAbsolutePath(String AbsolutePath) {
        this.AbsolutePath = AbsolutePath;
    }

    /**
     * @return the EmptyLines
     */
    public int getEmptyLines() {
        return EmptyLines;
    }

    /**
     * @param EmptyLines the EmptyLines to set
     */
    public void setEmptyLines(int EmptyLines) {
        this.EmptyLines = EmptyLines;
    }
}
