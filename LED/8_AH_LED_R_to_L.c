// 8 AH_LED turn on one by one w.r.t 200ms delay from R to L
// AH_LED -> 1 -> ON
// AH_LED -> 0 -> OFF
#include <lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	u32 i;
	// cfg po.0 to po.7 as o/p
	IODIR0 |= 255<<0;
	
	// turn off all AH led
	IOCLR0 = 255<<0;
	
	for(i=0; i<=7; i++)
	{
		// turn on led one by one
		IOSET0 = 1<<i;
		
		// delay -> 200ms
		delay_ms(200);
		
		// turn off all LED
		IOCLR0 = 255<<0;
	}
	while(1);
}