// write an ECP to display 0 to 15 binary on AL LED

#include <lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
int main()
{
	u32 i;
	
	// cfg po.0 to po.3 as o/p pin
	IODIR0  |= 15<<0;

	// All LED off
	IOSET0 = 15<<0;

	for(i=0; i<16; i++)
	{
		// make pin high
		IOCLR0 = i<<0;

		// delay- 1s
		delay_s(1);

		// All LED off
		IOSET0 = 15<<0;

		// delay -> 1sec
		delay_s(1);
	}
	while(1);
}
