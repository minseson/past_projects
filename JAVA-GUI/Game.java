import java.awt.*;
import java.awt.image.BufferStrategy;

public class Game extends Canvas implements Runnable {
	private static final long serialVersionUID = 23421; //serialVersionUID
	
	//Width and Height set to the full size of the screen
	public static final int WIDTH = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
	public static final int HEIGHT = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
	
	//takes the pixels per inch
	public final int resolution = Toolkit.getDefaultToolkit().getScreenResolution();
	//converts the pixels per inch to centimeters
	public final int res_cent = (int) (resolution / 2.54);
	
	
	private Thread thread;//Thread
	private boolean running = false;//A boolean that checks if the thread is still running
	private Handler handler;//a handler to take care of the particles
	
	private double leftSpeed, rightSpeed; //doubles to store speed of left and right boxes
	private double leftTemp, rightTemp; //doubles to store temperature of left and right boxes
	
	//constants to make the format of the game similar on every screen
	private final double ONE_EIGHTH = 0.125;
	private final double TWO_EIGHTH = 0.250;
	private final double THREE_EIGHTH = 0.375;
	private final double FOUR_EIGHTH = 0.500;
	private final double FIVE_EIGHTH = 0.625;
	private final double SIX_EIGHTH = 0.750;
	
	//Game class default constructor
	public Game() {
		
		//initializes handler
		handler = new Handler(WIDTH, HEIGHT);
		
		//Adds a mouselistener
		this.addMouseListener(new UserMouseInput(handler));

		//Window class to set JFrame
		new Window(WIDTH, HEIGHT, "Maxwell's Demon Simulator", this, handler);
		
		handler.intialAddParticle();//handler adds particles
	}//END Game()
	
	
	//Game class start()
	//this starts the thread and set running to true
	public synchronized void start() {
		thread = new Thread(this);
		thread.start();
		running = true;
	}//END synchronized void start()
	
	
	//Game class stop()
	//aborts the programme
	public synchronized void stop() {
		try {
			running = false;
			System.exit(0);
			thread.join();
		} catch(Exception e) {
			e.printStackTrace();
		}
		
	}

	//Game class function implementing Runnable
	@Override
	public void run() {
		long lastTime = System.nanoTime();
		double amountOfTicks = 60.0;
		double ns = 1000000000/ amountOfTicks;
		double delta = 0;
		long timer = System.currentTimeMillis();
		int frames = 0;
		
		while(running) { //as long as runnin == true
			long nowTime = System.nanoTime();
			delta += (nowTime - lastTime) / ns;
			lastTime = nowTime;
			while(delta >= 1) {
				tick();
				delta--;
			}//END while(delta >= 1)
			
			if(running) {
				render();
			}//END if(running)
			
			frames++;
			
			//updates and stores frame per second
			if(System.currentTimeMillis() - timer > 1000) {
				timer += 1000;
				System.out.println("FPS: " + frames);
				
				//updates speed and temperature every second
				leftSpeed = handler.getLeftSpeed(frames);
				rightSpeed = handler.getRightSpeed(frames);
				leftTemp = handler.getLeftTemperature(frames, res_cent);
				rightTemp = handler.getRightTemperature(frames, res_cent);
				frames = 0; //set frames to zero for the next second
			}//END if(System.currentTimeMillis() - timer > 1000)
			
		}//while(running)
		stop();//stops if running == false
	}//END void run()
	
	
	//Game class tick()
	//this class moves the particles
	private void tick() {
		handler.tick();
	}//END void tick()
	
	
	//Game class render()
	//this class paints
	private void render() {
		//instnatiate a bufferStrategy
		BufferStrategy bs = this.getBufferStrategy();
		if(bs == null) { //buffer starts with null
			this.createBufferStrategy(3);
			return;
		}//END if(bs == null)
		
		//Graphics to draw
		Graphics g = bs.getDrawGraphics();
		
		g.setColor(Color.white); //background set to white
		g.fillRect(0, 0, WIDTH, HEIGHT); //draws a white background
		g.setColor(Color.black);//Rest of them in black if not otherwise
		g.setFont(new Font("Arial",Font.PLAIN,40));//set the font to arial and size to 40
		
		//this draws the big rectangle
		g.drawRect((int) (WIDTH * ONE_EIGHTH), (int) (HEIGHT * ONE_EIGHTH),
				(int) (WIDTH * SIX_EIGHTH), (int) (HEIGHT * FOUR_EIGHTH)); 
		
		//when mouse is not clicked
		if(handler.getMouseClicked() == false) {
			g.drawLine((int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * ONE_EIGHTH),
					(int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * FIVE_EIGHTH));
		} 
		//if mouse is clicked
		else if(handler.getMouseClicked() == true) {
			g.drawLine((int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * ONE_EIGHTH),
					(int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * TWO_EIGHTH ));
			g.drawLine((int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * FOUR_EIGHTH + 30),
					(int)(WIDTH * FOUR_EIGHTH), (int)(HEIGHT * FIVE_EIGHTH));
		}
		
		//This visually represent if the mouse is clicked
		if(handler.getMouseClicked() == false) g.drawString("Mouse: Released" ,
				(int)(WIDTH * ONE_EIGHTH),(int)(HEIGHT * ONE_EIGHTH - 10));
		else if(handler.getMouseClicked() == true)g.drawString("Mouse: Clicked",
				(int)(WIDTH * ONE_EIGHTH), (int)(HEIGHT * ONE_EIGHTH - 10));
		
		//Display of average speed on both left and right sides
		String sLeftSpeed = String.format("%.2f", leftSpeed);
		g.drawString("Left Speed: "+sLeftSpeed , (int)(WIDTH * ONE_EIGHTH),
				(int)(HEIGHT * FIVE_EIGHTH) + 40);
		String sRightSpeed = String.format("%.2f", rightSpeed);
		g.drawString("Right Speed: " + sRightSpeed , (int)(WIDTH * FOUR_EIGHTH),
				(int)(HEIGHT * FIVE_EIGHTH) + 40);
		
		//Display of average temperature on both left and right sides
		String sLeftTemperature = String.format("%.2f", leftTemp);
		g.drawString("Left Temperature: "+sLeftTemperature , (int)(WIDTH * ONE_EIGHTH),
				(int)(HEIGHT * FIVE_EIGHTH) + 80);
		String sRightTemperature = String.format("%.2f", rightTemp);
		g.drawString("Right Temperature: " + sRightTemperature , (int)(WIDTH * FOUR_EIGHTH),
				(int)(HEIGHT * FIVE_EIGHTH) + 80);
		
		//Display of particles summary on both left and right sides
		g.drawString("Left Count: " + handler.getLeftCount() , (int)(WIDTH * THREE_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 40);
		g.drawString("Right Count: " + handler.getRightCount() , (int)(WIDTH * SIX_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 40);
		g.drawString("Left Red Count: " + handler.getLeftRedCount() , (int)(WIDTH * THREE_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 80);
		g.drawString("Right Red Count: " + handler.getRightRedCount() , (int)(WIDTH * SIX_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 80);
		g.drawString("Left Blue Count: " + handler.getLeftBlueCount() , (int)(WIDTH * THREE_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 120);
		g.drawString("Right Blue Count: " + handler.getRightBlueCount() , (int)(WIDTH * SIX_EIGHTH)-50,
				(int)(HEIGHT * FIVE_EIGHTH) + 120);
		
		//This calls each particle's render(Graphics g)
		handler.render(g);
		
		g.dispose();
		bs.show();
	}//END void render()
	
	//main function
	public static void main(String[] args) {
		new Game(); //calls for a new game
	}//END static void main(String[] args)
}//END Game class implementation
