#include <lpc21xx.h>
#include "typedef.h"
#include "eint0.h"
#include "lcd.h"

int main()
{
	Init_LCD();
	eint0_enable();
	
	while(1)
	{
		WRITE_LCD_CMD(0X80);
		strLCD("Hii Bhanu");
	}
}
