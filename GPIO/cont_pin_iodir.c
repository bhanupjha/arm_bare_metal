#include<lpc21xx.h>
int main()
{
	// cfg po.4, po.5, po.6, po.7 as o/p
	IODIR0 |= 15<<4; // 15 for setting 4 pin 1 as o/p, and 4 starting pin

	// cfg po.8 to po.15 as o/p pin
	IODIR0 |= 0xFF<<8; // 128 - FF for setting 8 pin 1 as o/p and 8 starting pin

	// cfg po.8 to po.15 as i/p pin
	IODIR0 &= (~(0xFF<<8));
}