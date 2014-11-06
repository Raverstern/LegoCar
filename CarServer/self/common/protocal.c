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
		fprintf(stderr, "test: %X-%X-%X-%X\n", testpck->all[3],testpck->all[2],testpck->all[1],testpck->all[0]);
		fprintf(stderr, "ack: %X-%X-%X-%X\n", ackpck->all[3],ackpck->all[3],ackpck->all[1],ackpck->all[0]);
		fprintf(stderr, "%s:%d: check_test_ack(): Packet mismatched\n", __FILE__, __LINE__);
		exit(1);
	}
}

int is_ctrl(packet_t *pck) {
	return (pck->ctrlpck.type == CTRL) ? 1 : 0;
}

int is_ctrl_stop(packet_t *pck) {
	if (pck->ctrlpck.type == CTRL && pck->ctrlpck.subtype == CTRL_STOP)
		return 1;
	else
		return 0;
}

int is_ctrl_update(packet_t *pck) {
	if (pck->ctrlpck.type == CTRL && pck->ctrlpck.subtype == CTRL_UPDATE)
		return 1;
	else
		return 0;
}

int is_ctrl_test(packet_t *pck) {
	if (pck->ctrlpck.type == CTRL && pck->ctrlpck.subtype == CTRL_TEST)
		return 1;
	else
		return 0;
}

int is_data(packet_t *pck){
	return (pck->datapck.type == DATA) ? 1 : 0;
}

int is_heartbeat(packet_t *pck){
	return (pck->ctrlpck.type == HEARTBEAT) ? 1 : 0;
}


