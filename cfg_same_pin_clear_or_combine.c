// for getting expected pin in one execution combine both statement with bitwise or
// To avoid writing multiple time lengthy dunc we can write one func
#include<lpc21xx.h>
int main()
{

	// cfg po.3 as fun 2
	PINSEL0=(PINSEL0&~(3<<(3*2))|(1<<(3*2)));
	
	// cfg po.3 as fun 3
	// dont write in shrt it change the meaning of expression
	PINSEL0=(PINSEL0&~(3<<(3*2))|(2<<(3*2)));

	while(1);
}
