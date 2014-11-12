#include "eCorner.h"
#include "motor_setting.h"

extern struct E_CORNER ecorner[4];

void init_ecorner(struct E_CORNER *ecorner, unsigned long ecorn_n) {
	// Motor
	ecorner->motor.frontORleft = 0;
	ecorner->motor.backORright = 0xffffffff;
	ecorner->motor.period = PERIOD_50MHZ;
	ecorner->motor.motor_d = 2 * ecorn_n;

	ecorner->motor.enable = ENABLE_BOTH;

	// Servo
	ecorner->servo.frontORleft = 0;
	ecorner->servo.backORright = 0xffffffff;
	ecorner->servo.period = PERIOD_50MHZ;
	ecorner->servo.motor_d = 2 * ecorn_n + 1;

	ecorner->servo.enable = ENABLE_BOTH;
}

void ecorn_set_motor(unsigned char duty, unsigned char dir, int e) {
	motor_setting(DUTY_50HZ(duty & dir), DUTY_50HZ(duty & (~dir)), ecorner[e].motor.period,
			ecorner[e].motor.enable, ecorner[e].motor.motor_d);
	ecorner[e].motor.duty = duty;
	ecorner[e].motor.dir = dir;
}

void ecorn_set_servo(unsigned char duty, unsigned char dir, int e) {
	motor_setting(DUTY_50HZ(duty & dir), DUTY_50HZ(duty & (~dir)), ecorner[e].servo.period,
			ecorner[e].servo.enable, ecorner[e].servo.motor_d);
	ecorner[e].servo.duty = duty;
	ecorner[e].servo.dir = dir;
}


