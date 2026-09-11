// single_7seg.c
// common Anode

#define CA_7SEG 8  // po.8 to po.15
#define SEG 16;    // seg CA

#include "typedef.h"
#include "delay_header.h"
#include <lpc21xx.h>

u8 segLUT[10] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};
//                 0    1     2      3     4     5    6     7      8     9

int main()
{
	s32 i;
	// cfg po.8 to po.15 as o/p
	IODIR0 |= 0XFF<<CA_7SEG;
	
	// cfg p1.16 as o/p
	IODIR0 |= 1<<SEG;
	
	// make logic high -> CA
	IOSET0 = 1<<SEG;
	
	while(1)
	{
		for(i=0; i<10; i++)
		{
			// make logic low all pin 
			IOCLR0=255<<CA_7SEG;
			
			// make logic high
			IOSET0=segLUT[i]<<CA_7SEG;
			
			// delay -> 500ms
			delay_ms(500);
		}
	}
}
