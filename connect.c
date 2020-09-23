
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "connect.h"
#include <confuse.h>

char *ADDRESS;
int PORT;

char serv_msg[60];
static int socketfd;


void config(void){
	
	cfg_t *cfg;

	cfg_opt_t opts[] = {
		CFG_SIMPLE_STR ("ip", &ADDRESS),
		CFG_SIMPLE_INT ("port", &PORT),
		CFG_END()

	};

	cfg = cfg_init(opts, 0);
	cfg_parse(cfg, "CONFIG.conf");

	printf("IP: %s\n", ADDRESS);
	printf("PORT: %d\n", PORT);

	cfg_free(cfg);

}






int init_conn(void){

	config();

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

