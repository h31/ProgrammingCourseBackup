package demography;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;

public class Demography {
    public static void main(String[] args) throws FileNotFoundException, EOFException{
        MainFrame mf=new MainFrame("Demography"); 
        List<Year> statistic=new LinkedList();
        Reader reader=new Reader("China.txt");
        for(int i=0; i<reader.getLength(); i++){
            statistic.add(new Year((int)reader.getListOfYear().get(i), (int)reader.getListOfBirth().get(i), (int)reader.getListOfDeath().get(i)));
        }
        for(int j=0; j<statistic.size(); j++)
           System.out.println(statistic.get(j).getNaturalIncrease()+" "+statistic.get(j).getFactorOfVitality()+" "+statistic.get(j).getDemographicFactor());
    }
}
