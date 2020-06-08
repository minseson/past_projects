import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Button extends JLabel implements ActionListener{
	
	private static final long serialVersionUID = 9084110186075165803L;
	//constants
	protected final double ONE_EIGHTH = 0.125;
	protected final double TWO_EIGHTH = 0.250;
	protected final double THREE_EIGHTH = 0.375;
	protected final double FOUR_EIGHTH = 0.500;
	protected final double FIVE_EIGHTH = 0.625;
	protected final double SIX_EIGHTH = 0.750;
	protected final double SEVEN_EIGHTH = 0.875;
	
	protected final double ONE_SIXTEENTH = 0.0625;
	protected final double TWO_SIXTEENTH = 0.1250;
	protected final double THREE_SIXTEENTH = 0.1875;
	protected final double FOUR_SIXTEENTH = 0.2500;
	protected final double FIVE_SIXTEENTH = 0.3125;
	protected final double SIX_SIXTEENTH = 0.3750;
	protected final double EIGHT_SIXTEENTH = 0.500;
	protected final double TEN_SIXTEENTH = 0.6250;	
	protected final double ELEVEN_SIXTEENTH = 0.6875;	
	
	protected final int THREE = 3;
	protected final int SIX = 6;
	//Three main buttons
	JButton particleAdd, reset, exit;
	//Four additional buttons
	JButton addRedLeft, addRedRight, addBlueLeft, addBlueRight;
	//Stores this Handler
	Handler handler;
	//Stores this JFrame
	JFrame frame;
	//Stores this Game
	Game game;
	//Stores this width and height
	int width, height;
	
	//Button class construcor
	public Button(int width, int height, JFrame frame, Game game) {
		
		this.width = width;
		this.height = height;
		
		this.frame = frame;
		this.game = game;
		
		//instantiate the buttons as new JBottons
		particleAdd = new JButton("Add Particle");
		reset = new JButton("Reset");
		exit = new JButton("Exit");
		addRedLeft = new JButton("Add Red on Left"); 
		addRedRight = new JButton("Add Red on Right"); 
		addBlueLeft = new JButton("Add Blue on Left"); 
		addBlueRight = new JButton("Add Blue on Left"); 
		
		//Setting the buttons' font and font's size
		particleAdd.setFont(new Font("Arial", Font.PLAIN, 40));
		reset.setFont(new Font("Arial", Font.PLAIN, 40));
		exit.setFont(new Font("Arial", Font.PLAIN, 40));
		addRedLeft.setFont(new Font("Arial", Font.PLAIN, 40));
		addRedRight.setFont(new Font("Arial", Font.PLAIN, 40));
		addBlueLeft.setFont(new Font("Arial", Font.PLAIN, 40));
		addBlueRight.setFont(new Font("Arial", Font.PLAIN, 40));

		//Setting particle add button location and size
		particleAdd.setLayout(null);
		particleAdd.setLocation((int) (width * TWO_SIXTEENTH) , (int)(height * SEVEN_EIGHTH));
		particleAdd.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		particleAdd.addActionListener(this);
		
		//Setting reset button location and size
		reset.setLayout(null);
		reset.setLocation((int) (width * SIX_SIXTEENTH) , (int)(height * SEVEN_EIGHTH));
		reset.setSize((int) (width * FOUR_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		reset.addActionListener(this);
		
		//Setting exit button location and size
		exit.setLayout(null);
		exit.setLocation((int) (width * ELEVEN_SIXTEENTH) , (int)(height * SEVEN_EIGHTH));
		exit.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		exit.addActionListener(this);

		//Setting adding red particle on the left box button location and size
		addRedLeft.setLayout(null);
		addRedLeft.setLocation((int)(width * TWO_SIXTEENTH), (int)(height * SIX_EIGHTH));
		addRedLeft.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		addRedLeft.addActionListener(this);
		
		//Setting adding blue particle on the left box button location and size
		addBlueLeft.setLayout(null);
		addBlueLeft.setLocation((int)(width * FIVE_SIXTEENTH), (int)(height * SIX_EIGHTH));
		addBlueLeft.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		addBlueLeft.addActionListener(this);

		//Setting adding red particle on the right box button location and size
		addRedRight.setLayout(null);
		addRedRight.setLocation((int)(width * EIGHT_SIXTEENTH), (int)(height * SIX_EIGHTH));
		addRedRight.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		addRedRight.addActionListener(this);

		//Setting adding blue particle on the right box button location and size
		addBlueRight.setLayout(null);
		addBlueRight.setLocation((int)(width * ELEVEN_SIXTEENTH), (int)(height * SIX_EIGHTH));
		addBlueRight.setSize((int) (width * THREE_SIXTEENTH) , (int)(height * ONE_SIXTEENTH));
		addBlueRight.addActionListener(this);

		//adding buttons to this JFrame
		frame.add(addRedLeft);
		frame.add(addRedRight);
		frame.add(addBlueLeft);
		frame.add(addBlueRight);
		frame.add(particleAdd);
		frame.add(reset);
		frame.add(exit);
	}//END Button constructor
	
	//sethandler function
	public void setHandler(Handler handler) {
		this.handler = handler;
	}//END void setHandler(Handler handler)
	

	//a void actionPerformed(ActionEvent e) function to 
	//see which buttons are clicked
	@Override
	public void actionPerformed(ActionEvent e) {
		JButton source = (JButton) e.getSource();
		if(source == particleAdd) {
			handler.addParticle();
		} else if(source == reset) {
			handler.removeAll();
			handler.intialAddParticle();
		} else if(source == addRedLeft) {
			handler.addObject(new T1(width, height, Side.Left));
		} else if(source == addRedRight) {
			handler.addObject(new T1(width, height, Side.Right));
		} else if(source == addBlueLeft) {
			handler.addObject(new T2(width, height, Side.Left));
		} else if(source == addBlueRight) {
			handler.addObject(new T2(width, height, Side.Right));
		} else if(source == exit) {
			frame.dispose();
			game.stop();
		}
	}//END void actionPerformed(ActionEvent e)

}//END Button class
