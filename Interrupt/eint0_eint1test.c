#include <lpc21xx.h>
#include "typedef.h"
#include "eint0_eint1.h"
#include "delay_header.h"

u32 count;
int main()
{
	eint0_enable();
	eint1_enable();
	while(1)
	{
		count++;
		delay_ms(100);
	}
}
