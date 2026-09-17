#include <lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
#include "fiq_virq_nvirq.h"

u32 count;
int main()
{
	IODIR0 |= 1<<EINT0_LED | 1<<EINT1_LED | 1<<EINT2_LED;
	eint0_fiq_enable();
	eint1_virq_enable();
	eint2_nvirq_enable();
	while(1)
	{
		count++;
		delay_ms(100);
	}
}
