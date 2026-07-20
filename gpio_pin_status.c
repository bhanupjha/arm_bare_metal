#define IPIN 0
#define OPIN 7
#include<lpc21xx.h>
int main()
{
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