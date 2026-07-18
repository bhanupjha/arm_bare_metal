#include<lpc21xx.h>
int main()
{
	// write po.0 as logic 1
	IOSET0 = 1<<0; // compund |&~ not reqd not reqd in IOSETreg bcz other bit not affect

	// write po.0 to po.7 as logic 1
	IOSET0 = 0xff<<0;

	// write po.8 po.10, po.12 as logic 1
	IOSET0 = (1<<8)|(1<<10)|(1<<12);
}