import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

//Hot, blue particles
//Extends GameObject
public class T1 extends GameObject{
	//T1 object constructor
	public T1(int width, int height, Side side) {
		super(width, height, side);
		r = new Random();
		id = ID.Red;

		//if the side instantiated as left, then generate a random location in the left box
		if(Side.Left == side) {
			x = (int) (r.nextInt((int) (width * THREE_EIGHTH)) + width * ONE_EIGHTH);
			y = (int) (r.nextInt((int) (height * FOUR_EIGHTH)) + height * ONE_EIGHTH);
		} 
		//if the side instantiated as right, then generate a random location in the right box
		else if (Side.Right == side) {
			x = (int) (r.nextInt((int) (width * THREE_EIGHTH)) + width * FOUR_EIGHTH);
			y = (int) (r.nextInt((int) (height * FOUR_EIGHTH)) + height * ONE_EIGHTH);
		}
		
		//randomnly generated velocity
		//faster than T2
		this.velocityX = r.nextInt(6) + 1;
		this.velocityY = r.nextInt(6) + 1;
		velX = velocityX;
		velY = velocityY;
	}
	

	//tick() function implementation
	public void tick() {
		//if the mouse is not clicked and the particle is on the left side
		if(mouseClicked == false && side == Side.Left) {
			if (x + velX < width * ONE_EIGHTH) {
				velX = velocityX;
			} else if (x + velX > width * FOUR_EIGHTH - diameter) {
				velX = -velocityX;
			} else if (y + velY < height * ONE_EIGHTH) {
				velY = velocityY;
			} else if (y + velY > height * FIVE_EIGHTH - diameter) {
				velY = -velocityY;
			}
			x += velX;
			y += velY;
		} 
		//if the mouse is clicked and the particle is on the left side
		//if it reaches the wall, then the particle can move to the right box
		else if (mouseClicked == true && side == Side.Left) {
			if (x + velX < width * ONE_EIGHTH + diameter) {
				velX = velocityX;
			} else if (x + velX > width * FOUR_EIGHTH - diameter) {
				velX = -velocityX;
			} else if (y + velY < height * ONE_EIGHTH) {
				velY = velocityY;
			} else if (y + velY > height * FIVE_EIGHTH - diameter) {
				velY = -velocityY;
			}
			
			if(x  + velX +velX > width * FOUR_EIGHTH - diameter 
					&& System.currentTimeMillis() - timer > 5000) {
				if(y + velY > height * TWO_EIGHTH && y + velY < height * FOUR_EIGHTH) {
					side = Side.Right;
					velX = velocityX;
					timer = System.currentTimeMillis();
				}
			}
			x += velX;
			y += velY;
		}
		//if the mouse is not clicked and the particle is on the right side
		else if(mouseClicked == false && side == Side.Right) {
			if (x + velX < width * FOUR_EIGHTH) {
				velX = velocityX;
			} else if (x + velX > width * SEVEN_EIGHTH - diameter) {
				velX = -velocityX;
			} else if (y + velY < height * ONE_EIGHTH) {
				velY = velocityY;
			} else if (y + velY > height * FIVE_EIGHTH - diameter) {
				velY = -velocityY;
			}
			x += velX;
			y += velY;
		} 
		//if the mouse is clicked and the particle is on the right side
		//if it reaches the wall, then the particle can move to the left box
		else if(mouseClicked == true && side == Side.Right) {
			if (x + velX < width * FOUR_EIGHTH) {
				velX = velocityX;
			} else if (x + velX > width * SEVEN_EIGHTH - diameter) {
				velX = -velocityX;
			} else if (y + velY < height * ONE_EIGHTH) {
				velY = velocityY;
			} else if (y + velY > height * FIVE_EIGHTH - diameter) {
				velY = -velocityY;
			}
			
			if(x - velX - velX < width * FOUR_EIGHTH  && System.currentTimeMillis() - timer > 5000) {
				if(y + velY > height * TWO_EIGHTH && y + velY < height * FOUR_EIGHTH) {
					side = Side.Left;
					velX = -velocityX;
					timer = System.currentTimeMillis();
				}
			}
			x += velX;
			y += velY;
		}
	}//END void tick()

	//render(Graphics g) funciton implementation
	public void render(Graphics g) {		
		g.setColor(Color.red);
		g.fillOval(x,y, diameter, diameter);
		
	}//END void render(Graphics g)
}//END T1 object implementation
