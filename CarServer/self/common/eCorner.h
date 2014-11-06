#ifndef _ECORNER_H
#define _ECORNER_H

// Macro for direction
#define FRONT 0
#define BACK 0xffffffff
#define LEFT 0
#define RIGHT 0xffffffff

struct MOTOR{
	unsigned long duty; // state value, shouldn only be modified by API: set_motor() or set_servo()
	unsigned long dir; // state value, shouldn only be modified by API: set_motor() or set_servo()
	unsigned long duty_tmp;
	unsigned long dir_tmp; // should only be 0 or 0xffffffff

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
void ecorn_set_motor(unsigned long duty, unsigned dir, int e);
void ecorn_set_servo(unsigned long duty, unsigned dir, int e);

#endif /* _ECORNER_H */


