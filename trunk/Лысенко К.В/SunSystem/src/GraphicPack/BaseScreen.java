package GraphicPack;

public class BaseScreen implements Screen{
    static Screen bscreen;
    public static Screen getBscreen(){
        if(bscreen == null)
            bscreen = new BaseScreen();
        return bscreen;
    }
    @Override
    public void setSfact(double nSfact){}
    @Override
    public void setTfact(double nTfact){}
    @Override
    public void setTstep(int nTstep){}
    @Override
    public double getSfact(){ return 1; }
    @Override
    public double getTfact(){ return 1; }
    @Override
    public int getTstep(){ return 20; }
}