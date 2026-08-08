// Write a program for 8 AL LED and 4 AL switch 
// num1 = 65894, num2  = 84756, num3 = 65372, num4 = 1325
// if sw1 pressed num1 second highest digit binar display on 8 AL LED , SW2 pressed num2 SH binary display and so on
// intially 0 binary display on 8  AL LED.

#define AL_start_bit 0

#define SW1 8
#define SW2 9
#define SW3 10
#define SW4 11

#include<lpc21xx.h>
#include "typedef.h"
u32 sh(u32);
int main()
{
	u32 arr[5], res, res1, res2, res3;
	arr[0]=65894, arr[1] = 84756, arr[2] = 65372, arr[3] = 1325; 
	
	// cfg 8 AL LED as o/p -> po.0 to po.7
	IODIR0 |= 255<<AL_start_bit;
	
	// cfg sw1, sw2, sw3, sw4 as i/p
	IODIR0 &= ~(15<<8);
	
	// turn off all AL_LED
	IOSET0 = 0xFF;
	
	res=sh(arr[0]);
	res1=sh(arr[1]);
	res2=sh(arr[2]);
	res3=sh(arr[3]);
		
	while(1)
		{
			if(((IOPIN0 >> SW1)&1)== 0)
				{
					// turn off all AL_LED
					IOSET0 = 0xFF;
					
					// binary reresent on AL LED -> pin high
					IOCLR0 = res<<0;
					
					// wait until switch released
					while(((IOPIN0 >> SW1)&1)== 0);
				}
			else if(((IOPIN0 >> SW2)&1)== 0)
				{
					// turn off all AL_LED
					IOSET0 = 0xFF;
					
					// binary reresent on AL LED -> pin high
					IOCLR0 = res1<<0;
					
					// wait until switch released
					while(((IOPIN0 >> SW2)&1)== 0);
				}
			else if(((IOPIN0 >> SW3)&1)== 0)
				{
					// turn off all AL_LED
					IOSET0 = 0xFF;
					
					// binary reresent on AL LED -> pin high
					IOCLR0 = res2<<0;
					
					// wait until switch released
					while(((IOPIN0 >> SW3)&1)== 0);
				}
			else if(((IOPIN0 >> SW4)&1)== 0)
				{
					// turn off all AL_LED
					IOSET0 = 0xFF;
					
					// binary reresent on AL LED -> pin high
					IOCLR0 = res3<<0;
					
					// wait until switch released
					while(((IOPIN0 >> SW4)&1)== 0);
				}
			else
				{
					// turn off all AL_LED
					IOSET0 = 0xFF;
				}
		}
	
}

u32 sh(u32 n)
{
	u32 rem, h=0, sh=0;
	while(n)
	{
		rem = n%10;
		if(rem>h)
		{
			sh=h;
			h=rem;
		}
		else if(rem>sh && rem!=h)
		{
			sh=rem;
		}
		n=n/10;
	}
	return sh;
}
