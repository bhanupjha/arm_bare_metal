// cfg same reg -> it effect another port reg. 
#include<lpc21xx.h>
int main()
{
	// cfg po.0 as fun 1
	PINSEL0=0<<(0*2);

	// cfg po.3 as fun 2
	PINSEL0=1<<(3*2);
	
	// cfg po.6 as fun 3
	PINSEL0=2<<(6*2);
	
	// cfg po.15 as fun 4
	PINSEL0=((unsigned int)3<<(15*2)); // default int-> after shift MSB 1 that is treated as signed bit

	while(1);
}
