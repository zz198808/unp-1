#include "unp.h"

void str_cli(FILE *fp,int sockfd)
{
	char sendline[MAXLINE],recvline[MAXLINE];
	while(fgets(sendline,MAXLINE,fp)!=NULL)
	{
		writen(sockfd,sendline,strlen(sendline));
		if(readline(sockfd,recvline,MAXLINE)==0)
		{
			perror("str_cli:error");
			exit(1);
		}
		fputs(recvline,stdout);
	}
}

int main(int argc,char **argv) {
	struct sockaddr_in servaddr;
	int sockfd;

	if(argc!=2)
	{
		printf("Usage: ./cli <ip>");
		exit(1);
	}
	
	sockfd = Socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

	Connect(sockfd,&servaddr,sizeof(servaddr));

	str_cli(stdin,sockfd);
	exit(0);
}
