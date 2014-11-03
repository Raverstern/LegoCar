#include "protocal.h"
#include <stdio.h>
#include <stdlib.h>

// Sequence number for packets
unsigned char glb_seq_num;


void set_packet_ctrl(packet_t *pckptr, unsigned int subtype){
	pckptr->ctrlpck.type = CTRL;
	pckptr->ctrlpck.subtype = subtype;
	pckptr->ctrlpck.seq_num = glb_seq_num++;
}

void set_packet_data(packet_t *pckptr, unsigned int ecorn_n, unsigned int m_s, unsigned char duty, unsigned char dir){
	pckptr->datapck.type = DATA;
	pckptr->datapck.ecorn_n = ecorn_n;
	pckptr->datapck.m_s = m_s;
	pckptr->datapck.seq_num = glb_seq_num++;
	pckptr->datapck.duty = duty;
	pckptr->datapck.dir = dir;
}

void set_packet_ack(packet_t *pckptr, unsigned char seq_num){
	pckptr->ctrlpck.type = ACK;
	pckptr->ctrlpck.subtype = 0;
	pckptr->ctrlpck.seq_num = seq_num;
}

void check_test_ack(packet_t *testpck, packet_t *ackpck){
	if (testpck->ctrlpck.seq_num != ackpck->ctrlpck.seq_num){
		fprintf(stderr, "%s:%d: check_test_ack(): Network testing error\n", __FILE__, __LINE__);
		exit(1);
	}
}


