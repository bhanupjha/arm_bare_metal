#include<lpc21xx.h>
int main()
{
	// write po.0 to po.15 as logic 1
	// first cfg as o/p to see the effect
	IOSET0 = 0xffff<<0;

	// write po.o as logic 0
	IOCLR0 = 1<<0;

	// write po.0 to po.15 as logic 0
	IOCLR0 = 0xffff<<0;
	while(1);
}