#include "typedef.h"
#include <lpc21xx.h>
#include "eint0.h"
#include "delay_header.h"

u32 count;
int	main()
{
	IODIR0 |= 1<<EINT0_LED;
	eint0_enable();
	while(1)
	{
		count++;
		delay_ms(100);
	}
}
