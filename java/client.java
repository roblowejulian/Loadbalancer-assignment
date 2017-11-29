import java.io.*;
import java.net.*;

public class client{
	public static void main(String []args) throws IOException{
		Socket client=new Socket("192.168.38.129",1234);
		DataOutputStream toserver=new DataOutputStream(client.getOutputStream());
		BufferedReader usrinput=new BufferedReader(new InputStreamReader(System.in));
		String packet=usrinput.readLine();
		toserver.writeBytes(packet);
		client.close();
}
	
}
