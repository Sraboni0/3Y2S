package main;

import java.io.DataInputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class NewServer{
    public static void main(String[] arg){
        try {
            System.out.println("waiting for Client...");
            ServerSocket ss = new ServerSocket(8000);
            Socket s = ss.accept();
            DataInputStream dis = new DataInputStream(s.getInputStream());
            System.out.println(dis.readUTF());
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
   
}