// toggle po.7 w.r.t 500ms delay
#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	// cfg po.7 as o/p
	IODIR0 |= (1<<7);

	while(1)
	{
		// write logic 1 po.7
		IOSET0 = (1<<7);

		// dealy 500ms
		delay_ms(500);

		// write logic 0 po.7
		IOCLR0 = (1<<7);

		// delay 500ms
		delay_ms(500);
	}
}