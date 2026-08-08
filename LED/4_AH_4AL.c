
#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	int i;
	// cfg p0.0 to po.7
	IODIR0 |= 255<<0;
	
	// all led off
	IOSET0 = 0x0F<<0;
	delay_s(1);
	
	// R to left
	for(i=0; i<=7; i++)
	{
		IOSET0=(((1<<i)^0x0F)<<0);
		// turn on led 
		//IOPIN0=(IOPIN0&~(255<<0))| (((1<<i)^0x0F)<<0);
		//delay 1 sec
		delay_s(1);
		IOCLR0=255<<0;
	}
	
	while(1);
	
	
}