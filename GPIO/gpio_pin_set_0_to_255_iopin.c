// write binary equivalent of 0 to 255 on po.8 to po.15 with 500ms using IOPIN0

#include<lpc21xx.h>
#include "delay_header.h"

int main()
{
	u32 i;
	// cfg po.0 to po.7 as o/p
	IODIR0 |= 255<<0;
	
	for(i=0; i<256; i++)
	{
		// set logic 1 to i
		IOPIN0 |= i<<0;
		
		// delay 500 ms
		delay_ms(500);
		
		// clear previous all bit
		IOPIN0 &= ~(255<<0);
		
		// using one line statement -> it will retain its previous value
		//IOPIN0 = ((IOPIN0 &~(255<0)) | (i<<0)); 
		//delay_ms(500);
	}
	
	while(1);
}
