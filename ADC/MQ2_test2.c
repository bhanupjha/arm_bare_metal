#include <lpc21xx.h>
#include "typedef.h"
#include "LCD.h"
#include "MQ2.h"

int main()
{
	u32 gas_logic;
	Init_LCD();
	strLCD("MQ2 TEST");
	WRITE_LCD_CMD(0XC0);
	strLCD("Gas_value:");
	while(1)
	{
		gas_logic = ((IOPIN0>>MQ2_Gas)&1);
		WRITE_LCD_CMD(0xCA);
        u32LCD(gas_logic);
	}
}
