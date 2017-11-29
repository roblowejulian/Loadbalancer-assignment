#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int socketdesc,client_sock,c,rsize;
	struct sockaddr_in server,client;
	char packetfromclient[3000];

	socketdesc=socket(AF_INET,SOCK_STREAM,0);
	if(socketdesc==-1){
		printf("cant create socket");
	}
	
	puts("socket created");
	

	s2.sin_family=AF_INET;
	s2.sin_addr.s_addr=INADDR_ANY;
	s2.sin_port=htons(4000);
	
	if(bind(socketdesc,(struct sockaddr *)&s2,sizeof(s2))<0){
	perror("fail to bind the socket to server");
	return 1;
	}
	
	puts("bind done");

	
	listen(socketdesc,3);


	puts("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);

	client_sock=accept(socketdesc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(client_sock<0){
	perror("accept failed");
	return 1;
	}
	puts("connection accepted");

	rsize=recv(client_sock,packetfromclient,3000,0);

	printf("%s",packetfromclient);
	
	
}
