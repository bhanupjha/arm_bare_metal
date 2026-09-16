#include "Adc.h"
#include "ADC_defines.h"
#include "LCD.h"

u32 dval;
f32 eAR;
int main()
{
	Init_LCD();
	Init_ADC();
	strLCD("ADC Test");
	while(1)
	{
		Read_ADC(CH1, &dval, &eAR);
		WRITE_LCD_CMD(0XC0);
		u32LCD(dval);
		WRITE_LCD_DATA('=');
		f32LCD(eAR, 2);
	}
}
