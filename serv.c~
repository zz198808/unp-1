#include "unp.h"

int str_echo(int fd)
{
	ssize_t n;
	char buf[MAXLINE];
again:
	while( (n = read(fd,buf,MAXLINE))>0 )
	{
		writen(fd,buf,n);
	}
	if(n<0 && errno == EINTR)
		goto again;
	else if(n<0)
		perror("str_echo:read error");
}

int main(int argc,char **argv)
{
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;

	listenfd = Socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(listenfd,&servaddr,sizeof(servaddr));
	Listen(listenfd,20);

	printf("server is listening\n");

	for(;;)
	{
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd,&cliaddr,&clilen);
		if( (childpid = Fork() == 0) )
		{
			Close(listenfd);	
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
