// 4 AH 4 AL LED turn on one by one from right to left w.r.t 500 ms delay
// AH ON -> 1
// AH OFF -> 0

// AL ON -> 0
// AL OFF -> 1

// left 4 bit-> AL
// Right 4 bit-> AH
#include<lpc21xx.h>
#include "delay_header.h"
#include "typedef.h"
int main()
{
	s32 i;
	// cfg po.0 to po.7 as o/p
	IODIR0 |= 255<<0;
	
	// turn off all LED
	IOSET0 = 0xF0;   // AL OFF
  IOCLR0 = 0x0F;   // AH OFF
	
	for(i=0; i<4; i++)
{
    
    IOSET0 = 1<<i;    // Selected AH ON
    delay_ms(200);
	  IOCLR0 = 0x0F;    // All AH OFF
}
	
	for(i=4; i<8; i++)
{
    
    IOCLR0 = 1<<i;    // Selected AL ON
    delay_ms(200);
	  IOSET0 = 0xF0;    // All AL OFF
}
	
	
	while(1);
}
