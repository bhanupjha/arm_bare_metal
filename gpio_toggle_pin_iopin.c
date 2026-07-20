#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	// cfg po.7 as o/p
	IODIR0 |= 1<<7;
	while(1)
	{
		// write logic 1
		IOPIN0 |= 1<<7;

		// delay 100 ms
		delay_ms(100);

		// write logic 0
		IOPIN0 &= (~(1<<7));

		// delay 100 ms
		delay_ms(100);
	}
}
