// 8 AL LED turn on one by one from left to  right w.r.t 500 ms delay from L to R
// AL_LED -> ON -> 0
// AL_LED -> OFF -> 1
#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	s32 i;
	// cfg po.0 to po.7 AL_LED  as o/p
	IODIR0 |= 255<<0;
	
	// turn off all LED
	IOSET0 = 255<<0;
	
	for(i=7; i>=0; i--)
	{
		// write i -> port pin one by one logic 1-> make pin high
		IOCLR0 = 1<<i;
		
		// delay-> 500 ms
		delay_ms(500);
		
		// write i -> port pin one by one logic 0-> make pin low
		IOSET0 = 255<<0;
		
		// delay-> 500 ms
		delay_ms(500);
	}
	while(1);
}
