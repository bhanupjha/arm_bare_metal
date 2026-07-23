#include<lpc21xx.h>
int main()
{
	// write po.0 as logic 1
	// default value - 1
	IOPIN0 |= 1<<0;

	// write po.0 as logic 0
	IOPIN0 &= (~(1<<0));

	// write po.0 to po.30 as logic 0
	// 2 pin-> 26 & 31 NA
	IOPIN0 &= (~(0xffffffff<<0));
}