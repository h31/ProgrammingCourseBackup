package myfuture.androidgames.rampskater;

import java.util.List;

import javax.microedition.khronos.opengles.GL10;

import myfuture.androidgames.rampskater.World.WorldListener;

import android.util.Log;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Input.TouchEvent;
import com.badlogic.androidgames.framework.gl.Camera2D;
import com.badlogic.androidgames.framework.gl.FPSCounter;
import com.badlogic.androidgames.framework.gl.SpriteBatcher;
import com.badlogic.androidgames.framework.impl.GLScreen;
import com.badlogic.androidgames.framework.math.OverlapTester;
import com.badlogic.androidgames.framework.math.Rectangle;
import com.badlogic.androidgames.framework.math.Vector2;


public class GameScreen extends GLScreen{
	private static final String TAG = "myLogs";
	static final int GAME_READY = 0;    
    static final int GAME_RUNNING = 1;
    static final int GAME_PAUSED = 2;
    static final int GAME_FALLED = 3;
    static final int GAME_RUNTIME = 4;
  
    int state;
    Camera2D guiCam;
    Vector2 touchPoint;
    Vector2 touchDownPoint;
    SpriteBatcher batcher;    
    World world;
    WorldListener worldListener;
    WorldRenderer renderer;    
    Rectangle pauseBounds;
    Rectangle resumeBounds;
    Rectangle quitBounds;
    Rectangle btnBoostBounds;
    Rectangle btnFlipBounds;
    Rectangle btnRotateBounds;
    int lastScore;
    String scoreString;    
    FPSCounter fpsCounter;
    boolean btnFlipClicked;
    boolean btnRotateClicked;
    boolean btnBoostClamped;
    
    public GameScreen(Game game) {
        super(game);
        Log.d(TAG, "GameScreen.GameScreen()");
        state = GAME_READY;
        guiCam = new Camera2D(glGraphics, 320, 480);
        touchPoint = new Vector2();
        batcher = new SpriteBatcher(glGraphics, 1000);
        btnFlipClicked = false;
        btnRotateClicked = false;
        btnBoostClamped = false;
        worldListener = new WorldListener() {
            @Override
            public void boost() {            
                Assets.playSound(Assets.boostSound);
            }
            @Override
            public void flip() {
                Assets.playSound(Assets.flipSound);
            }
            @Override
            public void rotate() {
                Assets.playSound(Assets.rotateSound);
            }                     
        };
        world = new World(worldListener);
        
        renderer = new WorldRenderer(glGraphics, batcher, world);
        Log.d(TAG, "GameScreen.WorldRenderer()");
        pauseBounds = new Rectangle(320- 64, 480- 64, 64, 64);
        resumeBounds = new Rectangle(38, 285, 238, 25);
        quitBounds = new Rectangle(38, 247, 238, 25);
        btnBoostBounds = new Rectangle(5, 21, 95, 29);
        btnFlipBounds = new Rectangle(125, 17, 70, 40);
        btnRotateBounds = new Rectangle(219, 21, 95, 28);
        lastScore = 0;
        scoreString = "score: 0";
        fpsCounter = new FPSCounter();
    }

    
	@Override
	public void update(float deltaTime) {
		//Log.d(TAG, "GameScreen.update()");
	    if(deltaTime > 0.1f)
	        deltaTime = 0.1f;
	    
	    switch(state) {
	    case GAME_READY:
	        updateReady();
	        break;
	    case GAME_RUNNING:
	        updateRunning(deltaTime);
	        break;
	    case GAME_PAUSED:
	        updatePaused();
	        break;
	    case GAME_FALLED:
	        updateFalled();
	        break;
	    case GAME_RUNTIME:
	        updateRuntime();
	        break;
	    }
	    
	}
	
	private void updateReady() {
	    if(game.getInput().getTouchEvents().size() > 0) {
	        state = GAME_RUNNING;
	    }
	}
	
	private void updateRunning(float deltaTime) {
		
		Log.d(TAG, "GameScreen.updateRunning()");
	    List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
	    int len = touchEvents.size();
	    for(int i = 0; i < len; i++) {
	        TouchEvent event = touchEvents.get(i);    
	        if(event.type != TouchEvent.TOUCH_UP)
	            continue;
	        
	        touchPoint.set(event.x, event.y);
	        guiCam.touchToWorld(touchPoint);
	        
	        if(OverlapTester.pointInRectangle(btnBoostBounds, touchPoint)) {
	        	if(world.buttonList.get(0).state==Button.BUTTON_AVAILABLE){
	        		    Assets.playSound(Assets.boostSound);
		            	world.skater.state = Skater.SKATER_STATE_BOOST;
		            	world.buttonList.get(0).state = Button.BUTTON_CLAMPED;
		            }
	        	return;
	        	}
	        
	        if(OverlapTester.pointInRectangle(pauseBounds, touchPoint)) {
	            Assets.playSound(Assets.clickSound);
	            state = GAME_PAUSED;
	            return;
	        } 
	        
	        
	        if(OverlapTester.pointInRectangle(btnFlipBounds, touchPoint)) {
	        	if(world.buttonList.get(1).state==Button.BUTTON_AVAILABLE){
	        		Assets.playSound(Assets.flipSound);
	        		btnFlipClicked = true;
	        	}
	            return;
	        }
	        
	        if(OverlapTester.pointInRectangle(btnRotateBounds, touchPoint)) {
	        	if(world.buttonList.get(2).state==Button.BUTTON_AVAILABLE){
	        		Assets.playSound(Assets.rotateSound);
	        		btnRotateClicked = true;
	        	}
	            return;
	        }
	        
	    }
	    

	    world.update(deltaTime);
	    if(btnFlipClicked){
	    	world.skater.do_trick(deltaTime, Trick.FLIP);
            world.buttonList.get(1).state = Button.BUTTON_CLAMPED;
            world.buttonList.get(2).state = Button.BUTTON_DISABLE;
            if(world.skater.pointsForTrick!=0) btnFlipClicked = false;
	    }
	    if(btnRotateClicked){
	    	 world.skater.do_trick(deltaTime, Trick.ROTATION);
   	         world.buttonList.get(2).state = Button.BUTTON_CLAMPED;
   	         world.buttonList.get(1).state = Button.BUTTON_DISABLE;
   	         if(world.skater.pointsForTrick!=0) btnRotateClicked = false;
	    }
	    
	    if(world.score != lastScore) {
	        lastScore = world.score;
	        scoreString = "" + lastScore;
	    }

	    if(world.state == World.WORLD_STATE_GAME_OVER) {
	        if(world.skater.state==Skater.SKATER_STATE_FALLED) state = GAME_FALLED;
	        if(world.time < 0) state = GAME_RUNTIME;
	        if(lastScore >= Settings.highscores[4]) 
	            scoreString = "new highscore: " + lastScore;
	        else
	            scoreString = "score: " + lastScore;
	        Settings.addScore(lastScore);
	        Settings.save(game.getFileIO());
	    }
	     
	    
	    
	    
	}
	
	private void updatePaused() {
	    List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
	    int len = touchEvents.size();
	    for(int i = 0; i < len; i++) {
	        TouchEvent event = touchEvents.get(i);
	        if(event.type != TouchEvent.TOUCH_UP)
	            continue;
	        
	        touchPoint.set(event.x, event.y);
	        guiCam.touchToWorld(touchPoint);
	        
	        if(OverlapTester.pointInRectangle(resumeBounds, touchPoint)) {
	            Assets.playSound(Assets.clickSound);
	            state = GAME_RUNNING;
	            return;
	        }
	        
	        if(OverlapTester.pointInRectangle(quitBounds, touchPoint)) {
	            Assets.playSound(Assets.clickSound);
	            game.setScreen(new MainMenuScreen(game));
	            return;
	        
	        }
	    }
	}
	
	private void updateFalled() {
	    List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
	    int len = touchEvents.size();
	    for(int i = 0; i < len; i++) {                   
	        TouchEvent event = touchEvents.get(i);
	        if(event.type != TouchEvent.TOUCH_UP)
	            continue;
	        game.setScreen(new MainMenuScreen(game));
	    }
	}

	private void updateRuntime() {
	    List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
	    int len = touchEvents.size();
	    for(int i = 0; i < len; i++) {                   
	        TouchEvent event = touchEvents.get(i);
	        if(event.type != TouchEvent.TOUCH_UP)
	            continue;
	        game.setScreen(new MainMenuScreen(game));
	    }
	}
	
	
	@Override
	public void present(float deltaTime) {
		//Log.d(TAG, "GameScreen.present()");
	    GL10 gl = glGraphics.getGL();
	    gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
	    gl.glEnable(GL10.GL_TEXTURE_2D);
	    
	    renderer.render();
	    
	    guiCam.setViewportAndMatrices();
	    gl.glEnable(GL10.GL_BLEND);
	    gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
	   
	    switch(state) {
	    case GAME_READY:
	        presentReady();
	        break;
	    case GAME_RUNNING:
	        presentRunning();
	        break;
	    case GAME_PAUSED:
	        presentPaused();
	        break;
	    case GAME_FALLED:
	        presentFalled();
	        break;
	    case GAME_RUNTIME:
	        presentRuntime();
	        break;
	    }
	   // batcher.endBatch();
	    gl.glDisable(GL10.GL_BLEND);
	    fpsCounter.logFrame();
	}
	
	private void presentReady() {
		batcher.beginBatch(Assets.readyT);
	    batcher.drawSprite(167, 278, 253, 54, Assets.ready);
	    batcher.endBatch();
	}
	
	private void presentRunning() {
		Log.d(TAG, "GameScreen.updateRunning()");
		batcher.beginBatch(Assets.statsT);
	    batcher.drawSprite(130, 277, 120, 68, Assets.stats);
	    batcher.endBatch();
	    
	    batcher.beginBatch(Assets.pauseBtnT);
	    batcher.drawSprite(290, 440, 50, 50, Assets.pauseBtn);
	    batcher.endBatch();
	    draw_score(280,300);
		draw_time(280,262);
		
	}
	
	private void presentPaused() {     
		batcher.beginBatch(Assets.pauseT);
	    batcher.drawSprite(157, 286, 238, 105, Assets.pause);
	    batcher.endBatch();
	}
	
	private void presentFalled() {
		batcher.beginBatch(Assets.falledT);
	    batcher.drawSprite(142, 285, 160, 96, Assets.falled);     
	    batcher.endBatch();
	    
	    batcher.beginBatch(Assets.statsT);
	    batcher.drawSprite(120, 400, 120, 40, Assets.score);
	    batcher.endBatch();
	    draw_score(250,400);
		
	}

	private void presentRuntime() {
		batcher.beginBatch(Assets.timeIsUpT);
	    batcher.drawSprite(145, 285, 160, 96, Assets.timeIsUp); 
	    batcher.endBatch();
	    
	    batcher.beginBatch(Assets.statsT);
	    batcher.drawSprite(120, 400, 120, 40, Assets.score);
	    batcher.endBatch();
	    draw_score(250,400);
	    
	}
	
	
	public void draw_score(int x,int y){
    	String currChar;
    	String score;
    	score = "" + world.score;
      
        for(int i=score.length()-1; i>-1;i--){
     		currChar = String.valueOf(score.charAt(i));
     		draw_number(Integer.parseInt(currChar), x-30*(score.length()-i), y);  
     	}  
}
	public void draw_time(int x, int y){
	 String currChar;
    	String time;
    	time = "" + (int)world.time;
    	
        for(int i=time.length()-1; i>-1;i--){
     		currChar = String.valueOf(time.charAt(i));
     		draw_number(Integer.parseInt(currChar), x-30*(time.length()-i), y);  
     	}  
} 
	public void draw_number(int number, int coordX, int coordY) {
        batcher.beginBatch(Assets.numbersT);
        if(number==1) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num1);
        if(number==2) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num2);
        if(number==3) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num3);
        if(number==4) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num4);
        if(number==5) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num5);
        if(number==6) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num6);
        if(number==7) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num7);
        if(number==8) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num8);
        if(number==9) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num9);
        if(number==0) batcher.drawSprite(coordX, coordY, 30, 19, Assets.num0);
        batcher.endBatch();
}

    @Override
    public void pause() {
        if(state == GAME_RUNNING)
            state = GAME_PAUSED;
    }

    @Override
    public void resume() {        
    }

    @Override
    public void dispose() {       
    }
}