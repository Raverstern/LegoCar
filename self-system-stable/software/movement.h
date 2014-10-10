#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void move_forward(unsigned long motor_duty);
void move_backward(unsigned long motor_duty);
void front_left(unsigned long motor_duty, unsigned long servo_duty);
void front_right(unsigned long motor_duty, unsigned long servo_duty);


// EXPERIMENT
void back_left(unsigned long motor_duty, unsigned long servo_duty);
void back_right(unsigned long motor_duty, unsigned long servo_duty);
void spin_clockwise(unsigned long motor_duty);
void spin_counterclockwise(unsigned long motor_duty);

#endif /* MOVEMENT_H_*/
