// cfg same pin -> fun change to another fun instead of expecting fun
#include<lpc21xx.h>
int main()
{
	// cfg po.0 as fun 1
	PINSEL0|=0<<(0*2);  

	// cfg po.3 as fun 2
	PINSEL0|=1<<(3*2);
	
	// cfg po.0 as fun3
	PINSEL0|=2<<(0*2);

	// cfg po.3 as fun 3
	// po.3 -> fun 3 -> Match 0.0 timer but got -> EINT1 due to Bitwise or
	// fun2 | fun4 -> 01 | 10 -> 11 -> fun4
	PINSEL0|=2<<(3*2);
	

	while(1);
}
