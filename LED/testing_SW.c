#include <lpc21xx.h>
#include "typedef.h"
#include "LCD.h"
#define SW2 5
int main()
{
	u32 val;
	Init_LCD();
	
	  while(1){
		val= ((IOPIN0>>SW2)&1);
		u32LCD(val);
		}
}
