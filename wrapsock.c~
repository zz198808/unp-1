#include "unp.h"

int Socket(int family,int type,int protocol)
{
	int ret = socket(family,type,protocol);
	if(ret < 0)
	{
		perror("socket error");
		exit(1);
	}
	return ret;
}

int Connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen)
{
	int ret = connect(sockfd,servaddr,addrlen);
	if(ret < 0)
	{
		perror("connect error");
		exit(1);
	}
	return ret;
}

int Bind(int sockfd,const struct sockaddr *myaddr,socklen_t addrlen)
{
	int ret = bind(sockfd,myaddr,addrlen);
	if(ret<0)
	{
		perror("bind error");
		exit(1);
	}
	return 0;
}

int Listen(int sockfd,int backlog)
{
	int ret = listen(sockfd,backlog);
	if(ret<0)
	{
		perror("listen error");
		exit(1);
	}
	return 0;
}

int Accept(int sockfd,struct sockaddr *cliaddr,socklen_t *addrlen)
{
	int ret = accept(sockfd,cliaddr,addrlen);
	if(ret<0)
	{
		perror("accept error");
		exit(1);
	}
	return 0;
}

int Fork()
{
	int ret = fork();
	if(ret<0)
	{
		perror("fork error");
		exit(1);
	}
	return ret;
}

int Close(int fd)
{
	int ret = close(fd);
	if(ret<0)
	{
		perror("close error");
		exit(1);
	}
	return ret;
}
