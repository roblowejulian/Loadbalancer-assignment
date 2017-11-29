#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(){
	int socketdesc,client_socket,c,read_size,ssocket1,ssocket2;
	struct sockaddr_in loadbalancer,client,s1,s2;
	char packetfromclient[3000];

	//create socket
	socketdesc=socket(AF_INET,SOCK_STREAM,0);
	if(socketdesc==-1){
		printf("cant create socket");
	}
	puts("loadbalancer socket created");
	
	//prepare the sockaddr_in structure
	lb.sin_family=AF_INET;
	lb.sin_addr.s_addr=INADDR_ANY;
	lb.sin_port=htons(1000);
	
	//bind
	if(bind(socketdesc,(struct sockaddr *)&lb,sizeof(lb))<0){
	perror("fail to bind the socket to server");
	return 1;
	}
	
	puts("bind done");

	//listen to the client
	listen(socketdesc,3);

	//wait for incoming connection
	puts("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);

	//accept connection from incoming client
	client_socket=accept(socketdesc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(client_socket<0){
	perror("accept failed");
	return 1;
	}
	puts("connection accepted");

	read_size=recv(client_socket,packetfromclient,3000,0);
	
	if(strcmp(packetfromclient,"girl")==0){

		//create socket for server1
		ssocket1=socket(AF_INET,SOCK_STREAM,0);
		s1.sin_family=AF_INET;
		s1.sin_addr.s_addr=inet_addr("192.168.36.128");
		s1.sin_port=htons(3000);
		if(connect(ssocket1,(struct sockaddr *)&s1,sizeof(s1))<0){
		perror("fail to connect to loadbalancer");
		return 1;
		}

		if(send(ssocket1,packetfromclient,strlen(packetfromclient),0)<0){
		puts("fail to send");
		return 1;
		}
	close(ssocket1);
	}else if(strcmp(packetfromclient,"boy")==0){

		//create socket for server2
		ssocket2=socket(AF_INET,SOCK_STREAM,0);
		s2.sin_family=AF_INET;
		s2.sin_addr.s_addr=inet_addr("192.168.36.129");
		s2.sin_port=htons(4000);
		if(connect(ssocket2,(struct sockaddr *)&s2,sizeof(s2))<0){
		perror("fail to connect to loadbalancer");
		return 1;
		}

		if(send(ssocket2,packetfromclient,strlen(packetfromclient),0)<0){
		puts("fail to send");
		return 1;
		}
		close(ssocket2);	
	}else{
	printf("error!!! the message did not redirected to any server");	
	}
	
	
}
