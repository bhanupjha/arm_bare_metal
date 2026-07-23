// Method 3 using variable
#define OPIN 6
#define IPIN 3
#include<lpc21xx.h>
#include "typedef.h"
#include "delay_header.h"
int main()
{
	u32 t;
	// cfg OPIN as o/p
	IODIR0 |= 1<<OPIN;
	
	while(1)
	{
		// storing status of register in variable
		t = ((IOPIN0>>IPIN)&1);
		IOPIN0 = t<<OPIN;
	}
}