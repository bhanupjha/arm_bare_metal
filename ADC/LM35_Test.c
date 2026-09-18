#include "typedef.h"
#include "ADC.h"
#include "LCD.h"
#include "LM35.h"

int main()
{
	f32 tempc;
//	f32 tempF;
	
	Init_LCD();
	Init_ADC();
	strLCD("LM35 TEST");
	while(1)
	{
		tempc = LM35tc();
		WRITE_LCD_CMD(0XC0);
		f32LCD(tempc, 2);
		WRITE_LCD_DATA(0XDF);
		WRITE_LCD_DATA('C');
		
		//tempF = LM35tF();
	//	WRITE_LCD_CMD(0XC8);
	//	f32LCD(tempF, 2);
	//	WRITE_LCD_DATA(0XDF);  // 0XDF -> degree
	//	WRITE_LCD_DATA('F');
	}
}
