#include <arpa/inet.h>
#include <sys/errno.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int Socket(int family, int type, int protocal){
	int n;
	
	if( (n = socket(family, type, protocal)) < 0){
		fprintf(stderr, "%s:%d: Socket(): %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	
	return n;
}

void Inet_pton(int family, const char *strptr, void *addrptr){
	int n;

	if ( (n = inet_pton(family, strptr, addrptr)) < 0){
		fprintf(stderr, "%s:%d: Inet_pton(): %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	else if (n == 0){
		fprintf(stderr, "%s:%d: Inet_pton(): unvalid string\n", __FILE__, __LINE__);
		exit(1);
	}
}

void Connect(int sockfd, const struct sockaddr *servaddr, socklen_t addrlen){
	if (connect(sockfd, servaddr, addrlen) < 0){
		fprintf(stderr, "%s:%d: Connect(): %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
}

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

int Mkfifo(const char *pathname, mode_t mode){
	if ( (mkfifo(pathname, mode) < 0) && (errno != EEXIST)){
		fprintf(stderr, "%s:%d: Mkfifo(): %s\n", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}
	return 0;
}


