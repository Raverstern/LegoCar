/*
 * encoder_sensor.h
 *
 *  Created on: Feb 6, 2012
 *      Author: Gang
 */

#ifndef ENCODER_SENSOR_H_
#define ENCODER_SENSOR_H_
//write_operation
#define set_sensor_speed(base_addr,data)	 IOWR(base_addr+(0<<2), 0, data) //TODO
#define set_senor_val(base_addr,data)    IOWR(base_addr+(1<<2), 0, data) //TODO
#define set_senor_ctrl(base_addr,data)    IOWR(base_addr+(2<<2), 0, data)
#define set_sensor_time(base_addr,data)	 IOWR(base_addr+(3<<2), 0, data) //TODO,set the time for compute speed

//read operation
#define get_sensor_speed(base_addr)	 IORD(base_addr+(0<<2), 0)
#define get_senor_val(base_addr)    IORD(base_addr+(1<<2), 0)
#define get_senor_ctrl(base_addr)    IORD(base_addr+(2<<2), 0)
#define get_sensor_time(base_addr)	 IORD(base_addr+(3<<2), 0)

#endif /* ENCODER_SENSOR_H_ */
