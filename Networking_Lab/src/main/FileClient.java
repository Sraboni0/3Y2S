package main;

import java.io.*;
import java.net.Socket;

public class FileClient {
    public static void main(String[] args) throws IOException {
        Socket soc = new Socket("localhost",3333);
        String FileName = "abc.txt";
        File myfile = new File(FileName);

        int FizeSize = (int)myfile.length();

        OutputStream os = soc.getOutputStream();
        PrintWriter pr = new PrintWriter(soc.getOutputStream(),true);

    }
}
