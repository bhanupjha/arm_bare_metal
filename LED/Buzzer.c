#include <lpc21xx.h>
int main()
{
	while(1){
	IODIR0 |= 1<<0;
	
	IOSET0 = 1<<0;
	}
}
