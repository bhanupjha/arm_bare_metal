// Write an ECP to display AH switch pin status on AL LED , if switch pressed -> LED glow , switch released -> LED off

#define AH_LED 4
#define AH_SW 0

#include<lpc21xx.h>
int main()
{
	// cfg po.4 as o/p
	IODIR0 |= 1<<AH_LED;

	// cfg po.0 as i/p
	//IODIR0 = ((1<<AH_SW));

	while(1)
	{
		if(((IOPIN0>>AH_SW)&1)==1)
		{
			// AH LED turn on error
			IOCLR0 = 1<<AH_LED;
		}
		else
		{
			// AH LED turn off
			IOSET0 = 1<<AH_LED;
		}
	}
}
