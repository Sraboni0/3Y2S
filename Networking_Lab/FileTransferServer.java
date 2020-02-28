package main;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class FileTransferServer {
    public static void main(String[] args) throws IOException{
        String fileName = "abc.txt";
        try {
            ServerSocket ss = new ServerSocket(8000);
            File myFile = new File(fileName);
            Socket soc = ss.accept();
            byte[] mybyteArray = new byte[(int) myFile.length()];
            
            BufferedInputStream bf = new BufferedInputStream(new FileInputStream(myFile));
            bf.read(mybyteArray,0,mybyteArray.length);

            OutputStream os = soc.getOutputStream();
            os.write(mybyteArray, 0,mybyteArray.length);
            os.flush();
            bf.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
