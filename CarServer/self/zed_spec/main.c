#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libconfig.h> // need "-lconfig" when compiling
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include "wrap.h"
#include "../common/protocal.h"
#include "../common/eCorner.h"

void cleanup(int dummy);
void network_test(int sockfd, long sec);
void init_DE0(void);

int sockfd;

int main(void){
	int fifofd, maxfd;
	struct sockaddr_in DE0addr;
	packet_t wrpck, rdpck, datapck[4], updatepck;
	config_t cfg;
	//config_setting_t *setting;
	const char *boardaddr;
	int boardport;
	fd_set rfds, rfd; // read file descriptor set
	time_t conn_time;
	int pckcount = 0, i;

	config_init(&cfg);
	config_read_file(&cfg, "board.cfg");
	config_lookup_string(&cfg, "Board.[0].Address", &boardaddr);
	config_lookup_int(&cfg, "Board.[0].Port", &boardport);
	

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&wrpck, sizeof(wrpck));
	bzero(&DE0addr, sizeof(DE0addr));
	FD_ZERO(&rfds);
	DE0addr.sin_family = AF_INET;
	DE0addr.sin_port = htons(boardport);

	Inet_pton(AF_INET, boardaddr, &DE0addr.sin_addr);
	Connect(sockfd, (struct sockaddr *) &DE0addr, sizeof(DE0addr));
	network_test(sockfd, 10);
	init_DE0();
	signal(SIGINT, cleanup);
	signal(SIGTERM, cleanup);

	Mkfifo(FIFO, FILE_MODE);
	printf("mark fifo\n");
	fifofd = open(FIFO, O_RDONLY);
	printf("mark fifo ok\n");
	FD_SET(fifofd, &rfds);
	FD_SET(sockfd, &rfds);
	maxfd = fifofd > sockfd ? fifofd : sockfd;

	set_packet_ctrl(&updatepck, CTRL_UPDATE);
	conn_time = time(NULL) + 1;
	while (1){
		printf("looping...\n");
		if (conn_time < time(NULL)){ // Time has elapsed 1s from last check
			if (pckcount <= 0){
				// Connection Problem
				fprintf(stderr, "Connection timeout, try connect again\n");
				FD_ZERO(&rfd);
				FD_SET(sockfd, &rfd);
				select(sockfd+1, &rfd, NULL, NULL, NULL);
				//Connect(sockfd, (struct sockaddr *) &DE0addr, sizeof(DE0addr));
				//maxfd = fifofd > sockfd ? fifofd : sockfd;
			}	
			printf("pckcount = %d\n", pckcount);
			pckcount = 0;
			conn_time = time(NULL); // Reset timer
		}
		rfd = rfds;
		select(maxfd+1, &rfd, NULL, NULL, NULL);

		// Handle message from DE0
		// for now, just add counter after receiving heartbeat packet
		if (FD_ISSET(sockfd, &rfd)){
			Readn(sockfd, &rdpck, sizeof(rdpck));
			if (is_heartbeat(&rdpck)){
				printf("heart\n");
				pckcount++;
			}
		}
		// Handle message from UI process
		// for now, just forward the packet directly to DE0
		if (FD_ISSET(fifofd, &rfd)){ 
			read(fifofd, &wrpck, sizeof(wrpck));
			if (wrpck.all[0] == 'u'){
				for (i = 0; i < 4; ++i)
					set_packet_data(&datapck[i], i, SEL_MOTOR, 100, FRONT);
			}
			else if (wrpck.all[0] == 'd'){
				for (i = 0; i < 4; ++i)
					set_packet_data(&datapck[i], i, SEL_MOTOR, 100, BACK);
			}
			else if (wrpck.all[0] == 'r'){
				for (i = 0; i < 4; ++i)
					set_packet_data(&datapck[i], i, SEL_SERVO, 100, RIGHT);
			}
			else if (wrpck.all[0] == 'l'){
				for (i = 0; i < 4; ++i)
					set_packet_data(&datapck[i], i, SEL_SERVO, 100, LEFT);
			}
			printf("fifo: %c-%c-%c-%c\n", wrpck.all[3],wrpck.all[2],wrpck.all[1],wrpck.all[0]);
			for (i = 0; i < 4; ++i){
				Writen(sockfd, &datapck[i], sizeof(datapck[i]));
				printf("ecorn_n:%d m_s:%d dir:%d duty:%d\n", datapck[i].datapck.ecorn_n, datapck[i].datapck.m_s, datapck[i].datapck.dir, datapck[i].datapck.duty);
			}
			Writen(sockfd, &updatepck, sizeof(updatepck));
		}
	}
	

	return 0;
};

void cleanup(int sig_num){
	packet_t wrpck, rdpck;

	if (sig_num == SIGTERM)
		printf("Caught signal: SIGTERM, terminating...\n");
	else if (sig_num == SIGINT)
		printf("Caught signal: SIGINT, stopping...\n");

	set_packet_ctrl(&wrpck, CTRL_STOP);
	Writen(sockfd, &wrpck, sizeof(wrpck));
	unlink(FIFO);
	printf("Server Halt!\n");
	exit(0);
}

void network_test(int sockfd, long sec){
	packet_t wrpck, rdpck;
	fd_set rfd;
	struct timeval timeout = {
		.tv_sec = sec,
		.tv_usec = 0
	};
	int n;

	FD_ZERO(&rfd);
	FD_SET(sockfd, &rfd);

	set_packet_ctrl(&wrpck, CTRL_TEST);
	Writen(sockfd, &wrpck, sizeof(wrpck));
	if ( (n = select(sockfd+1, &rfd, NULL, NULL, &timeout)) < 0){
		fprintf(stderr, "%s:%d: select(): Network testing error\n", __FILE__, __LINE__);
		exit(1);
	}
	else if (n == 0){
		fprintf(stderr, "%s:%d: select(): Connection timeout\n", __FILE__, __LINE__);
		exit(1);
	}

	Readn(sockfd, &rdpck, sizeof(rdpck));
	check_test_ack(&wrpck, &rdpck);
}

void init_DE0(void){
	packet_t wrpck;
	int i;

	for (i = 0; i < 4; ++i){
		set_packet_data(&wrpck, i, SEL_MOTOR, 0, FRONT);
		Writen(sockfd, &wrpck, sizeof(wrpck));
		set_packet_data(&wrpck, i, SEL_SERVO, 0, RIGHT);
		Writen(sockfd, &wrpck, sizeof(wrpck));
	}
}



