#include <lpc21xx.h>
#include "typedef.h"
#include "kpm.h"

int main()
{
	u32 keyv;
	IODIR1 |= 255<<8;
	Initkpm();
	keyv=keyscan();
	IOPIN0 = (((IOPIN0 & (~(255<<8))) | (keyv<<8)));
}
