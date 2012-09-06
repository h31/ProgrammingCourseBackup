package myfuture.androidgames.rampskater;

public class Button {

	// variables
	public static final int BUTTON_AVAILABLE = 1;
	public static final int BUTTON_DISABLE = 0;
	public static final int BUTTON_CLAMPED = 2;
	
	public String name;
	public int state;
	
	// methods
	public Button(String name, int state){
		this.name = name;
		this.state = state;
	}
	
}
