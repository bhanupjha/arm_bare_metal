#include <lpc21xx.h>
#include "typedef.h"
#include "LCD.h"
#include "ADC.h"
#include "thrsh_val.h"
#include "LM35.h"

int main()
{
	f32 tempc;
	Init_LCD();
	Init_ADC();
	strLCD("Gas Detection");
	while(1){
	tempc = LM35tc();
	WRITE_LCD_CMD(0XC0);
	f32LCD(tempc, 2);
	WRITE_LCD_DATA(0XDF);
	WRITE_LCD_DATA('C');
	if(tempc > THRSHOLD_VAL)
	{
		
		Buzzer_ON();
	}
	else
	{
		Buzzer_OFF();
	}
}	
}

