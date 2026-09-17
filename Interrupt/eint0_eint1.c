#include "typedef.h"
#include <lpc21xx.h>
#include "delay_header.h"
#include "eint0_eint1.h"

void eint0_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT0_LED;
	delay_ms(2000);
	EXTINT = 1<<0; // clear eint0 flag
	VICVectAddr = 0; // end of interrupt
}

void eint1_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT1_LED;
	delay_ms(2000);
	EXTINT = 1<<1; // clear eint1 flag
	VICVectAddr = 0; // end of interrupt
}

void eint0_enable(void)
{
	// cfg p0.7 as o/p pin
	IODIR0 |= 1<<EINT0_LED;
	
	// cfg p0.16 as EINT0
	PINSEL1 |= 0X15400001;
	
	// select int0 as irq
	VICIntSelect = 0<<EINT0_CHNO;
	
	// enable eint0 interrupt source
	VICIntEnable = 1<<EINT0_CHNO;
	
	// load ISR address into address register
	VICVectAddr0 = (u32)eint0_isr;
	
	// select slot0 for eint0
	VICVectCntl0 = 1<<5|EINT0_CHNO;
	
	// trigger eint0 at edge
	EXTMODE |= 1<<0; // falling edge
}

void eint1_enable(void)
{
	// cfg p0.8 as o/p pin
	IODIR0 |= 1<<EINT1_LED;
	
	// cfg po.14 as EINT1
	PINSEL0 |= 0X20000000;
	
	// select Eint1 as irq
	VICIntSelect = 0<<EINT1_CHNO;
	
	// enable eint1 source
	VICIntEnable = 1<<EINT1_CHNO;
	
	// load ISR address
	VICVectAddr1 = (u32)eint1_isr;
	
	// select slot1 for eint1
	VICVectCntl1 = 1<<5|EINT1_CHNO;
	
	// trigger eint1 at edge
	EXTMODE |= 1<<1;
}
