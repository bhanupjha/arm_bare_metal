#include "typedef.h"
#include "ADC.h"
#include "ADC_defines.h"
#include "LCD.h"

f32 LM35tc(void)
{
	u32 dval;
	f32 eAR;
	Read_ADC(CH1, &dval, &eAR);
	WRITE_LCD_CMD(0XC0);
	u32LCD(dval);
	return (eAR*100);
}

f32 LM35tF(void)
{
	f32 tempc;
	tempc = LM35tc();
	return (tempc*(1.8)+32);
}
