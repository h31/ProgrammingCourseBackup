package myfuture.androidgames.rampskater;

import java.util.ArrayList;
import java.util.List;

import android.util.Log;

import com.badlogic.androidgames.framework.math.Vector2;


public class World {
	private static final String TAG = "myLogs";
	// interface
	 public interface WorldListener {
        public void flip();
        public void rotate();
        public void boost();
     }
	
	// variables
	 public static final float WORLD_WIDTH = 40;
	 public static final float WORLD_HEIGHT = 60;
	 public static final int WORLD_STATE_RUNNING = 0;
	 public static final int WORLD_STATE_GAME_OVER = 1;
	 public static final float RAMP_RADIUS = (float) 14.25;
	 public static final float RAMP_CENTER = (float) 26.5;
	 public static final Vector2 gravity = new Vector2(0, -10);
	 public static final int RESISTANCE = 3;
	 
	 public final Skater skater;
	 public final List<Button> buttonList;
	 public final WorldListener listener;
	 
	 public float time;
	 public int score;
	 public int state;
	
	 
	 // methods
	 public World(WorldListener listener) {
		 Log.d(TAG, "WorldListener.WorldListener()");
	        this.skater = new Skater((float)13.25, (float)9.25, 0, 0, 0);
	        this.listener = listener;
	        
	        buttonList = new ArrayList<Button>();
	        buttonList.add(new Button("boost",0));
	        buttonList.add(new Button("flip",0));
	        buttonList.add(new Button("rotate",0));
	        
	        this.time = 60;
	        this.score = 0;
	        this.state = WORLD_STATE_RUNNING;
	    }
	 
	 public void update(float deltaTime) {
		    updateSkater(deltaTime);
		    updateButtons();
		    updateScore();
		    updateTime(deltaTime);
		    
		    checkLand();
		    checkGameOver();
	 }
	 
	 public void updateSkater(float deltaTime){
		 skater.update(deltaTime);
	 }
	 public void updateButtons()
	 {
		 if(skater.pos==Skater.SKATER_POSITION_INRAMP){
			 buttonList.get(0).state = Button.BUTTON_AVAILABLE;
			 buttonList.get(1).state = Button.BUTTON_DISABLE;
			 buttonList.get(2).state = Button.BUTTON_DISABLE;
		 }
		 if(skater.pos==Skater.SKATER_POSITION_LEFTSIDE || 
		    skater.pos==Skater.SKATER_POSITION_RIGHTSIDE){
			 buttonList.get(0).state = Button.BUTTON_DISABLE;
			 buttonList.get(1).state = Button.BUTTON_AVAILABLE;
			 buttonList.get(2).state = Button.BUTTON_AVAILABLE;
		 }
	 }
	 public void updateScore(){
		 if(skater.pointsForTrick!=0){
			 score = score + skater.pointsForTrick;
			 skater.pointsForTrick = 0;
		 }
	 }
	 public void updateTime(float deltaTime){
		 time = time - deltaTime;
	 }
	 
	 public void checkLand(){
		 if(skater.state==Skater.SKATER_STATE_INTRICK && skater.position.y<RAMP_CENTER){
			 skater.state=Skater.SKATER_STATE_FALLED;
		 }
	 }
	 public void checkGameOver(){
		 if(skater.state==Skater.SKATER_STATE_FALLED || time<0){
			 this.state = World.WORLD_STATE_GAME_OVER;
		 }
	 }
	 
	 
	 
	 
	 
}
