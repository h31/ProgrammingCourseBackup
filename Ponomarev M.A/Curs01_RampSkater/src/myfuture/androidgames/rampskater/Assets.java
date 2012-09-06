package myfuture.androidgames.rampskater;

import android.util.Log;

import com.badlogic.androidgames.framework.Music;
import com.badlogic.androidgames.framework.Sound;
import com.badlogic.androidgames.framework.gl.Texture;
import com.badlogic.androidgames.framework.gl.TextureRegion;
import com.badlogic.androidgames.framework.impl.GLGame;

public class Assets {

	// variables
	private static final String TAG = "myLogs";
	
	// TEXTURES
	 // backgrounds
	 public static Texture backgroundT, backgroundGameT;
     // buttons
	 public static Texture btnBoostBlackT, btnBoostBlueT, btnBoostRedT;
	 public static Texture btnFlipBlackT, btnFlipBlueT, btnFlipRedT;
	 public static Texture btnRotateBlackT, btnRotateBlueT, btnRotateRedT;
	 public static Texture pauseBtnT;
	 // words
	 public static Texture menuT;
	 public static Texture pauseT;
	 public static Texture readyT;
	 public static Texture falledT;
	 public static Texture timeIsUpT;
	 public static Texture statsT;
	 // numbers
	 public static Texture numbersT;
	 // sprite
	 public static Texture skaterT;
	 // soundOnOff
	 public static Texture soundOnT, soundOffT;
	 // logo
	 public static Texture logoT;
	 
	 
	// TEXTURE REGIONS
	 // backgrounds
	 public static TextureRegion background, backgroundGame;
	 // buttons
	 public static TextureRegion btnBoostBlack, btnBoostBlue, btnBoostRed;
	 public static TextureRegion btnFlipBlack, btnFlipBlue, btnFlipRed;
	 public static TextureRegion btnRotateBlack, btnRotateBlue, btnRotateRed;
	 public static TextureRegion pauseBtn;
	 // words
	 public static TextureRegion menu;
	 public static TextureRegion pause;
	 public static TextureRegion ready;
     public static TextureRegion falled;
	 public static TextureRegion timeIsUp;
	 public static TextureRegion stats;
	 public static TextureRegion score;
	 // numbers
	 public static TextureRegion num1, num2, num3, num4, num5, num6, num7, num8, num9, num0;
	 // sprite
	 public static TextureRegion skater;
	 // soundOnOff
	 public static TextureRegion soundOn, soundOff;
	 // logo
	 public static TextureRegion logo;
	 
	 
	 
	 
	 
	 // music 
	 public static Music music;
	 
	 // sounds
	 public static Sound boostSound;
	 public static Sound flipSound;
	 public static Sound rotateSound;
	 public static Sound clickSound;
	 
	 
	 // methods
	 public static void load(GLGame game) {
		 Log.d(TAG, "Assets.load()");
		 
		 
		    backgroundT = new Texture(game, "background.jpg");
		    backgroundGameT = new Texture(game, "backgroundgame.jpg");
	        btnBoostBlackT = new Texture(game, "boost-black.png");
	        btnBoostBlueT = new Texture(game, "boost-blue.png");
	        btnBoostRedT = new Texture(game, "boost-red.png");
	        btnFlipBlackT = new Texture(game, "flip-black.png");
	        btnFlipBlueT = new Texture(game, "flip-blue.png");
	        btnFlipRedT = new Texture(game, "flip-red.png");
	        btnRotateBlackT = new Texture(game, "rotate-black.png");
	        btnRotateBlueT = new Texture(game, "rotate-blue.png");
	        btnRotateRedT = new Texture(game, "rotate-red.png");
	        pauseBtnT = new Texture(game, "pauseBtn.png");
	        menuT = new Texture(game, "menu.png");
	        pauseT = new Texture(game, "pause.png");
	   	    readyT = new Texture(game, "ready.png");
	   	    falledT = new Texture(game, "falled.png");
	   	    timeIsUpT = new Texture(game, "time is up.png");
	   	    statsT = new Texture(game, "stats.png");
	   	    numbersT = new Texture(game, "numbers.png");
	   	    skaterT = new Texture(game, "skater.png");
	   	    soundOnT = new Texture(game, "soundOn.png");
	   	    soundOffT = new Texture(game, "soundOff.png");
	   	    logoT = new Texture(game, "logo.png");
		
		 
	   	    background = new TextureRegion(backgroundT, 0, 0, 320, 480);
	        backgroundGame = new TextureRegion(backgroundGameT, 0, 0, 320, 480);
	        btnBoostBlack = new TextureRegion(btnBoostBlackT, 0, 0, 95, 29);
	        btnBoostBlue = new TextureRegion(btnBoostBlueT, 0, 0, 95, 29);
	        btnBoostRed = new TextureRegion(btnBoostRedT, 0, 0, 95, 29);
	        btnFlipBlack = new TextureRegion(btnFlipBlackT, 0, 0, 70, 40);
	        btnFlipBlue = new TextureRegion(btnFlipBlueT, 0, 0, 70, 40);
	        btnFlipRed = new TextureRegion(btnFlipRedT, 0, 0, 70, 40);
	        btnRotateBlack = new TextureRegion(btnRotateBlackT, 0, 0, 95, 28);
	        btnRotateBlue  = new TextureRegion(btnRotateBlueT, 0, 0, 95, 28);
	        btnRotateRed = new TextureRegion(btnRotateRedT, 0, 0, 95, 28);
	        pauseBtn = new TextureRegion(pauseBtnT, 0, 0, 50, 50);
	        menu  = new TextureRegion(menuT, 0, 0, 288, 154);
	        pause = new TextureRegion(pauseT, 0, 0, 238, 105);
	   	    ready = new TextureRegion(readyT, 0, 0, 253, 54);
	   	    falled = new TextureRegion(falledT, 0, 0, 184, 43);
	   	    timeIsUp = new TextureRegion(timeIsUpT, 0, 0, 160, 90);
	   	    stats = new TextureRegion(statsT, 0, 0, 120, 68);
	   	    score = new TextureRegion(statsT, 0, 0, 120, 30);
	   	    num1 = new TextureRegion(numbersT, 0, 0, 30, 19);
	   	    num2 = new TextureRegion(numbersT, 30, 0, 30, 19);
	   	 	num3 = new TextureRegion(numbersT, 60, 0, 30, 19);
	   	 	num4 = new TextureRegion(numbersT, 90, 0, 30, 19);
	   	 	num5 = new TextureRegion(numbersT, 120, 0, 30, 19);
	   	 	num6 = new TextureRegion(numbersT, 150, 0, 30, 19);
	   	 	num7 = new TextureRegion(numbersT, 180, 0, 30, 19);
	   	 	num8 = new TextureRegion(numbersT, 210, 0, 30, 19);
	   	 	num9 = new TextureRegion(numbersT, 240, 0, 30, 19);
	   	 	num0 = new TextureRegion(numbersT, 270, 0, 30, 19);
	   	    skater = new TextureRegion(skaterT, 0, 0, 38, 70);
	   	    soundOn = new TextureRegion(soundOnT, 0, 0, 70, 47);
	   	    soundOff  = new TextureRegion(soundOffT, 0, 0, 70, 47);
	   	    logo = new TextureRegion(logoT, 0, 0, 234, 171);
	   	    
	   	    
	    	  
	       
	   	    music = game.getAudio().newMusic("skater boy.mp3");
	        music.setLooping(true);
	        music.setVolume(0.2f);
	        if(Settings.soundEnabled)
	            music.play();
	        
	        boostSound = game.getAudio().newSound("boost.wav");
	        flipSound = game.getAudio().newSound("flip.wav");
	        rotateSound = game.getAudio().newSound("rotate.wav");
	        clickSound = game.getAudio().newSound("click.wav");
	        
	        
	    }       
	    
	    public static void reload() {
	    	Log.d(TAG, "Assets.reload()");
	    	
	    	backgroundT.reload();
	        backgroundGameT.reload();
	        btnBoostBlackT.reload();
	        btnBoostBlueT.reload();
	        btnBoostRedT.reload();
	        btnFlipBlackT.reload();
	        btnFlipBlueT.reload();
	        btnFlipRedT.reload();
	        btnRotateBlackT.reload();
	        btnRotateBlueT.reload();
	        btnRotateRedT.reload();
	        menuT.reload();
	        pauseT.reload();
	   	    readyT.reload();
	   	    falledT.reload();
	   	    timeIsUpT.reload();
	   	    statsT.reload();
	   	    numbersT.reload();
	   	    skaterT.reload();
	   	    soundOnT.reload();
	   	    soundOffT.reload();
	   	    logoT.reload();
	   	    
	        if(Settings.soundEnabled)
	            music.play();
	    }
	    
	    public static void playSound(Sound sound) {
	    	Log.d(TAG, "Assets.playSound()");
	        if(Settings.soundEnabled)
	            sound.play(1);
	    }
}
