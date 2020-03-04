package main;

import java.io.*;
import java.net.Socket;

public class ChatClient {
    public static void main(String[] arg) throws IOException {
        Socket soc = new Socket("localhost",3333);
        DataInputStream din = new DataInputStream(soc.getInputStream());
        DataOutputStream dout = new DataOutputStream(soc.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str="",str2="";
        while (!str.equals("stop")){
            str = br.readLine();
            dout.writeUTF(str);
            dout.flush();
            str2 = din.readUTF();
            System.out.println("Server Says: "+str2);
        }
        dout.close();
        soc.close();
    }
}
