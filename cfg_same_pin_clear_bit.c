// cfg same pin -> before using every time clear the bit
// One issue -> first its clear -> 00 -> First GPIO pin then expected fun 
#include<lpc21xx.h>
int main()
{

	// cfg po.3 as fun 2
	PINSEL0=PINSEL0&~(3<<(3*2));
	PINSEL0|=1<<(3*2);
	
	// cfg po.3 as fun 3
	PINSEL0&=~(3<<(3*2));
	PINSEL0|=2<<(3*2);

	while(1);
}
