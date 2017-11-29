server.java
import java.io.*;
import java.net.*;

public class server2{
		public static void main(String []args)throws IOException{
		ServerSocket s1=new ServerSocket(2346);
		while(true){
			Socket socketcon=s1.accept();
			BufferedReader packefromloadbalancerfromloadbalancer=new BufferedReader(new InputStreamReader(socketcon.getInputStream()));
			String packet=packefromloadbalancer.readLine();
			System.out.println("Packet from Load Balancer: "+packet);
		}
	}
}