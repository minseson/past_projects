import java.net.*;
import java.util.*;
import java.io.*; 
  
public class ChattyChatChatServer 
{ 
    private static int port;			//port number
    private static ServerSocket server;	//server socket
    private static int clientIndex;		//client number to keep track of the number of clients
    
    //A vector clienthandler to deal with individual client
    static Vector <ClientHandler> clients = new Vector<ClientHandler>();
    
    public static class ClientHandler implements Runnable {
    	
    	private Socket socket;		//A Socket
    	private String username;	//username for each client
    	public int index;			//index to keep track of the number of clients
    	
    	
    	public ClientHandler(Socket socket, int index) {//ClientHandler constructor
    		this.socket = socket;	//socket of individual client
    		this.index = index;		//index number of individual client
    		this.username = "Client " + index;	//default username
    	}//END ClientHandler constructor
    	
    	//run() function implementation overriden from Runnable
    	@Override
    	public void run(){
    		try {
    			boolean running = true;		//a boolean to run this function 
    		
    			//BuffereReader: read the user input 
	    		BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	    		//PrintWriter: output to the user
	    		PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
	    		
	    		//A greeting message to the user
	    		out.println("[Server]: Welcome to ChattyChatChatServer.");
	    		
	    		//while the boolean value running is true
	    		while(running) {
	    			String command = in.readLine();		//read from the user
	    			if(command == null) running = false;//if the user is disconnected
	    			else {
	    				//Splitting the command to determine the user choice
	    				String[] commandArr = command.split(" ");	
	    				if(command.startsWith("/quit")) {			//the user wants to quit
	    					running = false;			//while loop stops
	    					synchronized(clients){
	    						clients.remove(this);	//remove this client from the vector
	    						clientIndex--;			//remove the integer reference to this client
	    					}
	    					out.println("[Server]: Thanks for using ChattyChatChat program.");
	    				} else if (command.startsWith("/dm")) {//the user wants to send a private message
	    					if(commandArr.length > 1) {
	    						String name = commandArr[1];   //the receiving client's name is after /nick
	    						synchronized(clients) {
	    							for(int i = 0; i < clients.size(); i++) {	//for the number of clients
	    								if(clients.elementAt(i).username.contains(name)) {
		    								//if the receiving client exists
	    									PrintWriter dm = new PrintWriter(clients.elementAt(i)
	    											.socket.getOutputStream(), true);
	    									String message = "";
	    									//a for-loop to converge the message from the array
	    									for(int j = 2; j < commandArr.length; j++) {
	    										message += commandArr[j] + " ";
	    									}
	    									//send message
	    									dm.println("[DM:"+username+"]: "+message); 
	    									//send message
	    		    						out.println("[Server]: DM sent to "+name+".");
	    								}
	    							}
		    					}
	    					}
	    				} else if (command.startsWith("/nick")) {//the user wants to change the name
	    					this.username = commandArr[1]; //user name is the next word after /nick
	    					out.println("[Server]: Your user name is now " + this.username + ".");
	    				} else {	//the user wants to send a public message
	    					synchronized(clients) {
	    						for(int i= 0; i < clients.size(); i++) { //for the number of clients
	    							if(this != clients.elementAt(i)) { //except for oneself
		    							PrintWriter all = new PrintWriter(clients.elementAt(i).socket.getOutputStream(), true);
		    							String message = "";
		    							//a for-loop to converge the message from the array
										for(int j = 0; j < commandArr.length; ++j) {
											message += commandArr[j] + " ";
										}
										all.println("["+username+"]: "+message); //send message
	    							}
	    						}
	    					}
	    				}
	    			}
	    			out.print("["+username+"]: "); //for a better user-interface
	    		}
    		} catch (IOException e) {
    			e.getStackTrace();
    			System.err.println("["+username+"]: Error caught in run().");
    		} finally {
    			System.err.println("["+username+"]: Disconnected.");
    		}
    	}//END run
    }//END ClientHandler
    
    //the main function of the main
    public static void main(String args[]) throws IOException
    { 
    	port = Integer.parseInt(args[0]); 	//the first string in the argument
		server = new ServerSocket(port);	//open a server socket
        
     // starts server and waits for a connection 
        try
        { 
        	//for a better server-user-interface
            System.out.println("[Server]: Server at port " + port + " started."); 
            System.out.println("[Server]: Waiting for a client."); 
            while (true) {

            	//Accept the incoming request from the same port
                 Socket socket = server.accept();
                 
          		 //Create a new handler object to handle this request
                 ClientHandler clientThread = new ClientHandler(socket, clientIndex);
                 clients.add(clientThread);
                 
                 System.out.println("[Server]: Connected to a client " + socket);
                 System.out.println("[Server]: Currnet number of clients is " + clients.size());
                 
                 //Create a new handler object for handling this request
                 Thread t = new Thread(clientThread);
                 t.start();

                 //increment index for new client
                 clientIndex++;
            }
        } 
        catch(IOException i) 
        { 
        	//outputs error messages when IOException caught
        	System.err.println("[Server]: Caught an IOException in server.");
        } 
		
    } //END main
} //END ChattyChatChatServer