package GUI;

/**
 * @author Andrew
 */
public class SimpleMessager implements Messager{
    @Override
    public void print(String str){
        System.out.println(str);
    }
}