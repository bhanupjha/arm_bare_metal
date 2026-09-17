#include "typedef.h"
#include "delay_header.h"
#include "eint0.h"
#include<lpc21xx.h>
#include "lcd.h"
#include "delay_header.h"
#include "LCD_defines.h"


void eint0_isr(void)__irq
{
	if(((IOPIN0>>1)&1)==0)
	{
		WRITE_LCD_CMD(CLEAR_LCD);
		WRITE_LCD_CMD(0X80);
		strLCD("1. Edit Request");
		WRITE_LCD_CMD(0X88);
		strLCD("2. exit");
		delay_ms(5000);
		WRITE_LCD_CMD(CLEAR_LCD);
	}
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
	EXTMODE = 1<<0;
}

