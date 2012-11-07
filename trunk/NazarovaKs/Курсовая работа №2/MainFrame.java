package demography;
import java.awt.EventQueue;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

public class MainFrame extends JFrame {
    public MainFrame(String s){
        super(s);
        EventQueue.invokeLater(new Runnable(){
            public void run(){
                JFrame frame=new CreateFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setLocationByPlatform(true);
                frame.setVisible(true);
            }
        });
    }
}

class CreateFrame extends JFrame{
    public CreateFrame(){
        setTitle("Demography");
        setSize(600, 200);
        list=new LinkedList<>();
        try{
            reader=new Reader("Russia.txt");
        }
        catch (FileNotFoundException | EOFException e){
            e.printStackTrace();
        }
        for(int i=0; i<reader.getLength(); i++){
            list.add(new Year((int)reader.getListOfYear().get(i), (int)reader.getListOfBirth().get(i), (int)reader.getListOfDeath().get(i)));
        }
        TableModel model=new TableModel(list);
        JTable table=new JTable(model);
        add(new JScrollPane(table));
    }
    
    private List<Year>list;
    private Reader reader;
}

class TableModel extends AbstractTableModel{
    public TableModel(List l){
        list=new LinkedList<>();
        list=l;
    }
    public int getRowCount(){
        return list.size();
    }
    public int getColumnCount(){
        return 6;
    }
    public Object getValueAt(int row, int column){
        switch(column){
            case 0: return String.format("%d", list.get(row).getYear());
            case 1: return String.format("%d", list.get(row).getBirth());
            case 2: return String.format("%d", list.get(row).getDeath());
            case 3: return String.format("%d", list.get(row).getNaturalIncrease());
            case 4: return String.format("%,.2f", list.get(row).getFactorOfVitality());
            case 5: return String.format("%,.2f", list.get(row).getDemographicFactor());
            default: return String.format("%d", 0);
        }  
    }
    public String getColumnName(int column){
        switch(column){
            case 0: return "Year";
            case 1: return "Birth";
            case 2: return "Death";
            case 3: return "NaturalIncrease";
            case 4: return "Factor Of Vitality";
            case 5: return "Demographic Factor";
            default: return "Error";
        }
    }
    
    private List<Year>list;
}  

