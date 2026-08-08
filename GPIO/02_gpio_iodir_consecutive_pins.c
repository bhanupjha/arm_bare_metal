/*
 * File : 02_gpio_iodir_consecutive_pins.c
 * Topic: GPIO - IODIR Register
 * Description:
 *   Demonstrates how to configure consecutive GPIO pins
 *   as input and output using the IODIR0 register.
 */

#include<lpc21xx.h>
int main()
{
	// cfg po.4, po.5, po.6, po.7 as o/p
	IODIR0 |= 15<<4; // 15 for setting 4 pin 1 as o/p, and 4 for starting pin position

	// cfg po.8 to po.15 as o/p pin
	IODIR0 |= 0xFF<<8; // 0xFF for setting 8 pin 1 as o/p and 8 starting pin

	// cfg po.8 to po.15 as i/p pin
	IODIR0 &= (~(0xFF<<8));
	
	while(1);
}