import java.net.*;
import java.io.*;

public class ChattyChatChatClient {
	private Socket socket = null;			//socket for communication
	private static boolean running = true;	//a boolean variable to determine to stop threads

	// Client default constructor implementation
	public ChattyChatChatClient(String host, int port) throws IOException {
		socket = new Socket(host, port);	//open a socket
		//BufferedReader: to receive message from the server
		BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		//BufferedReader: to receive message from the command by the user
		BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
		//PrintWriter: to send message to the server
		PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

		//Start two thread: one for sending message and another for receiving message to/from the server
		Thread send = new Thread(new sendThread(userInput, out));
		Thread receive = new Thread(new receiveThread(in, userInput));
		send.start();
		receive.start();

		//if either of the threads is not alive, then close client
		if (!send.isAlive() || !receive.isAlive()) socket.close();
	}//END ChattyChatChatClient constructor

	
	//main function of ChattyChatChatClient
	public static void main(String args[]) throws IOException {
		String host = args[0];		//the server is the first string of the argument
		int port = Integer.parseInt(args[1]);	//the host is the second string of the argument
		ChattyChatChatClient client = new ChattyChatChatClient(host, port); //create a client
	}//END main

	
	//A Thread for sending messages to the server
	class sendThread implements Runnable {
		private BufferedReader userIn;	//user's input from the command
		private PrintWriter out;		//out to the server

		//constructor for this thread
		public sendThread(BufferedReader userIn, PrintWriter out) {
			this.userIn = userIn;
			this.out = out;
		}//END constructor for sending the message

		@Override
		public void run() {
			//while the threads are running
			while (running) {
				try {
					//command from the user
					String command = userIn.readLine();
					if (command == null || command.startsWith("/quit")) running = false;
					
					//command is passed to the server
					out.println(command);
				} catch (IOException e) {
					e.getStackTrace();
					System.err.println("[Program]: Disconnected from the server.");
					running = false;
					System.exit(1);
				}
			}
		}//END run()
	}//END sendThread

	//A Thread for receiving messages to the server
	class receiveThread implements Runnable {
		private BufferedReader in;		//message from the server

		//constructor for this thread
		public receiveThread(BufferedReader in, BufferedReader userIn) {
			this.in = in;
		}//END constructor for receving the message from the server

		//implementation of run() function
		@Override
		public void run() {
			//while the threads are running
			while (running) {
				try {
					//message for server
					String incoming = in.readLine();
					//output the message from the server
					System.out.println(incoming);
				} catch (IOException e) {
					e.getStackTrace();
					System.err.println("[Program]: Disconnected from the server.");
					running = false;
					System.exit(1);
				}
			}
		}//END run
	}//END receiveThread
}//END ChattyChatChatClient
