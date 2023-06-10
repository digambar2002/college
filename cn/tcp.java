//5. Implementation of TCP Socket (TCP Server and TCP Client)

//TCP SERVER

import java.io.*;

import java.net.*;

class tcp

{

    public static final int PORT = 1222;

    public static void main(String a[]) throws Exception

    {

        ServerSocket s = new ServerSocket(PORT);

        System.out.println("Server Started");

        Socket c = s.accept();

        System.out.println("Connection acepted:" + c);

        BufferedReader in = new BufferedReader(new InputStreamReader(c.getInputStream()));

        PrintWriter out = new PrintWriter(new BufferedWriter(new

        OutputStreamWriter(c.getOutputStream())), true);

        String send;

        while (true)

        {

            String str = in.readLine();

            send = ("Echo:" + str);

            out.println(send);

            System.out.println("Echoing: " + str);

            if (str.equals("END"))

                break;

        }

        System.out.println("Closing server");

        c.close();

        s.close();

    }

}

// TCP CLIENT

class TCPClient

{

    public static void main(String a[]) throws Exception

    {

        Socket cp = new Socket("localhost", 1222);

        System.out.println("Client connected" + cp);

        String s1;

        BufferedReader abc = new BufferedReader(new

        InputStreamReader(cp.getInputStream()));

        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        PrintWriter out = new PrintWriter(new BufferedWriter(new

        OutputStreamWriter(cp.getOutputStream())), true);

        while (true)

        {

            System.out.println("Enter the string to sent to server");

            s1 = in.readLine();

            out.println(s1);

            String str = abc.readLine();

            System.out.println("From server:" + str);

            if (str.equals("END"))

                break;

        }

        System.out.println("Closing client");

        cp.close();

    }

}
