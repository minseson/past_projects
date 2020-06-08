import java.awt.event.*;

//This checks if the mouse is clicked
public class UserMouseInput implements MouseListener {
	private Handler handler;
	
	public UserMouseInput(Handler handler) {
		this.handler = handler;
	}
	
	//If mouse is pressed then set the boolean value called mouseClicked in handler to true
	//and allow the objects to move between the bars
	@Override
	public void mousePressed(MouseEvent e) {
		for(int i = 0; i < handler.object.size(); i++) {
			GameObject tempObject = handler.object.get(i);
			
			tempObject.setMouseClicked(true);
		}
		handler.setMouseClicked(true);
	}
	
	//If mouse is released then set the boolean value called mouseClicked in handler to false
	//and disallow the objects to move between the bars
	@Override
	public void mouseReleased(MouseEvent e) {
		for(int i = 0; i < handler.object.size(); i++) {
			GameObject tempObject = handler.object.get(i);
			
			tempObject.setMouseClicked(false);
		}
		handler.setMouseClicked(false);
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		
	}

}
