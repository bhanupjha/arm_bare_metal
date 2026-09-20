#include "LCD.h"
#include "LCD_defines.h"
#include "timer0.h"

//tdelay_us(1);
//tdelay_ms(1);
//tdelay_s(5);

int main()
{
	Init_LCD();
	Init_timer0();
	WRITE_LCD_CMD(GOTO_LINE1_POS0);
	strLCD("LCD_TEST");
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	WRITE_LCD_DATA('B');
	//delay_ms(500);
	tdelay_ms(500);
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	WRITE_LCD_DATA(' ');
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	strLCD("Bhanu");
	//delay_ms(500);
	tdelay_ms(500);
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	strLCD("     ");
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	u32LCD(12345);
	//delay_ms(500);
	tdelay_ms(500);
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	strLCD("     ");
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	s32LCD(-12345);
	//delay_ms(500);
	tdelay_ms(500);
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	strLCD("      ");
	WRITE_LCD_CMD(GOTO_LINE2_POS0);
	f32LCD(123.456,3);
	//delay_ms(500);
	tdelay_ms(500);
	//WRITE_LCD_CMD(CLEAR_LCD);
	while(1);
}
