/*

 ^
 | front
 |
 |

 +---+       +---+
 | 3 |_______| 0 |
 |   |       |   |
 +---+       +---+
 |           |
 |           |
 |           |
 |           |
 +---+       +---+
 | 2 |_______| 1 |
 |   |       |   |
 +---+       +---+

 */

#include "motor_setting.h"

void move_forward(unsigned long motor_duty) {
	motor_setting(DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_0);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_1);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_2);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_3);
}

void move_backward(unsigned long motor_duty) {

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_0);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_1);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_2);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(0), PERIOD_50MHZ, ENABLE_BOTH,
			SERVO_3);
}

void front_left(unsigned long motor_duty, unsigned long servo_duty) {

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);
}

void front_right(unsigned long motor_duty, unsigned long servo_duty) {

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);
}

void back_left(unsigned long motor_duty, unsigned long servo_duty) {

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(servo_duty), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);
}

void back_right(unsigned long motor_duty, unsigned long servo_duty) {

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(servo_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);
}

void spin_clockwise(unsigned long motor_duty) {

	// MS0: b,l
	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(DUTY_FULL), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	// MS1: b,r
	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(DUTY_FULL), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	// MS2: f,l
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(DUTY_FULL), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	// MS3: f,r
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(DUTY_FULL), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);

}

void spin_counterclockwise(unsigned long motor_duty) {

	// MS0: f,l
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_0);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(DUTY_FULL), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_0);

	// MS1: f,r
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(motor_duty), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_1);
	motor_setting( DUTY_50HZ(DUTY_FULL), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_1);

	// MS2: b,l
	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_2);
	motor_setting( DUTY_50HZ(0), DUTY_50HZ(DUTY_FULL), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_2);

	// MS3: b,r
	motor_setting( DUTY_50HZ(motor_duty), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, MOTOR_3);
	motor_setting( DUTY_50HZ(DUTY_FULL), DUTY_50HZ(0), PERIOD_50MHZ,
			ENABLE_BOTH, SERVO_3);

}
