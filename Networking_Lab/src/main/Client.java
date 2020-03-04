package main;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client {
    public static void main(String[] arg){
        Scanner in = new Scanner(System.in);
        System.out.println("Server addess: ");
        String add = in.nextLine();
        try{
            Socket soc = new Socket(add,6666);
            //System.out.println("Connection Established.");
            DataOutputStream out = new DataOutputStream(soc.getOutputStream());
            out.writeUTF("I am Client");

            out.flush();
            out.close();
            soc.close();
        }catch (Exception e) {
            System.out.println(e);
        }
    }
}
