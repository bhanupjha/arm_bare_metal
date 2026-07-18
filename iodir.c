#include<lpc21xx.h>
int main()
{
	// cfg po.0 as o/p
	IODIR0 |= 1<<0;

	// cfg po.8 as o/p
	IODIR0 |= 1<<8;

	// cfg po.0 as i/p
	IODIR0 &= (~(1<<0));

	while(1);
}
							