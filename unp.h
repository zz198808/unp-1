#ifndef UNP_H
#define UNP_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h> //socket();
#include<netinet/in.h> //struct sockaddr_in
#include<sys/wait.h>
#include<signal.h>

#define SERV_PORT 9877
#define MAXLINE   80
#endif
