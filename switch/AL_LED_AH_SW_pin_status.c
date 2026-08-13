// Write an ECP to display AH switch pin status on AL LED , if switch pressed -> LED glow , switch released -> LED off

#define AL_LED 5
#define AH_SW 1

#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	// cfg po.6 as o/p LED
	IODIR0 |= 1<<AL_LED;

	// cfg po.1 as i/p SW
	IODIR0 &= (~(1<<AH_SW));

	while(1)
	{
		if(((IOPIN0>>AH_SW)&1)==1)
		{
			// Make pin high
			IOCLR0 = 1<<AL_LED;
		}
			
		else
		{
			// Make pin low
			IOSET0 = 1<<AL_LED;
		}
	}
}
