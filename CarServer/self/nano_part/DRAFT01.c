/*

TODO: Add these content to motor_setting.c, and correspondingly modify motor_setting.h

*/

void set_motor(unsigned long duty, unsigned dir, int e){
	motor_setting(duty&dir, duty&(~dir), ecorn[e]->motor.period,
		ecorn[e]->motor.enable, ecorn[e]->motor.motor_d);
	ecorn[e]->motor.duty = duty;
	ecorn[e]->motor.dir = dir;
}

void set_servo(unsigned long duty, unsigned dir, int e){
	motor_setting(duty&dir, duty&(~dir), ecorn[e]->motor.period,
		ecorn[e]->motor.enable, ecorn[e]->motor.motor_d);
	ecorn[e]->servo.duty = duty;
	ecorn[e]->servo.dir = dir;
}

void init(unsigned long period, unsigned long enable, unsigned long motor_d){
	motor_setting(0, 0, period, enable, motor_d);
}

#define init(period, enable, motor_d) \
	motor_setting(0, 0, (period), (enable), (motor_d))

