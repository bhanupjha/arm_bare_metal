// toggling pin based on IPIN status 0 -> 0, status 1 -> 1
#define IPIN 0
#define OPIN 7
#include<lpc21xx.h>
int main()
{
	// cfg po.7 as o/p
	IODIR0 |= 1<<OPIN;
	while(1)
	{
		if(((IOPIN0>>IPIN)&1)==0)
		{
			// if status -> 0 -> logic 0
			IOCLR0 = 1<<OPIN;
		}
		else
		{
			// if status -> 1 -> logic 1
			IOSET0 = 1<<OPIN;
		}
	}
}