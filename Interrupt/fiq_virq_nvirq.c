#include <lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
#include "fiq_virq_nvirq.h"

void eint0_fiq_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT0_LED;
	delay_ms(2000);
	EXTINT = 1<<0;
	VICVectAddr = 0;
}

void eint1_virq_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT1_LED;
	delay_ms(2000);
	EXTINT = 1<<1;
	VICVectAddr = 0;
}

void eint2_nvirq_isr(void)__irq
{
	IOPIN0 ^= 1<<EINT2_LED;
	delay_ms(2000);
	EXTINT = 1<<2;
	VICVectAddr = 0;
}

void eint0_fiq_enable(void)
{
	// cfg p0.16 as EINT0
	PINSEL1 |= 0x15400001;
	
	// raise EINT0 as fiq
	VICIntSelect = 1<<EINT0_CHNO;
	
	// enable the eint0 source
	VICIntEnable = 1<<EINT0_CHNO;
	
	//for  fiq isr addr need to manipulate the startup
	// comment 263 line place this FIQ handler
	// B eint0_fiq_isr
	// Import eint0_fiq_isr
	
	// trigger at edge
	EXTMODE = 1<<0;
	
}

void eint1_virq_enable(void)
{
	// cfg p0.14 as EINT1
	PINSEL0 |= 0x20000000;
	
	// select eint1 as irq
	// VICIntSelect = 0<<EINT1_CHNO;
	
	// enable eint1 source
	VICIntEnable = 1<<EINT1_CHNO;
	
	// load ISR address 
	VICVectAddr0 = (u32)eint1_virq_isr;
	
	// select slot for eint0
	VICVectCntl0 = 1<<5|EINT1_CHNO;
	
	// trigger eint1 at edge
	EXTMODE |= 1<<1;
}

void eint2_nvirq_enable(void)
{
	// cfg p0.15 as eint2
	PINSEL0 |= 0x80000000;
	
	// select eint2 as irq
	// VICIntSelect = 0<<EINT2_CHNO;
	
	// enable eint2 source
	VICIntEnable = 1<<EINT2_CHNO;
	
	// load ISR address
	VICDefVectAddr = (u32)eint2_nvirq_isr;
	
	// trigger eint2 at edge
	EXTMODE |= 1<<2;
}
