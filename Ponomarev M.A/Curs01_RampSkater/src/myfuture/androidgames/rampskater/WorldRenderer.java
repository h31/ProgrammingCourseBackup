package myfuture.androidgames.rampskater;

import javax.microedition.khronos.opengles.GL10;

import android.util.Log;

import com.badlogic.androidgames.framework.gl.Camera2D;
import com.badlogic.androidgames.framework.gl.SpriteBatcher;
import com.badlogic.androidgames.framework.gl.Vertices;
import com.badlogic.androidgames.framework.impl.GLGraphics;

public class WorldRenderer {
	private static final String TAG = "myLogs";
    static final float FRUSTUM_WIDTH = 40;
    static final float FRUSTUM_HEIGHT = 60;    
    GLGraphics glGraphics;
    World world;
    Camera2D cam;
    SpriteBatcher batcher;    
    
    public WorldRenderer(GLGraphics glGraphics, SpriteBatcher batcher, World world) {
    	Log.d(TAG, "WorldRenderer.WorldRenderer()");
        this.glGraphics = glGraphics;
        this.world = world;
        this.cam = new Camera2D(glGraphics, FRUSTUM_WIDTH, FRUSTUM_HEIGHT);
        this.batcher = batcher;        
    }
    
    public void render() {
        cam.setViewportAndMatrices();
        renderBackground();
        renderObjects();        
    }
    
    public void renderBackground() {
        batcher.beginBatch(Assets.backgroundGameT);
        batcher.drawSprite(cam.position.x, cam.position.y,
                           FRUSTUM_WIDTH, FRUSTUM_HEIGHT, 
                           Assets.backgroundGame);
        batcher.endBatch();
    }
    
    public void renderObjects() {
        GL10 gl = glGraphics.getGL();
        gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
        
        
        
        
        renderBoostButton();
        renderFlipButton();
        renderRotateButton();
        renderSkater(gl);
        gl.glDisable(GL10.GL_BLEND);
    }
    
    public void renderSkater(GL10 gl){
    	Log.d(TAG, "WorldRenderer.renderSkater()");
    	batcher.beginBatch(Assets.skaterT);
    	batcher.drawSprite(world.skater.position.x, world.skater.position.y, (float)4.75, (float)8.75, 
    			world.skater.angle, (float)world.skater.scale, Assets.skater);
    	batcher.endBatch();

    }
    
    public void renderBoostButton(){
    	if(world.buttonList.get(0).state==Button.BUTTON_AVAILABLE){
    		batcher.beginBatch(Assets.btnBoostBlueT);
        	batcher.drawSprite((float)5.93, (float)4.43, (float)11.87, (float)3.625, 
                    Assets.btnBoostBlue);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(0).state==Button.BUTTON_DISABLE){
    		batcher.beginBatch(Assets.btnBoostBlackT);
        	batcher.drawSprite((float)5.93, (float)4.43, (float)11.87, (float)3.625, 
                    Assets.btnBoostBlack);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(0).state==Button.BUTTON_CLAMPED){
    		batcher.beginBatch(Assets.btnBoostRedT);
        	batcher.drawSprite((float)5.93, (float)4.43, (float)11.87, (float)3.625, 
                    Assets.btnBoostRed);
        	batcher.endBatch();
    	}
    }
    public void renderFlipButton(){
    	if(world.buttonList.get(1).state==Button.BUTTON_AVAILABLE){
    		batcher.beginBatch(Assets.btnFlipBlueT);
        	batcher.drawSprite(20, (float)4.62, (float)8.75, 5, 
                    Assets.btnFlipBlue);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(1).state==Button.BUTTON_DISABLE){
    		batcher.beginBatch(Assets.btnFlipBlackT);
        	batcher.drawSprite(20, (float)4.62, (float)8.75, 5, 
                    Assets.btnFlipBlack);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(1).state==Button.BUTTON_CLAMPED){
    		batcher.beginBatch(Assets.btnFlipRedT);
        	batcher.drawSprite(20, (float)4.62, (float)8.75, 5, 
                    Assets.btnRotateRed);
        	batcher.endBatch();
    	}
    }
    public void renderRotateButton(){
    	if(world.buttonList.get(2).state==Button.BUTTON_AVAILABLE){
    		batcher.beginBatch(Assets.btnRotateBlueT);
        	batcher.drawSprite((float)33.12, (float)4.37, (float)11.87, (float)3.5, 
                    Assets.btnRotateBlue);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(2).state==Button.BUTTON_DISABLE){
    		batcher.beginBatch(Assets.btnRotateBlackT);
        	batcher.drawSprite((float)33.12, (float)4.37, (float)11.87, (float)3.5, 
                    Assets.btnRotateBlack);
        	batcher.endBatch();
    	}
    	if(world.buttonList.get(2).state==Button.BUTTON_CLAMPED){
    		batcher.beginBatch(Assets.btnRotateRedT);
        	batcher.drawSprite((float)33.12, (float)4.37, (float)11.87, (float)3.5, 
                    Assets.btnRotateRed);
        	batcher.endBatch();
    	}
    }
}
