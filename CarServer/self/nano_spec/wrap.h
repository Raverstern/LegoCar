#ifndef _WRAP_H
#define _WRAP_H

ssize_t Writen(int sockfd, const void *buff, size_t nbytes);

ssize_t Readn(int sockfd, void *buf, size_t nbytes);

#endif /* _WRAP_H */


