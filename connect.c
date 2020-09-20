
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "connect.h"


#define ADDRESS "192.168.15.6"
#define PORT 5001

int socketfd;
char connected = 0;

char serv_msg[6];

int init_conn(void){

	char serv_msg[50];
	memset(&serv_msg, 0, sizeof(serv_msg));

	struct sockaddr_in servaddr, cli;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket: %d\n", socketfd);

	//IP e PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(ADDRESS);
	servaddr.sin_port = htons(PORT);

	if (connect(socketfd, (struct sockaddr*) &servaddr, sizeof(servaddr))==0)
		connected = 1;
	else
		printf("Não conectou\n");

	printf("%zu\n", recv(socketfd, serv_msg, 50, 0));
	
	//recv(socketfd, serv_msg, 10, 0);

	printf("%s\n", serv_msg);

	return 0;
}

void listening(struct ball *ball, char *msg){

	send(socketfd, msg, 1, 0);
	recv(socketfd, serv_msg, 3, 0);

	printf("msg: %d\n", atoi(serv_msg));
	ball->bball.x = atoi(serv_msg);
	

}