#ifndef _CONNECT_H_
#define _CONNECT_H_

#include "ball.h"

int socketfd;
char connected;


int init_conn(void);
void listening(struct ball *ball, char *msg);


#endif