#define IPIN 2
#define OPIN 6
#include<lpc21xx.h>
int main()
{
	// cfg po.6 as o/p
	IODIR0 |= 1<<OPIN;

	while(1)
	{
		// set & clr using ternary
		((IOPIN0>>IPIN)&1)?(IOSET0=1<<OPIN):(IOCLR0=1<<OPIN);
}	}