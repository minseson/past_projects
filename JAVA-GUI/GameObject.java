import java.awt.Graphics;
import java.util.Random;

//GameObjects which are particles
public abstract class GameObject {
	
	//Constants
	protected final double ONE_EIGHTH = 0.125;
	protected final double TWO_EIGHTH = 0.250;
	protected final double THREE_EIGHTH = 0.375;
	protected final double FOUR_EIGHTH = 0.500;
	protected final double FIVE_EIGHTH = 0.625;
	protected final double SIX_EIGHTH = 0.750;
	protected final double SEVEN_EIGHTH = 0.875;
	protected final double FIVE_SIXTEENTH = 0.3125;
	protected final double ELEVEN_SIXTEENTH = 0.6875;	
	protected final int THREE = 3;
	protected final int SIX = 6;
	
	//Variables
	protected int x,y;//the location of the particles
	protected ID id;//To determine if hot or cold
	protected Side side;//To determine the location of the particles in two boxes
	protected int velX, velY; //velocity in X and Y directions
	protected int velocityX, velocityY;//randonmly generated velocities
	
	protected int width, height;//screen size
	
	protected boolean mouseClicked;//boolean checking for if mouse is clicked
	
	protected int diameter;//int for diameter of the particles

	protected long timer;//timer to determine time passed
	
	protected Random r;//a Random variable
	
	
	//GameObject constructor
	public GameObject(int width, int height, Side side) {
		this.width = width; 
		this.height = height;
		this.side = side;
		this.mouseClicked = false; //mouse clicked set to false in default
		this.diameter = 30; //diameter set to 30 in default
		timer = 0;//timer set to 0 in default
	}//END GameObject (int width, int height, Side side)
	
	protected abstract void tick(); //this sets the velocity of particles and keeps in the boxes
	protected abstract void render(Graphics g); //this draws the particles
	
	public void setX(int x) {
		this.x = x;
	}//END void setX(int x)
	
	public void setY(int y) {
		this.y = y;
	}//END void setY(int y)
	
	public int getX() {
		return x;
	}//END int getX()
	
	public int getY() {
		return y;
	}//END int getY()
	
	public void setID(ID id) {
		this.id = id;
	}//END void setID(ID id)
	
	public ID getID() {
		return id;
	}//END ID getID()
	
	public void setVelX(int velX) {
		this.velX = velX;
	}//END void setVelX(int velX)
	
	public void setVelY(int velY) {
		this.velY = velY;
	}//END void setVelY(int velY)
	
	public int getVelX() {
		return velX;
	}//END int getVelX()
	
	public int getVelY() {
		return velY;
	}//END int getVelY()
	
	public int getVelocityX() {
		return velocityX;
	}//END int getVelocityX()
	
	public int getVelocityY() {
		return velocityY;
	}//END int getVelocityY()

	public void setSide(Side side) {
		this.side = side;
	}//END int setSide(Side side)

	public Side getSide() {
		return side;
	}//END Side getSide()
	
	public void setMouseClicked(boolean clicked) {
		mouseClicked = clicked;
	}//END void setMouseClicked(boolean clicked)
	
	public boolean getMouseClicked() {
		return mouseClicked;
	}//END boolean getMouseClicked()
	
	
	//This returns the temperature of the objects
	//implements root mean square velocity of gas particles
	public double getTemperature(int frame, int res_cent) {
		double tempSpeed = this.getSpeed(frame, res_cent);
		double tempSpeed2 = tempSpeed * tempSpeed;
		double mass = 0.002; //kilogram per mole, assumed as 0.002 (2g/mol)
		double gas_constant = 8.314;// unit: J/(mol * K)
		
		//Apply the equation
		double temperatureK = tempSpeed2 * mass / gas_constant /3;
		
		//Apply logarithm to convert it to celcius
		//this is not an exact method but the speed of particles are
		//much slower than the gas particles in real life
		double temperatureC = Math.log(1000000*temperatureK);
		
		return temperatureC ;
	}//END double getTemperature(int frame, int res_cent)
	
	//This returns the speed of the objects in centimeters
	public double getSpeed(int frame, int res_cent) {
		//get velocity in X direction and square it
		int tempVelX = this.getVelocityX();
		int tempVelX2 = tempVelX*tempVelX;
		
		//get velocity in Y direction and square it
		int tempVelY = this.getVelocityY();
		int tempVelY2 = tempVelY*tempVelY;
		
		//add the squares of two velocities in two directions
		int tempVelX2Y2 = tempVelY2 + tempVelX2;
		
		//apply power of 0.5 (root square)
		double tempSpeedPerFrame = Math.pow(tempVelX2Y2, 0.5);
		
		//calculate how much pixels an objects moves per second
		double tempSpeedPerSec = tempSpeedPerFrame * frame;
		
		//calculate how much centimeters an objects moves per second
		double tempSpeedPerSecInCM = tempSpeedPerSec / res_cent;
		
		return tempSpeedPerSecInCM;
	}//END double getSpeed(int frame, int res_cent)
}
