#ifndef _ECORNER_H
#define _ECORNER_H

// Macro for direction
#define FRONT 0
#define BACK 0xff
#define LEFT 0
#define RIGHT 0xff

struct MOTOR{
	unsigned char duty; // state value, shouldn only be modified by API: set_motor() or set_servo()
	unsigned char dir; // state value, shouldn only be modified by API: set_motor() or set_servo()
	unsigned char duty_tmp;
	unsigned char dir_tmp; // should only be 0 or 0xffffffff

	unsigned long enable;

	unsigned long frontORleft; // constant, should be 0
	unsigned long backORright; // constant, should be 0xffffffff
	unsigned long motor_d;
	unsigned long period;
};

struct E_CORNER{
	struct MOTOR motor;
	struct MOTOR servo;
};

void init_ecorner(struct E_CORNER *ecorner, unsigned long ecorn_d);
void ecorn_set_motor(unsigned char duty, unsigned char dir, int e);
void ecorn_set_servo(unsigned char duty, unsigned char dir, int e);

#endif /* _ECORNER_H */


