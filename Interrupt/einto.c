#include <lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
#include "eint0.h"


void eint0_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT0_LED;
	delay_ms(1000);
	VICVectAddr = 0; // end of ISR
	EXTINT = 1<<0; // clear extint0 flag
}

void eint0_enable(void)
{
	// cfg p0.1 as EINT0
	PINSEL0 |= 3<<(1*2);
	
	// select extint0 as irq
	VICIntSelect = 0<<EINT0_CHNO;
	
	//enable extint0 source
	VICIntEnable = 1<<EINT0_CHNO;
	
	// load ISR address
	VICVectAddr0 = (u32)eint0_isr;
	
	// select slot for extint0
	VICVectCntl0 = 1<<5|EINT0_CHNO;
	
	//select edge triggering
	//EXTMODE = 1<<0;
}
