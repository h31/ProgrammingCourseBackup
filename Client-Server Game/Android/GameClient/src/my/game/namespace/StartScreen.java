package my.game.namespace;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class StartScreen extends Activity implements OnClickListener {
	
	@Override
    public void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        
        // ������ "Start"
        Button startButton = (Button)findViewById(R.id.StartButton);
        startButton.setOnClickListener(this);

        // ������ "Exit"
        Button exitButton = (Button)findViewById(R.id.ExitButton);
        exitButton.setOnClickListener(this);

        // ������ "Settings"
        Button settingsButton = (Button)findViewById(R.id.SettingsButton);
        settingsButton.setOnClickListener(this);
        
    }
	
	
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch (v.getId())
		{
			case R.id.StartButton:{
				Intent intent = new Intent();
				intent.setClass(this, GameScreen.class);
				startActivity(intent);
			}
			
			case R.id.SettingsButton:{
				break;
			}
			
			case R.id.ExitButton:{
				finish();
				break;
			}
			default:
				break;
			
		}
	}

}