#ifndef _WRAP_H
#define _WRAP_H

#include <sys/types.h>

int Socket(int family, int type, int protocal);

void Inet_pton(int family, const char *strptr, void *addrptr);

void Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen);

ssize_t Writen(int sockfd, const void *buff, size_t nbytes);

ssize_t Readn(int sockfd, void *buf, size_t nbytes);

#endif /* _WRAP_H */


