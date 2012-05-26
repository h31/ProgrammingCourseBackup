package GUI;

/**
 * @author Andrew
 */
public class DefaultMessager implements Messager{
    @Override
    public void print(String str){
        System.out.println(str);
    }
}