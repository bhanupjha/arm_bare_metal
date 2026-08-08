/*
 * File : 01_gpio_iodir.c
 * Topic: GPIO - IODIR Register
 * Description:
 *   Demonstrates how to configure GPIO pins
 *   as input and output using the IODIR0 register.
 */

#include<lpc21xx.h>
int main()
{
	// cfg po.0 as o/p
	IODIR0 |= 1<<0;

	// cfg po.8 as o/p
	IODIR0 |= 1<<8;

	// cfg po.0 as i/p
	IODIR0 &= (~(1<<0));

	while(1);
}
							