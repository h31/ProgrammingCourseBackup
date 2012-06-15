package sunsystem;

import LogicPack.Planet;
import LogicPack.TrajCircle;
import LogicPack.TrajStat;
import LogicPack.Trajectory;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
public class PlanetLoader {
    static ArrayDeque<Planet> loadPlanets(String dname){
        ArrayDeque<Planet> planets = new ArrayDeque<>();
        File dir = new File(dname);
        if(dir.isDirectory()){
            for(File pdir: dir.listFiles(new Filter())){
                try{
                    planets.add(loadPlanet(pdir));
                }catch(NoPlanetException ex){}
            }
        }
        return planets;
    }
    static Planet loadPlanet(File pdir) throws NoPlanetException{
        try{
            String name = pdir.getName();
            File fSmallImg = new File(pdir.getAbsolutePath() + "/planetSmall.gif");
            File fBigImg = new File(pdir.getAbsolutePath() + "/planetBig.gif");
            File fDesc = new File(pdir.getAbsolutePath() + "/descr.txt");
            File fPData = new File(pdir.getAbsolutePath() + "/pdata.dat");
            if(!fSmallImg.isFile() || !fBigImg.isFile() || !fDesc.isFile() || !fPData.isFile())
                throw new NoPlanetException();
            Image SmallImg = Toolkit.getDefaultToolkit().createImage(fSmallImg.getAbsolutePath());
            Image BigImg = Toolkit.getDefaultToolkit().createImage(fBigImg.getAbsolutePath());
            StringBuilder description = new StringBuilder();
            BufferedReader dbr = new BufferedReader(new InputStreamReader(new FileInputStream(fDesc), "cp1251"));
            for(; ;){
                String str = dbr.readLine();
                if(str == null)
                    break;
                else
                    description.append(str).append(" ");
            }
            BufferedReader fbr = new BufferedReader(new FileReader(fPData));
            StringTokenizer st = new StringTokenizer(fbr.readLine());
            int prad = Integer.parseInt(st.nextToken());
            int ttype = Integer.parseInt(st.nextToken());
            Trajectory traj;
            switch(ttype){
                case 0:{
                    int trad = Integer.parseInt(st.nextToken());
                    boolean dir = Boolean.parseBoolean(st.nextToken());
                    double sangle = Double.parseDouble(st.nextToken());
                    double cycle = Double.parseDouble(st.nextToken());
                    Point pos = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                    traj = new TrajCircle(trad, dir, sangle, cycle, pos);
                    break;
                }
                case 1:{
                    Point pos = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                    traj = new TrajStat(pos);
                    break;
                }
                default: throw new NoPlanetException();
            }
            return new Planet(name, SmallImg, BigImg, description.toString(), prad, traj);
        }catch(Exception ex){System.out.println(ex.getMessage()); throw new NoPlanetException();}
    }
}

class Filter implements FileFilter{
    @Override
    public boolean accept(File pathname){
        return pathname.isDirectory();
    }
    
}

class NoPlanetException extends Exception{
    
}