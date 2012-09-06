package myfuture.androidgames.rampskater;

import android.util.Log;

import com.badlogic.androidgames.framework.DynamicGameObject;


public class Skater extends DynamicGameObject{
	private static final String TAG = "myLogs";
	// variables
	public static final float SKATER_WIDTH = (float) 4.75;
    public static final float SKATER_HEIGHT = (float) 8.75;
    public static final int SKATER_POSITION_INRAMP = 0;
    public static final int SKATER_POSITION_LEFTSIDE = 1;
    public static final int SKATER_POSITION_RIGHTSIDE = 2;
    public static final int SKATER_STATE_JUSTSKATE = 0;
    public static final int SKATER_STATE_BOOST = 1;
    public static final int SKATER_STATE_INTRICK = 2;
    public static final int SKATER_STATE_FALLED = 3;
    public static final int SKATER_VELOCITY = 35;
    public static final int SKATER_MAX_VELOCITY = 35;
    public static final float SKATER_BOOSTER = (float) 2.25;
    
    public int pos;
    public int state;
    public float angle;
    public float scale;
    public int pointsForTrick;
    boolean isClockRotation;
    
    // methods
    public Skater(float x, float y, int pos, int state, float angle){
    	super(x, y, SKATER_WIDTH, SKATER_HEIGHT);
    	Log.d(TAG, "Skater.Skater()");
        this.pos = pos;
        this.state = state;
        this.angle = angle;
        this.scale = 1;
        this.pointsForTrick = 0;
        this.isClockRotation = true;
        velocity.x = Skater.SKATER_VELOCITY;
    }
    
    public void update(float deltaTime){
    	//Log.d(TAG, "Skater.update()");
        set_angle(deltaTime);
        set_velocity(deltaTime);
        set_position(deltaTime);  
    }
    
    public void set_angle(float deltaTime){
		   if(pos == SKATER_POSITION_INRAMP) { // if skater IN RAMP
			   angle = angle + (float) (180*velocity.x * deltaTime / Math.PI / World.RAMP_RADIUS);
		   }
		   if(pos == SKATER_POSITION_LEFTSIDE) { // if skater in the AIR from LEFT SIDE of ramp
			   if (state == SKATER_STATE_JUSTSKATE) angle = -90; // if not in trick
		   }
		   if(pos == SKATER_POSITION_RIGHTSIDE) { // if skater in the AIR from RIGHT SIDE of ramp
			   if (state == SKATER_STATE_JUSTSKATE) angle = 90;  // if not in trick
		   }
    }
    
    public void set_velocity(float deltaTime){
    	
    	if(pos == SKATER_POSITION_LEFTSIDE) {   // if skater in the AIR from LEFT SIDE of ramp
 		   if(velocity.x < 0) velocity.add(-World.gravity.y * deltaTime + World.RESISTANCE*deltaTime, 0); // move UP
 		   if(velocity.x > 0) velocity.add(-World.gravity.y * deltaTime, 0);                              // move DOWN
 	   }
 	   
 	   if(pos == SKATER_POSITION_RIGHTSIDE) {  // if skater in the AIR from RIGHT SIDE of ramp
 		   if(velocity.x > 0) velocity.add(World.gravity.y * deltaTime - World.RESISTANCE*deltaTime, 0);  // move UP
 	       if(velocity.x < 0) velocity.add(World.gravity.y * deltaTime, 0);                               // move DOWN
 	   }
 	   
 	   
 	   
    	if(pos == SKATER_POSITION_INRAMP) { // if skater IN RAMP
            if(angle < 90 && angle > 0) { // right Side inside ramp
	            if(velocity.x < 0) { // move DOWN
	            	velocity.add(World.gravity.y * deltaTime, 0);
	            	if(state == SKATER_STATE_BOOST){ 
	            		velocity.add(-SKATER_BOOSTER, 0); // boost when  pressed
	            		state = Skater.SKATER_STATE_JUSTSKATE;
	            	}
	            }
	            if(velocity.x > 0) { // move UP
	            	velocity.add(World.gravity.y * deltaTime - World.RESISTANCE*deltaTime, 0);
	            	if(state == SKATER_STATE_BOOST){
	            		velocity.add(-SKATER_BOOSTER, 0); // slow down when  pressed
	            		state = Skater.SKATER_STATE_JUSTSKATE;
	            	}
	            }
	            }
	            
	            if(angle < 0 && angle > -90) { // left Side inside ramp
	            if(velocity.x < 0) { // move UP
	            	velocity.add(-World.gravity.y * deltaTime + World.RESISTANCE*deltaTime, 0);
	            	if(state == SKATER_STATE_BOOST){
	            		velocity.add(SKATER_BOOSTER, 0); // slow down when  pressed
	            		state = Skater.SKATER_STATE_JUSTSKATE;
	            	}
	            }
	            if(velocity.x > 0) { // move DOWN
	            	velocity.add(-World.gravity.y * deltaTime, 0);
	            	if(state == SKATER_STATE_BOOST){
	            		velocity.add(SKATER_BOOSTER, 0); // boost when  pressed
	            		state = Skater.SKATER_STATE_JUSTSKATE;
	            	}
	            }
	            }
	            
	            if (velocity.x > SKATER_MAX_VELOCITY ) velocity.x = SKATER_MAX_VELOCITY; // limit max speed
	            if (velocity.x < -SKATER_MAX_VELOCITY ) velocity.x = -SKATER_MAX_VELOCITY; // limit max speed
	   }
    }
    
    public void set_position(float deltaTime){
		   if(pos == SKATER_POSITION_INRAMP) { // if skater IN RAMP
	           position.set(World.WORLD_WIDTH/2 + (float) (World.RAMP_RADIUS*Math.sin(Math.PI/180*angle)), // coordX
	        		        World.RAMP_CENTER  - (float) (World.RAMP_RADIUS*Math.cos(Math.PI/180*angle))); // coordY
		   }
		   
		   if(pos == SKATER_POSITION_LEFTSIDE) { // if skater in the AIR from LEFT SIDE of ramp
			   position.add(0, -velocity.x * deltaTime);
		   }
		   if(pos == SKATER_POSITION_RIGHTSIDE) { // if skater in the AIR from RIGHT SIDE of ramp
			   position.add(0, velocity.x * deltaTime);
		   }
		   
		   // check current pos
		   if(position.y < World.RAMP_CENTER) pos = Skater.SKATER_POSITION_INRAMP;
		   else {
			   if(position.x > 20) pos = Skater.SKATER_POSITION_RIGHTSIDE;
			   if(position.x < 20) pos = Skater.SKATER_POSITION_LEFTSIDE; 
		   }
			   
    }
    
    public void do_trick(float deltaTime, int name){
    	
    	 if(pos!=Skater.SKATER_POSITION_INRAMP) { // if skater not in ramp
			   state = Skater.SKATER_STATE_INTRICK;
			   
			  if (name==Trick.FLIP){ // if skater do FLIP
				  
				  if(pos== Skater.SKATER_POSITION_RIGHTSIDE) { // do trick on RIGHT SIDE
						 angle = angle + Trick.FLIP_VELOCITY*deltaTime*360;
						  if (angle > 450) { 
							state = Skater.SKATER_STATE_JUSTSKATE;
							pointsForTrick = pointsForTrick + Trick.FLIP_SCORE;
							
						  }
				  }
				  if(pos== Skater.SKATER_POSITION_LEFTSIDE) {  // do trick on LEFT SIDE 
					  angle = angle - Trick.FLIP_VELOCITY*deltaTime*360;
					  if (angle <  -450) {
						  state = Skater.SKATER_STATE_JUSTSKATE;
						    pointsForTrick = pointsForTrick + Trick.FLIP_SCORE;
						    
					  }
				  }
			  } 
			  
			  
			  if (name==Trick.ROTATION) { // if skater do ROTATION
				  
				  
				  if(scale == 1) isClockRotation  = true;
				  
				  if(scale == -1) isClockRotation  = false;
				  
				  if(isClockRotation) {
					  scale = scale - Trick.ROTATION_VELOCITY*deltaTime;
					  if ( scale < -1) {
						  scale = -1;
						  state = Skater.SKATER_STATE_JUSTSKATE;
						  pointsForTrick = pointsForTrick + Trick.ROTATION_SCORE;
						 
					  }
				  }
				  
				  if(!isClockRotation) {
					  scale = scale + Trick.ROTATION_VELOCITY*deltaTime;
					  if ( scale > 1) {
						  scale = 1;
						  state = Skater.SKATER_STATE_JUSTSKATE;
						  pointsForTrick = pointsForTrick + Trick.ROTATION_SCORE;
					  }
				      }
			  }
			  
		   }
    }
}
