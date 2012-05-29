package sunsystem;

public interface Screen{
    public void setSfact(double nSfact);
    public void setTfact(double nTfact);
    public void setTstep(int nTstep);
    public double getSfact();
    public double getTfact();
    public int getTstep();
}

class BaseScreen implements Screen{
    static Screen bscreen;
    static Screen getBscreen(){
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