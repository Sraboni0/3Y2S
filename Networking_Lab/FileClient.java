package main;

import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

public class FileClient {
    public static void main(String[] args) throws IOException{
        Socket soc = new Socket("localhost",8000);
        byte[] mybarr = new byte[1024];

        InputStream is = soc.getInputStream();
        FileOutputStream fos = new FileOutputStream("s.txt");
        BufferedOutputStream bos = new BufferedOutputStream(fos);

        int byteRead = is.read(mybarr,0,mybarr.length);
        bos.write(mybarr,0,mybarr.length);
        bos.close();
    }
}
