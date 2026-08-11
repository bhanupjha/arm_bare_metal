//Write an ECP to toggle Active low LED which is connected to the po.8 w.r.t 100 ms infinetly
#define AL_LED 8;
#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	// cfg po.8 as o/p
 	IODIR0 |= 1<<AL_LED;
	
	while(1)
	{
		// Write logic 1 on po.8 to AL_LED -> LED ON
		IOCLR0 = 1<<AL_LED;
		
		// delay - 200 ms
		delay_ms(200);
		
		// write logic 0 on po.8 to AL_LED -> LED OFF
		IOSET0 = 1<<AL_LED;
		
		// delay - 200 ms
		delay_ms(200);
	}
}
