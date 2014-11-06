/*
 * motor_setting.c
 *
 *  Created on: 07.11.2012
 *      Author: karl_ee
 *          input parameters:
 *      	phase: range from 0 to value of period
 *     		duty cycle: set to number=period*percentage of duty cycle
 *      	period: according to the freq of cpu,
 *      			normally the period should be set to the value
 *      			that makes the freq of pwm waveform to be 15 k
 *      			e.x for 50MHz, value should be 3333(0xD05)
 *      	enable:'0' represents off, '1' is on, lease significant bit is for channel 1
 *      			e.x for channel 1 on and channel 2 off, enable=0x1
 *
 */
#include "system.h"
#include "unistd.h"

/*
 *
 *         duty1 | duty2
 *       +-------+-------+
 * motor | back  | front |
 * ------+-------+-------+
 * servo | right | left  |
 *       +-------+-------+
 *
 * */
void motor_setting(unsigned long duty1, unsigned long duty2,
		unsigned long period, unsigned long enable, unsigned long motor_d) {
	unsigned long * pwm_base;
	unsigned long * pwm_en;
	unsigned long * pwm_period;
	unsigned long * pwm_phase1;
	unsigned long * pwm_phase2;
	unsigned long * pwm_duty1;
	unsigned long * pwm_duty2;

	switch (motor_d) {
	case 0:
		pwm_base = (unsigned long *) (MOTOR_0_BASE | 0x80000000); //bypass data cache
		break;
	case 1:
		pwm_base = (unsigned long *) (SERVO_0_BASE | 0x80000000);
		break;
	case 2:
		pwm_base = (unsigned long *) (MOTOR_1_BASE | 0x80000000);
		break;
	case 3:
		pwm_base = (unsigned long *) (SERVO_1_BASE | 0x80000000);
		break;
	case 4:
		pwm_base = (unsigned long *) (MOTOR_2_BASE | 0x80000000);
		break;
	case 5:
		pwm_base = (unsigned long *) (SERVO_2_BASE | 0x80000000);
		break;
	case 6:
		pwm_base = (unsigned long *) (MOTOR_3_BASE | 0x80000000);
		break;
	case 7:
		pwm_base = (unsigned long *) (SERVO_3_BASE | 0x80000000);
		break;
	}
	pwm_en = pwm_base;
	pwm_period = pwm_base + 1;
	pwm_duty1 = pwm_base + 2;
	pwm_duty2 = pwm_base + 3;
	pwm_phase1 = pwm_base + 4;
	pwm_phase2 = pwm_base + 5;

	*pwm_en = enable;
	*pwm_period = period;
	*pwm_phase1 = 0;
	*pwm_phase2 = 0;
	*pwm_duty1 = duty1;
	*pwm_duty2 = duty2;
}


/*void motor_setting_origin(unsigned long phase1, unsigned long duty1,
 unsigned long phase2, unsigned long duty2, unsigned long period,
 unsigned long enable) {
 volatile unsigned long * pwm_en = (unsigned long *) PWM_EN;
 volatile unsigned long * pwm_period = (unsigned long *) PWM_PERIOD;
 volatile unsigned long * pwm_phase1 = (unsigned long *) PWM_PHASE1;
 volatile unsigned long * pwm_phase2 = (unsigned long *) PWM_PHASE2;
 volatile unsigned long * pwm_duty1 = (unsigned long *) PWM_DUTY1;
 volatile unsigned long * pwm_duty2 = (unsigned long *) PWM_DUTY2;

 *pwm_en = enable;
 *pwm_period = period;
 *pwm_phase1 = phase1;
 *pwm_phase2 = phase2;
 *pwm_duty1 = duty1;
 *pwm_duty2 = duty2;

 }
 */

