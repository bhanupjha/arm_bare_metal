// 4 AH LED turn on one by one from right to  left w.r.t 500 ms delay from R to L

#define AL_LED_start_bit 0
#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	u32 i;
	// cfg po.0 to po.3 AL_LED  as o/p
	IODIR0 |= 15<<AL_LED_start_bit;
	
	// turn off all LED
	IOCLR0 = 15<<AL_LED_start_bit;

	while(1)
	{
	
	for(i= AL_LED_start_bit; i<=3; i++)
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
