package datapackage;

/**
 * Класс описывает запись в БД "зависимости":
 * зависимость = структурная единица "алгоритма"
 * @see datapackage.DependenciesDatabaseHelper
 */
public class Dependence {
    
    //ID в базе
    private long Id;
    //ID алгоритма, которому принадлежит данная зависимость
    private long AlgorithmId;
    //ID материала, от которого зависят
    private long IndependentId;
    //коэффициент "на СТОЛЬКО-ТО независимого материала необходимо..."
    private double IndependentFactor;
    //ID материала, который зависит
    private long DependentId;
    //коэффициент "...необходимо СТОЛЬКО-ТО зависимого материала"
    private double DependentFactor;
    
    public final static long DEPEND_ON_SURFACE_ID = -1;
    public final static long DEPEND_ON_NOTHING_ID = -2;
    
    public Dependence(long Id, long AlgorithmId, long IndependentId, double IndependentFactor, long DependentId, double DependentFactor) {
        this.Id = Id;
        this.AlgorithmId = AlgorithmId;
        this.IndependentId = IndependentId;
        this.IndependentFactor = IndependentFactor;
        this.DependentId = DependentId;
        this.DependentFactor = DependentFactor;
    }
    
    public long getId() {
        return Id;
    }
    
    public long getIndependentId() {
        return IndependentId;
    }
    
    public double getIndependentFactor() {
        return IndependentFactor;
    }
    
    public long getDependentId() {
        return DependentId;
    }
    
    public double getDependentFactor() {
        return DependentFactor;
    }
}
