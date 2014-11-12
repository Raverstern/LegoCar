/*
 * motor_setting.h
 *
 *  Created on: 07.11.2012
 *      Author: karl_ee
 *          input parameters:
 *          phase: range from
 *          duty cycle:
 *          period: according to the freq of cpu,
 *                  normally the period should be set to the value
 *                  that makes the freq of pwm waveform to be 15 k
 *                  e.x for 50MHz, value should be 3333(0xD05)
 *          enable:'0' represents off, '1' is on
 */

#ifndef MOTOR_SETTING_H_
#define MOTOR_SETTING_H_

#include "system.h"

// for origin
//#define PWM_EN MOTOR_1_BASE
//#define PWM_PERIOD MOTOR_1_BASE+1
//#define PWM_DUTY1 MOTOR_1_BASE+2
//#define PWM_DUTY2 MOTOR_1_BASE+3
//#define PWM_PHASE1 MOTOR_1_BASE+4
//#define PWM_PHASE2 MOTOR_1_BASE+5

#define PERIOD_50MHZ 3333
#define DUTY_50HZ(x) ((x)*PERIOD_50MHZ/100)

// enable
#define ENABLE_CH1 1
#define ENABLE_CH2 2
#define ENABLE_BOTH 3

// motor_d
#define MOTOR_0 0
#define SERVO_0 1
#define MOTOR_1 2
#define SERVO_1 3
#define MOTOR_2 4
#define SERVO_2 5
#define MOTOR_3 6
#define SERVO_3 7

void motor_setting(unsigned long duty1, unsigned long duty2,
		unsigned long period, unsigned long enable, unsigned long motor_d);

/*
 void motor_setting_origin(unsigned long phase1, unsigned long duty1,
 unsigned long phase2, unsigned long duty2, unsigned long period,
 unsigned long enable);
 */

#endif /* MOTOR_SETTING_H_ */
