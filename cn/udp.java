 //5. Implementation of UDP Socket (UDP Server and UDP Client)

//UDP SERVER

import java.io.*;

import java.net.*;

class udp

{

public static void main(String args[]) throws Exception

{

DatagramSocket serverSocket = new DatagramSocket(9876);

byte[] receiveData = new byte[1024];

byte[] sendData = new byte[1024];

while(true)

{

DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

serverSocket.receive(receivePacket);

String sentence = new String( receivePacket.getData());

System.out.println("RECEIVED: " + sentence);

InetAddress IPAddress = receivePacket.getAddress();

int port = receivePacket.getPort();

String capitalizedSentence = sentence.toUpperCase();

sendData = capitalizedSentence.getBytes();

DatagramPacket sendPacket =new

DatagramPacket(sendData, sendData.length, IPAddress, port);

serverSocket.send(sendPacket);

}

}

}

//UDP CLIENT
class UDPClient

{

public static void main(String args[]) throws Exception

{

BufferedReader inFromUser =

new BufferedReader(new InputStreamReader(System.in));

DatagramSocket clientSocket = new DatagramSocket();

InetAddress IPAddress = InetAddress.getByName("localhost");

byte[] sendData = new byte[1024];

byte[] receiveData = new byte[1024];

String sentence = inFromUser.readLine();

sendData = sentence.getBytes();

DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length,

IPAddress,

9876);

clientSocket.send(sendPacket);

DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

clientSocket.receive(receivePacket);

String modifiedSentence = new String(receivePacket.getData());

System.out.println("FROM SERVER:" + modifiedSentence);

clientSocket.close();

}

}