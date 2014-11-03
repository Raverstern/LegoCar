#ifndef _PROTOCAL_H
#define _PROTOCAL_H

// Package type
#define CTRL 0x1
#define DATA 0x2
#define ACK 0x3

// Subtype for CTRL
#define CTRL_TEST 0x0
#define CTRL_UPDATE 0x1
#define CTRL_STOP 0x2

// Motor & Servo
#define MOTOR 0x0
#define SERVO 0x1


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

#endif /* _PROTOCAL_H */


