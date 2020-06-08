import java.awt.Graphics;
import java.awt.Toolkit;
import java.util.LinkedList;

//A handler class to take care of objects in the box
public class Handler {

	//A LinkedList to store objects
	LinkedList<GameObject> object = new LinkedList<GameObject>();
	
	//for the calculation of speed of objects
	int resolution = Toolkit.getDefaultToolkit().getScreenResolution(); //pixels per inch
	int res_cent = (int) (resolution / 2.54);//converting to pixels per centimeter
	
	//stores this width and height
	private int width, height;
	
	//checks if mouse is clicked
	private boolean mouseClicked = false;
	
	//Handler constructor
	public Handler(int width, int height) {
		this.width = width;
		this.height = height;
	}//END Handler constructor
	
	//tick() function implementation
	public void tick() {
		for(int i = 0; i < object.size(); i++) {
			GameObject tempObject = object.get(i);
			
			tempObject.tick();
		}//END for(int i = 0; i < object.size(); i++)
	}//END void tick()
	
	//render() function implementation
	public void render(Graphics g) {
		for(int i = 0; i < object.size(); i++) {
			GameObject tempObject = object.get(i);
			
			tempObject.render(g);
		}//END forint i = 0; i < object.size(); i++)
	}//END void render(Graphics g)
	
	
	//this adds an object to the linked list
	//addObject(GameObject obj) function implementation
	public void addObject(GameObject obj) {
		this.object.add(obj);
	}//END void addObject(GameObject obj)
	
	//this removes an object from the linked list
	//removeObject(GameObject obj) function implementation
	public void removeObject(GameObject obj) {
		this.object.remove(obj);
	}//END void removeObject(GameObject obj)
	
	//this returns the average speed on the left box
	//getLeftSpeed(int frame)
	public double getLeftSpeed(int frame) {
		int objCount = 0;
		double speedSum = 0;
		double avgSpeed = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			
			if(temp.getSide() == Side.Left) {
				double objSpeed = temp.getSpeed(frame, res_cent);
				speedSum += objSpeed;
				objCount ++;
			} //END if(temp.getID() == ID.Red)
		}//END for(int i = 0; i < object.size(); i++)
		
		avgSpeed = speedSum / objCount;
		return avgSpeed;
	}//END double getRedSpeed(int frame)
	
	//this returns the average speed on the right box
	//getRightSpeed(int frame)
	public double getRightSpeed(int frame) {
		int objCount = 0;
		double speedSum = 0;
		double avgSpeed = -1;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			
			if(temp.getSide() == Side.Right) {
				double objSpeed = temp.getSpeed(frame,  res_cent);
				speedSum += objSpeed;
				objCount ++;
			} //END if(temp.getID() == ID.Red)
		}//END for(int i = 0; i < object.size(); i++)
		
		avgSpeed = speedSum / objCount;
		return avgSpeed;
	}//END double getBlueSpeed(int frame)
	
	//this returns the average temperature of the particles on the left box
	//getLeftTemperatrue(int frame, int res_cent)
	public double getLeftTemperature(int frame, int res_cent) {
		int objCount = 0;
		double temperatureSum = 0;
		double avgTemperature = -1;
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			
			if(temp.getSide() == Side.Left) {
				temperatureSum += temp.getTemperature(frame, res_cent);
				objCount++;
			}
		}
		avgTemperature = temperatureSum / objCount;
		return avgTemperature;
	}//END double getLeftTemperature(int frame, int res_cent)
	
	//this returns the average temperature of the particles on the Right box
	//getRightTemperatrue(int frame, int res_cent)
	public double getRightTemperature(int frame, int res_cent) {
		int objCount = 0;
		double temperatureSum = 0;
		double avgTemperature = -1;
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			
			if(temp.getSide() == Side.Right) {
				temperatureSum += temp.getTemperature(frame, res_cent);
				objCount++;
			}
		}
		avgTemperature = temperatureSum / objCount;
		return avgTemperature;
	}//END double getRightTemperature(int frame, int res_cent)
	
	//setMouseClicked(boolean clicked) function implementation
	public void setMouseClicked(boolean clicked) {
		mouseClicked = clicked;
	}//END void setMouseClicked(boolean clicked) 
	
	//getMouseClicked() function implementation
	public boolean getMouseClicked() {
		return mouseClicked;
	}//END boolean getMouseClicked()
	
	//this adds two red and blue particles on each side
	//addParticle() function implementation
	public void addParticle() { 
		this.addObject(new T1(width, height, Side.Left));
		this.addObject(new T1(width, height, Side.Right));

		this.addObject(new T2(width, height, Side.Left));
		this.addObject(new T2(width, height, Side.Right));
	}//END void addParticle()
	
	//this adds two red particles on the left box
	//and two blue particles on the right box
	//initialAddParticle() function implementation
	public void intialAddParticle() {
		this.addObject(new T1(width, height, Side.Left));
		this.addObject(new T1(width, height, Side.Left));

		this.addObject(new T2(width, height, Side.Right));
		this.addObject(new T2(width, height, Side.Right));
	}//END void initialAddParticle()
	
	//This removes all the objects from the LinkedList
	//removeAll() function implementation
	public void removeAll() {
		int size = object.size(); //for loop runs for the size of the linked list
		for(int i = 0; i < size; i++) {
			GameObject temp = object.get(0);
			
			this.removeObject(temp);
		}
	}//END void removeAll()
	
	//This returns the objects count on the left box
	//getLeftCount() function implementation
	public int getLeftCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Left) {
				count ++;
			}
		}
		
		return count;
	}//END int getLeftCount()
	
	//This returns the objects count on the right box
	//getRightCount() function implementation
	public int getRightCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Right) {
				count ++;
			}
		}
		
		return count;
	}//END int getRightCount()
	
	//This returns the number of red objects on the left box
	//getLeftRedCount() function implementation
	public int getLeftRedCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Left) {
				if(temp.getID() == ID.Red) {
					count ++;
				}
			}
		}
		
		return count;
	}//END int getLeftRedCount()
	
	//This returns the number of blue objects on the left box
	//getLeftBlueCount() function implementation
	public int getLeftBlueCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Left) {
				if(temp.getID() == ID.Blue) {
					count ++;
				}
			}
		}
		
		return count;
	}//END int getLeftBlueCount()
	
	//This returns the number of red objects on the right box
	//getRightRedCount() function implementation
	public int getRightRedCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Right) {
				if(temp.getID() == ID.Red) {
					count ++;
				}
			}
		}
		
		return count;
	}//END int getrightRedCount()
	
	//This returns the number of blue objects on the right box
	//getRightBlueCount() function implementation
	public int getRightBlueCount() {
		int count = 0;
		
		for(int i = 0; i < object.size(); i++) {
			GameObject temp = object.get(i);
			if(temp.getSide() == Side.Right) {
				if(temp.getID() == ID.Blue) {
					count ++;
				}
			}
		}
		
		return count;
	}//END int getRightBlueCount() 
	
}//END Class Handler
