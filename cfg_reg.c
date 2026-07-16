// cfg reg -> it doesn't change other pin -> used Bitwise or 
#include<lpc21xx.h>
int main()
{
	// cfg po.0 as fun 1
	PINSEL0|=0<<(0*2);  // PINSEL0 = (PINSEL0 | (0<<(0*2)))

	// cfg po.3 as fun 2
	PINSEL0|=1<<(3*2);
	
	// cfg po.4 as fun3
	PINSEL0|=2<<(4*2);

	// cfg po.6 as fun 3
	PINSEL0|=2<<(6*2);
	
	// cfg po.11 as fun4
	PINSEL0|=3<<(11*2);

	// cfg po.1 as fun 2
	PINSEL0|=1<<(1*2);

	// cfg po.7 as fun3
	PINSEL0|=2<<(7*2);


	// cfg po.16 as fun2
	PINSEL1|=1<<((16-16)*2);

	// cfg po.17 as fun3
	PINSEL1|=2<<((17-16)*2);
	while(1);
}
