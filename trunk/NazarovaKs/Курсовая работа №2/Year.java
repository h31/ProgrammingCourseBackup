package demography;

public class Year {
     public Year(int y, int b, int d){
        year=y;
        birth=b;
        death=d;
        naturalIncrease=calcOfNaturalIncrease();
        factorOfVitality=calcOfFactorOfVitality();
        demographicFactor=calcOfDemographicFactor();
    }
    
    private int calcOfNaturalIncrease(){
        return birth-death;
    }
    private double calcOfFactorOfVitality(){
        return birth*100/death;
    }
    private double calcOfDemographicFactor(){
        return (birth-death)*100/(birth+death);
    }
    public int getYear(){
        return year;
    }
    public int getBirth(){
        return birth;
    }    
    public int getDeath(){
        return death;
    }  
    public int getNaturalIncrease(){
        return naturalIncrease;
    }
    public double getFactorOfVitality(){
        return factorOfVitality;
    }
    public double getDemographicFactor(){
        return demographicFactor;
    }
    
    int year;
    int birth;
    int death;
    int naturalIncrease;
    double factorOfVitality;
    double demographicFactor;
}
