/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "system.h"
#include "movement.h"
#include "altera_avalon_pio_regs.h"
#include "unistd.h"

int main() {
	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x0);

	while (1) {
		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x01);
		move_forward(80);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x02);
		move_forward(50);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x04);
		front_left(80, 100);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x08);
		front_right(80, 100);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x10);
		back_left(80, 100);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x20);
		back_right(80, 100);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x40);
		spin_clockwise(100);
		usleep(3000000);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 0x80);
		spin_counterclockwise(100);
		usleep(3000000);
	}

	return 0;
}
