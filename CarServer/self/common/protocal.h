#ifndef _PROTOCAL_H
#define _PROTOCAL_H

// Package type
#define CTRL 0x1
#define DATA 0x2
#define ACK 0x3
#define HEARTBEAT 0x4

// Subtype for CTRL
#define CTRL_TEST 0x0
#define CTRL_UPDATE 0x1
#define CTRL_STOP 0x2

// Motor & Servo
#define SEL_MOTOR 0x0
#define SEL_SERVO 0x1


typedef union PACKET{
	struct {
		unsigned int type : 4;
		unsigned int subtype : 4;
		unsigned char seq_num;
		unsigned char undefined[2];
	}ctrlpck;
	struct {
		unsigned int type : 4;
		unsigned int ecorn_n : 2;
		unsigned int m_s : 2;
		unsigned char seq_num;
		unsigned char duty;
		unsigned char dir;
	}datapck;
	unsigned char all[4];
} packet_t;


void set_packet_ctrl(packet_t *pckptr, unsigned int subtype);
void set_packet_data(packet_t *pckptr, unsigned int ecorn_n, unsigned int m_s, unsigned char duty, unsigned char dir);
void set_packet_ack(packet_t *pckptr, unsigned char seq_num);

void check_test_ack(packet_t *testpck, packet_t *ackpck);

int is_ctrl(packet_t *pck);
int is_ctrl_stop(packet_t *pck);
int is_ctrl_update(packet_t *pck);
int is_ctrl_test(packet_t *pck);

int is_data(packet_t *pck);
int is_heartbeat(packet_t *pck);

#endif /* _PROTOCAL_H */



