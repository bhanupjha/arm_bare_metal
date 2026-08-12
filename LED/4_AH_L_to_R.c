// 4 AH LED turn on one by one from left to  right w.r.t 500 ms delay from L to R

#define AH_LED_start_bit 3
#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	s32 i;
	// cfg po.0 to po.3 AL_LED  as o/p
	IODIR0 |= 15<<0;
	
	// turn off all LED
	IOCLR0 = 15<<0;

	while(1)
	{
	
	for(i=3; i>=0; i--)
	{
		// write i -> port pin one by one logic 1-> make pin high
		IOSET0 = 1<<i;
		
		// delay-> 500 ms
		delay_ms(500);
		
		// write i -> port pin one by one logic 0-> make pin low
		IOCLR0 = 15<<0;
		
		// delay-> 500 ms
		delay_ms(500);
	}
	}
}
