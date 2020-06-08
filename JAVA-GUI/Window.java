import java.awt.Canvas;
import java.awt.Dimension;

import javax.swing.*;

//This makes the window
public class Window extends Canvas{
	private static final long serialVersionUID = 23421;
	
	//Window class constructor
	public Window(int width, int height, String title, Game game, Handler handler) {
		JFrame frame = new JFrame(title);
		
		Button button = new Button(width, height, frame, game);
		button.setHandler(handler);
		
		frame.setPreferredSize(new Dimension(width, height));//setting preferred size to width and height
		frame.setMaximumSize(new Dimension(width, height));//setting max size to width and height
		frame.setMinimumSize(new Dimension(width, height));//setting min size to width and height
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//close all threads
		frame.setResizable(false);//window is not resizabe
		frame.setLocationRelativeTo(null);
		frame.add(game);//add a component game to jframe
		frame.setVisible(true);
		
		
		
		game.start();
		
	}//END Window class constructor
}//END Window class
