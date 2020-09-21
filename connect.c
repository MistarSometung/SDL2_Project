
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

char serv_msg[60];
static int socketfd;


int init_conn(void){

	connected = 0;

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

	printf("%zu\n", recv(socketfd, serv_msg, sizeof(serv_msg), 0));
	

	printf("%s\n", serv_msg);

	return 0;
}

int get_ball_poss(void){
	recv(socketfd, serv_msg, 3, 0);
	printf("msg: %d\n", atoi(serv_msg));
	return atoi(serv_msg);
	
}

void listening(void){
	recv(socketfd, serv_msg, sizeof(serv_msg), 0);
	printf("%s", serv_msg);
	//send(socketfd, "0", 1, 0);
}

void hero_action(char *msg){
	send(socketfd, msg, sizeof(msg), 0);

}

