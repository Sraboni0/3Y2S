package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	public static void main(String[] arg) {
		 try {
	            System.out.println("waiting for Client...");
	            ServerSocket ss = new ServerSocket(8000);
	            Socket soc = ss.accept();
	            //System.out.println("Connection Established.");
	            BufferedReader in =new BufferedReader(new InputStreamReader(soc.getInputStream()));
	            int num = Integer.parseInt(in.readLine());
	            PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
	            //System.out.println("num is: "+num);
	            out.println("Square is : "+ multi(num));
	            
	        }
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	 static int multi(int num)
	    {
	        return num*num;
	    }
}
