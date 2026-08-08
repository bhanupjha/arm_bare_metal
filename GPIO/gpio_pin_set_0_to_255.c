// write binary equivalent of 0 to 255 on po.8 to po.15 with 500ms
#include<lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
int main()
{
	u32 i;
	// cfg po.8 - po.15 as o/p
	IODIR0 |= 255<<8;
	
	for(i=0; i<256; i++)
	{
		// Make pin high
		IOSET0 = i<<8;
		
		// delay 500ms
		delay_ms(500);
		
		// to clear previous bit 
		IOCLR0 = 255<<8;
	}
	while(1);
}
