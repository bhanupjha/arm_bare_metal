#include<lpc21xx.h>
int main()
{
	// cfg po.0, po.4, po.7, po.15, as o/p pin
	IODIR0 |= (1<<0)|(1<<4)|(1<<7)|(1<<15);

	// cfg po.0, po.4, po.7, po.15 as i/p pin
	// here if multiple pin use & instead of | 
	// | comparing with prev value prev value always set as o/p -> every time give the same value
	IODIR0 =  (IODIR0&(~(1<<0)))&(IODIR0&(~(1<<4)))&(IODIR0&(~(1<<7)))&(IODIR0&(~(1<<15)));		  // no effect

	while(1);
}
