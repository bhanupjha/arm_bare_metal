// multi_7_seg
// Common Anode

#include "defines.h"
#include "typedef.h"
#include<lpc21xx.h>
#include "delay_header.h"

#define CA_7SEG 8 // po.8 to po.15
#define SEG1 16   // po.16 -> CA
#define SEG2 17   // po.17 -> CA

u8 segLUT[10] = {0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};

int main()
{
	s32 i, dly;
	
	// cfg po.8 to po.15 as o/p pin
	WRITEBYTE(IODIR0, CA_7SEG, 0XFF);
	
	// cfg po.16 as o/p
	SETBIT(IODIR0, SEG1);
	
	// cfg po.17 as o/p
	SETBIT(IODIR0, SEG2);
	
	for(i=0; i<100; i++)
	{
		for(dly=200; dly>0; dly--)
		{
			WRITEBYTE(IOPIN0, CA_7SEG, segLUT[i/10]);
			
			// Turn on seg1
			SSETBIT(IOSET0, SEG1);
			
			// delay 1ms
			delay_ms(1);
			
			// Turn off Seg1
			SCLRBIT(IOCLR0, SEG1);
			
			WRITEBYTE(IOPIN0, CA_7SEG, segLUT[i%10]);
			
			// Turn on seg2
			SSETBIT(IOSET0, SEG2);
			
			// delay 1ms
			delay_ms(1);
			
			// Turn off Seg2
			SCLRBIT(IOCLR0, SEG2);
		}
	}
	while(1);
}
