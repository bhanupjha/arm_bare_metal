#include "LCD.h"
#include "kpm.h"
#include "delay_header.h"

int main()
{
	u32 keyv;
	Init_LCD();
	Initkpm();
	strLCD("KPM Test");
	while(1)
	{
		WRITE_LCD_CMD(0xc0);
		keyv = keyscan();
		u32LCD(keyv);
		delay_ms(500);
		WRITE_LCD_CMD(0xc0);
		strLCD("  ");
	}
}
