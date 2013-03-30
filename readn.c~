#include "unp.h"

ssize_t readn(int fd,void *vptr,size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;
	ptr = vptr;
	nleft = n;
	while(nleft>0)
	{
		if((nread = read(fd,ptr,nleft))<0)
		{
			if(errno == EINTR)
				nread = 0;
			else
				return -1;
		}
		else if(nread ==0)
			break;
		nleft -= nread;
		ptr += nread;
	}
	return n-nleft;
}

ssize_t writen(int fd,void *vptr,size_t n)
{
	size_t nleft;
	ssize_t nwrite;
	char *ptr;
	ptr = vptr;
	nleft = n;
	while(nleft>0)
	{
		if((nwrite = write(fd,ptr,nleft))<=0)
		{
			if(nwrite<0 && errno == EINTR)
				nwrite = 0;
			else
				return -1;
		}
		nleft -= nwrite;
		ptr += nwrite;
	}
	return n;
}

ssize_t readline(int fd,void *vptr,size_t maxlen)
{
	ssize_t n,rc;
	char c,*ptr;
	ptr = vptr;
	for(n=1;n<maxlen;n++)
	{
again:
		if((rc = read(fd,&c,1))==1)
		{
			*ptr++ = c;
			if(c=='\n')
				break;
		}
		else if(rc==0)
		{
			*ptr = 0;
			return n-1;
		}
		else
		{
			if(errno==EINTR)
				goto again;
			return -1;
		}
	}
	*ptr=0;
	return n;
}
