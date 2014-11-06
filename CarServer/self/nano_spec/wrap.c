#include <sys/errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t Writen(int sockfd, const void *buf, size_t nbytes){
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr = buf;
	nleft = nbytes;
	
	while (nleft > 0){
		if ( (nwritten = write(sockfd, ptr, nbytes)) <= 0) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;
			else {
				fprintf(stderr, "%s:%d: Writen(): %s\n", __FILE__, __LINE__, strerror(errno));
				exit(1);
			}
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return nbytes;
}

ssize_t Readn(int sockfd, void *buf, size_t nbytes){
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = buf;
	nleft = nbytes;

	while (nleft > 0){
		if ( (nread = read(sockfd, ptr, nleft)) < 0){
			printf("nread: %d", nread);
			if (errno == EINTR)
				nread = 0; // and will read() again
			else{
				fprintf(stderr, "%s:%d: Readn(): %s\n", __FILE__, __LINE__, strerror(errno));
				exit(1);
			}
		} else if (nread == 0)
			break; // EOF
		nleft -= nread;
		ptr += nread;
	}
	return (nbytes - nleft);
}


