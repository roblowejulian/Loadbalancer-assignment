#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int sck;
	struct sckaddr_in server;
	char packet[3000];
	
	//create socket
	sck=socket(AF_INET,SOCK_STREAM,0);
	if(sck==-1){
	   printf("could not create socket");
	}
	puts("socket created");
	//socket specification
	server.sin_addr.s_addr=inet_addr("192.168.38.129");
	server.sin_family=AF_INET;
	server.sin_port=htons(1000);

	//connect to server
	if(connect(sck,(struct sckaddr *)&server,sizeof(server))<0){
		perror("fail to connect to loadbalancer");
		return 1;
	}

	printf("enter your message");
	scanf("%s",packet);
	if(send(sck,packet,strlen(packet),0)<0){
	puts("fail to send");
	return 1;
	}
	close(sck);
return 0;
}
