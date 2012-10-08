package my.game.namespace;

import android.app.Activity;
import android.widget.Button;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;


public class GameScreen extends Activity implements OnClickListener {

	public void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setContentView(R.layout.game);
		
		Button upButton = (Button)findViewById(R.id.upButton);
		upButton.setOnClickListener(this);
		
		Button downButton = (Button)findViewById(R.id.downButton);
		downButton.setOnClickListener(this);
		
		Button leftButton = (Button)findViewById(R.id.leftButton);
		leftButton.setOnClickListener(this);
		
		Button rightButton = (Button)findViewById(R.id.rightButton);
		rightButton.setOnClickListener(this);
		
		
	}
	
	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		switch (arg0.getId())
		{
			case R.id.upButton: {
				break;
			}
			
			case R.id.downButton: {
				break;
			}
			
			case R.id.leftButton: {
				break;
			}
			
			case R.id.rightButton: {
				break;
			}
			
			default:
				break;
		}
		
	}

}
