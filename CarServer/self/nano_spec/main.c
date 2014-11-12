#include "header.h"

#ifndef TEST

static alt_alarm timer;
alt_u32 ticks_num = 400;

int glb;

alt_u32 timer_CallBack(void *context) {
	//Send Ack packet
	packet_t pck = { .ctrlpck.type = HEARTBEAT };
	glb++;
	Writen(*(int *) context, &pck, sizeof(pck));
	return ticks_num; //period for next ISR
}

struct E_CORNER ecorner[4];

int main() {
	//struct MOTOR motor = { .front = 1000 };
	int fp = open("/dev/uart", O_RDWR); //Open file for reading and writing
	packet_t rdpck, wrpck;
	int i;

	for (i = 0; i < 4; ++i)
		init_ecorner(&ecorner[i], i);

	//printf("mark1\n");
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0xff);

	if (fp >= 0) {
		//printf("mark2\n");
		alt_alarm_start(&timer, ticks_num, timer_CallBack, &fp);

		while (!is_ctrl_stop(&rdpck)) { // Loop until we receive a stop packet.
			//printf("looping...\n");
			//printf("i = %d\n", glb);
			while (Readn(fp, &rdpck, sizeof(rdpck)) != sizeof(rdpck)); // Get messages from the UART, blocking.
			//printf("mark3\n");
			//printf("rdpck: %X-%X-%X-%X\n", rdpck.all[3],rdpck.all[2],rdpck.all[1],rdpck.all[0]);

			if (is_ctrl_test(&rdpck)) { // Response for coming packet: test
				IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x01);
				set_packet_ack(&wrpck, rdpck.ctrlpck.seq_num);
				//printf("ack: %X-%X-%X-%X\n", wrpck.all[3],wrpck.all[3],wrpck.all[1],wrpck.all[0]);
				Writen(fp, &wrpck, sizeof(wrpck));
			} else if (is_ctrl_update(&rdpck)) { // Response for coming packet: update
				IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x02);
				for (i = 0; i < 4; ++i) {
					ecorn_set_motor(ecorner[i].motor.duty_tmp,
							ecorner[i].motor.dir_tmp, i);
					ecorn_set_servo(ecorner[i].servo.duty_tmp,
							ecorner[i].servo.dir_tmp, i);
				}
			} else if (is_data(&rdpck)) { // Response for coming packet: data
				IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x04);
				//printf("ecorn_n:%d m_s:%d dir:%d duty:%d\n",
				//		rdpck.datapck.ecorn_n, rdpck.datapck.m_s,
				//		rdpck.datapck.dir, rdpck.datapck.duty);
				if (rdpck.datapck.m_s == SEL_MOTOR) {
					ecorner[rdpck.datapck.ecorn_n].motor.duty_tmp =
							rdpck.datapck.duty;
					ecorner[rdpck.datapck.ecorn_n].motor.dir_tmp =
							rdpck.datapck.dir;
				} else if (rdpck.datapck.m_s == SEL_SERVO) {
					ecorner[rdpck.datapck.ecorn_n].servo.duty_tmp =
							rdpck.datapck.duty;
					ecorner[rdpck.datapck.ecorn_n].servo.dir_tmp =
							rdpck.datapck.dir;
				}
			}
		}

		// Clean up before halt
		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x08);
		alt_alarm_stop(&timer); // stop timer first
		set_packet_ack(&wrpck, rdpck.ctrlpck.seq_num);
		Writen(fp, &wrpck, sizeof(wrpck));
		for (i = 0; i < 4; ++i) { // stop and turn wheels ahead
			ecorn_set_motor(0, ecorner[i].motor.dir_tmp, i);
			ecorn_set_servo(0, ecorner[i].servo.dir_tmp, i);
		}

		//printf("i = %d\n", glb);
		printf("System Halt!\n");
		close(fp);
	}

	return 0;
}

#else

#include <stdio.h>
#include "system.h"
#include "movement.h"
#include "altera_avalon_pio_regs.h"
#include "unistd.h"

int main() {
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x0);

	while (1) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x01);
		move_forward(80);
		printf("move_forward80\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x02);
		move_forward(50);
		printf("move_forward50\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x04);
		front_left(80, 100);
		printf("front_left\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x08);
		front_right(80, 100);
		printf("front_right\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x10);
		back_left(80, 100);
		printf("back_left\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x20);
		back_right(80, 100);
		printf("back_right\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x40);
		spin_clockwise(100);
		printf("spin_clockwise\n");
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x80);
		spin_counterclockwise(100);
		printf("spin_counterclockwise\n");
		usleep(3000000);
	}

	return 0;
}

#endif /*TEST*/

