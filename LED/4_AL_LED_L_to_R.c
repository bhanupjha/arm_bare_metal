// 4 AL LED turn on one by one from left to  right w.r.t 500 ms delay from L to R

#define AL_LED_start_bit 7
#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	u32 i;
	// cfg po.4 to po.7 AL_LED  as o/p
	IODIR0 |= 15<<4;
	
	// turn off all LED
	IOSET0 = 15<<4;

	while(1)
	{
	
	for(i= AL_LED_start_bit; i>=4; i--)
	{
		// write i -> port pin one by one logic 1-> make pin high
		IOCLR0 = 1<<i;
		
		// delay-> 500 ms
		delay_ms(500);
		
		// write i -> port pin one by one logic 0-> make pin low
		IOSET0 = 15<<4;
		
		// delay-> 500 ms
		delay_ms(500);
	}
	}
}
