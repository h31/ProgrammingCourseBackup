package myfuture.androidgames.rampskater;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.util.Log;

import com.badlogic.androidgames.framework.Screen;
import com.badlogic.androidgames.framework.impl.GLGame;

public class RampSkater extends GLGame {
	
	// variables
	private static final String TAG = "myLogs";
	
    boolean firstTimeCreate = true;
    
    
    // methods
    @Override
    public Screen getStartScreen() {
    	Log.d(TAG, "RampSkater.getStartScreen()");
        return new MainMenuScreen(this);
        
    }
    
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) { 
    	Log.d(TAG, "RampSkater.onSurfaceCreated()");
        super.onSurfaceCreated(gl, config);
        if(firstTimeCreate) {
            Settings.load(getFileIO());
            Assets.load(this);
            firstTimeCreate = false;            
        } else {
            Assets.reload();
        }
    }     
    
    @Override
    public void onPause() {
    	Log.d(TAG, "RampSkater.onPause()");
        super.onPause();
        if(Settings.soundEnabled)
            Assets.music.pause();
    }
}
