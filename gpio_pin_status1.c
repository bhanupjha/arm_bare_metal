#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	// cfg po.9 as o/p
	IODIR0 |= 1<<9;
	while(1)
	{
		if(((IOPIN0>>1)&1)==0)
		{
			// status 0 -> logic 0
			IOCLR0 = 1<<9;

			// delay 100 ms
			delay_ms(100);
		}
		else
		{
			// status 1 -> logic 1
			IOSET0 = 1<<9;

			// delay 100 ms
			delay_ms(100);
		}
	}
}