#define IPIN 5
#define OPIN 7

#include<lpc21xx.h>
int main()
{
	// cfg po.7 as o/p 
	IODIR0 = 1<<OPIN;
	
	while(1)
	{
		// using ternary operator
		((IOPIN0>>IPIN)&1)?(IOPIN0 |= 1<<OPIN):(IOPIN0 &= (~(1<<OPIN)));
	}
}