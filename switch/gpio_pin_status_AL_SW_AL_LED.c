// Write an ECP to display pin status on AL LED , if switch pressed -> LED glow , switch released -> LED off

#define AL_LED 6
#define AL_SW 0

#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	// cfg po.6 as o/p LED
	IODIR0 |= 1<<AL_LED;

	// cfg po.0 as i/p SW
	IODIR0 &= (~(1<<AL_SW));

	while(1)
	{
		if(((IOPIN0>>AL_SW)&1)==0)
		{
			// Make pin high
			IOCLR0 = 1<<AL_LED;
		}
			// delay_ms -> 500
		//	delay_ms(500);
		else
		{
			// Make pin low
			IOSET0 = 1<<AL_LED;

			// delay_ms -> 500
			//delay_ms(500);
		}
	}
}
