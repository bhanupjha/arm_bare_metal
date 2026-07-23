#define IPIN 4
#define OPIN 6
#include<lpc21xx.h>
int main()
{
	/// cfg po.6 as o/p
	IODIR0 |= 1<<OPIN;

	while(1)
	{
		// using switch case
		switch((IOPIN0>>IPIN)&1)
		{
			case 0: IOCLR0 = 1<<OPIN;
			break;
			case 1: IOSET0 = 1<<OPIN;     
			break;
		}
	}
}