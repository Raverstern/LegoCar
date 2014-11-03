#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <libconfig.h> // need "-lconfig" when compiling
#include "wrap.h"
#include "protocal.h"

int main(void){
	int sockfd;
	//char buf[BUF_SIZE];
	struct sockaddr_in DE0addr;
	packet_t wrtpck, rdpck;
	config_t cfg;
	//config_setting_t *setting;
	const char *boardaddr;
	int boardport;

	config_init(&cfg);
	config_read_file(&cfg, "board.cfg");
	config_lookup_string(&cfg, "Board.[0].Address", &boardaddr);
	config_lookup_int(&cfg, "Board.[0].Port", &boardport);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&wrtpck, sizeof(wrtpck));
	bzero(&DE0addr, sizeof(DE0addr));
	DE0addr.sin_family = AF_INET;
	DE0addr.sin_port = htons(boardport);

	Inet_pton(AF_INET, boardaddr, &DE0addr.sin_addr);
	
	Connect(sockfd, (struct sockaddr *) &DE0addr, sizeof(DE0addr));

	// Testing Network Connection
	set_packet_ctrl(&wrtpck, CTRL_TEST);
	Writen(sockfd, &wrtpck, sizeof(wrtpck));
	Readn(sockfd, &rdpck, sizeof(rdpck));
	check_test_ack(&wrtpck, &rdpck);
	
	//
	

	return 0;
};


