package main;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class MessageClient {
	public static void main(String[] args) throws IOException{
		Socket soc = new Socket("localhost",8000);
		DataOutputStream dos = new DataOutputStream(soc.getOutputStream());
        dos.writeUTF("Hello World");
        dos.close();
	}
}
