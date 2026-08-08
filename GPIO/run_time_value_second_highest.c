// After got second highest digit from number set the second highest digit

#include<lpc21xx.h>
#include "delay_header.h"
int main()
{
	u32 num;
  u32	sh, h;
	
	// cfg po.8 to po.12 as o/p pin
	IODIR0 |= 15<<8;
	
	while(num)
	{
		u32 rem=num%10;
		if(rem>h)
		{
			sh=h;
			h=rem;
		}
		else if(rem>sh && rem!=sh)
		{
			sh=rem;
		}
		num =num/10;
	}
	
	// set the sh bit -> logic 1
	IOSET0 = sh<<8;
	
while(1);
}