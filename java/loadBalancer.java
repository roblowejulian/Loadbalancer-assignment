
loadbalancer.java
import java.net.*;
import java.io.*;

public class loadBalancer{
		public static void main(String []args)throws IOException{
		ServerSocket s1=new ServerSocket(1234);
		while(true){
			Socket socketcon=s1.accept();
			BufferedReader packetfromclient=new BufferedReader(new InputStreamReader(socketcon.getInputStream()));
			String clientpacket=packetfromclient.readLine();

			if(clientpacket.contains("Boy")){
			Socket s1=new Socket("192.168.36.128",2345);
			DataOutputStream toserver=new DataOutputStream(s1.getOutputStream());
			outtoserver.writeBytes(clientpacket+"\n");
			s1.close();
			}

			else if(clientpacket.contains("Girl")){
			Socket s2=new Socket("192.168.36.129",2346);
			DataOutputStream toserver2=new DataOutputStream(s2.getOutputStream());
			toserver2.writeBytes(clientpacket+"\n");
			server2.close();
			}

			else{System.ou.println(ERROR!);}
			}
		}
}
