#include "typedef.h"
#include "kpm_defines.h"
#include <lpc21xx.h>

u32 kpmLUT[4][4] = {{'7', '8', '9', '/'},
										{'4', '5', '6', '*'},
										{'1', '2', '3', '-'},
										{'C', '0', '=', '+'}};

void Initkpm(void)
{
	IODIR1 |= 15<<ROW0;
}

u32 colscan(void)
{
	if(((IOPIN1>>COL0)&15)<15)
		return 0;
	else
		return 1;
}

u32 Rowcheck(void)
{
	u32 rno;
	for(rno=0; rno<4; rno++)
	{
		IOPIN1 = ((IOPIN1 & (~(15<<ROW0)))|((~(1<<rno))<<ROW0));
		if(colscan()==0)
			break;
	}
	IOCLR1 = 15<<ROW0;
	return rno;
}

u32 colcheck(void)
{
	u32 cno;
	for(cno=0; cno<4; cno++)
	{
		if(((IOPIN1>>(COL0+cno))&1)==0)
		{
			break;
		}
	}
	return cno;
}


u32 keyscan(void)
{
	u32 rno, cno, key;
	// wait for switch press
	while(colscan());
	// find the rn
	rno = Rowcheck();
	// find the cn
	cno = colcheck();
	// get the valuee from LUT
	key = kpmLUT[rno][cno];
	// wait for switch release
	while(!colscan());
	return key;
}

u32 ReadNum(void)
{
	u8 key;
	u32 sum = 0;
	while(1)
	{
		key = keyscan();
		if(key >= '0' && key <= '9')
		{
			sum = (sum*10) + (key-48);
		}
		else
			break;
	}
	return sum;
}
