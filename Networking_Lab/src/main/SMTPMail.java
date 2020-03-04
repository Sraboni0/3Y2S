package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class SMTPMail {
    public static void main(String[] args) throws IOException {

        Socket ss= new Socket("localhost",25);
        PrintWriter os = new PrintWriter(ss.getOutputStream(),true);
        BufferedReader br = new BufferedReader(new InputStreamReader(ss.getInputStream()));

        os.println("HELO "+ "example.com");
        System.out.println("Response1: "+br.readLine());

        os.println("MAIL FROM: "+"aa@abcd.com");
        System.out.println("Response2: "+br.readLine());

        os.println("RCPT TO: "+"ijdfas@abcd.com");
        System.out.println("Response3: "+br.readLine());

        os.println("DATA");
        System.out.println("Response4: "+ br.readLine());

        os.println("Subject: My message");
        os.println();
        os.println("Hello Bangladesh.");
        os.println();
        os.println(".");

        System.out.println("Response5: "+br.readLine());
        os.println("QUIT");

        System.out.println("Response5: "+br.readLine());
        System.out.println("Response5: "+br.readLine());
    }
}
