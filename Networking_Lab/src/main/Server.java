package main;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] arg){
        System.out.println("Server Ready");
        try{
            ServerSocket socket = new ServerSocket(6666);
            Socket s =socket.accept();

            DataInputStream din = new DataInputStream(s.getInputStream());
            String str = (String)din.readUTF();
            System.out.println("Client Message= "+ str);

            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
