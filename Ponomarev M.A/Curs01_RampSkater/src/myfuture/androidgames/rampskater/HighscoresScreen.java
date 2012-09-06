package myfuture.androidgames.rampskater;

import java.util.List;

import javax.microedition.khronos.opengles.GL10;

import com.badlogic.androidgames.framework.Game;
import com.badlogic.androidgames.framework.Input.TouchEvent;
import com.badlogic.androidgames.framework.gl.Camera2D;
import com.badlogic.androidgames.framework.gl.SpriteBatcher;
import com.badlogic.androidgames.framework.gl.Texture;
import com.badlogic.androidgames.framework.gl.TextureRegion;
import com.badlogic.androidgames.framework.impl.GLScreen;
import com.badlogic.androidgames.framework.math.OverlapTester;
import com.badlogic.androidgames.framework.math.Rectangle;
import com.badlogic.androidgames.framework.math.Vector2;



public class HighscoresScreen extends GLScreen {
    Camera2D guiCam;
    SpriteBatcher batcher;
    Rectangle backBounds;
    Vector2 touchPoint;
    String[] highScores;  
    Texture highscoresImage;
    TextureRegion highscoresRegion;    
    
    public HighscoresScreen(Game game) {
        super(game);
        
        guiCam = new Camera2D(glGraphics, 320, 480);
        backBounds = new Rectangle(0, 230, 70, 50);
        touchPoint = new Vector2();
        batcher = new SpriteBatcher(glGraphics, 100);
        highScores = new String[5];        
        for(int i = 0; i < 5; i++)  highScores[i] = "" + Settings.highscores[i];
            
    }    

    @Override
    public void update(float deltaTime) {
        List<TouchEvent> touchEvents = game.getInput().getTouchEvents();
        game.getInput().getKeyEvents();
        int len = touchEvents.size();
        for(int i = 0; i < len; i++) {
            TouchEvent event = touchEvents.get(i);
            touchPoint.set(event.x, event.y);
            guiCam.touchToWorld(touchPoint);
            
            if(event.type == TouchEvent.TOUCH_UP) {
                if(OverlapTester.pointInRectangle(backBounds, touchPoint)) {
                    game.setScreen(new MainMenuScreen(game));
                    Assets.playSound(Assets.clickSound);
                    return;
                }
            }
        }
    }

    public void draw_score(GL10 gl) {
    	String currChar;
        for(int i=0; i<5; i++) {
        	//for(int j=0; j<highScores[i].length();j++){
        		for(int j=highScores[i].length()-1; j>-1;j=j-1){
     			currChar = String.valueOf(highScores[i].charAt(j));
     			draw_number(gl, Integer.parseInt(currChar), 200-30*(highScores[i].length()-j), 480-160-40*i);  
     		} 
        }
        
    }
    public void draw_number(GL10 gl, int number, int coordX, int coordY) {
    	gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
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
        gl.glDisable(GL10.GL_BLEND);
    }
    
    @Override
    public void present(float deltaTime) {
        GL10 gl = glGraphics.getGL();        
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
        guiCam.setViewportAndMatrices();
        
        gl.glEnable(GL10.GL_TEXTURE_2D);
        
        batcher.beginBatch(highscoresImage);
        batcher.drawSprite(160, 240, 320, 480, highscoresRegion);
        batcher.endBatch();
        
        draw_score(gl);
    }
    
    
    @Override
    public void resume() {       
    	highscoresImage = new Texture(glGame, "highscoresScreen.jpg" );
    	highscoresRegion = new TextureRegion(highscoresImage, 0, 0, 320, 480);
    }
    
    @Override
    public void pause() {      
    	highscoresImage.dispose();
    }

    @Override
    public void dispose() {
    }
}