#ifndef _ECORNER_H
#define _ECORNER_H

// Macro for direction
#define FRONT 0
#define BACK 0xffffffff
#define LEFT 0
#define RIGHT 0xffffffff

struct MOTOR{
// Variables
	// Dynamic
	unsigned long duty;
	unsigned long dir;
	unsigned long duty_tmp;
	unsigned long dir_tmp;

        // Seldomly changed
	unsigned long enable;

	// Constant, must be set in definition
	const unsigned long frontORleft; // = 0
	const unsigned long backORright; // = 0xffffffff
	const unsigned long motor_d;
	const unsigned long period;
};

struct E_CORNER{
	struct MOTOR* const motor;
	struct MOTOR* const servo;
};

#endif /* _ECORNER_H */

