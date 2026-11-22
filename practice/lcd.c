#include "defines.h"
#include "lcd_define.h"
#include "type.h"
#include <lpc21xx.h>
#include "delay.h"

void WRITE_LCD_CMD(u8 cmd)
{
	// perform RW=0 write operation
	SCLRBIT(IOCLR0, LCD_RW);
	
	// select register RS=0
	SCLRBIT(IOCLR0, LCD_RS);
	
	// write data into data pins
	WRITEBYTE(IOPIN0, LCD_DATA, cmd);
	
	// apply H-L  EN=1
	SSETBIT(IOSET0, LCD_EN);
	
	dlyms(1);
	
	// apply L-H  EN=0
	SCLRBIT(IOCLR0, LCD_EN);
	
	dlys(2);
}

void WRITE_LCD_DATA(u8 ascii)
{
	// perform RW=0 write operation
	SCLRBIT(IOCLR0, LCD_RW);
	
	// select register RS=1
	SSETBIT(IOCLR0, LCD_RS);
	
	// write data into data pins
	WRITEBYTE(IOPIN0, LCD_DATA, ascii);
	
	// apply H-L  EN=1
	SSETBIT(IOSET0, LCD_EN);
	
	dlyms(1);
	
	// apply L-H  EN=0
	SCLRBIT(IOCLR0, LCD_EN);
	
	dlys(2);
}

void Init_LCD(void)
{
	// make LCD data pin as o/p
	WRITEBYTE(IODIR0,LCD_DATA, 0XFF);
	
	// set dir of RW, RS, EN
	SETBIT(IODIR0, LCD_RW);
	SETBIT(IODIR0, LCD_RS);
	SETBIT(IODIR0, LCD_EN);
	
	dlyms(5);
	
	WRITE_LCD_CMD(MODE_8_BIT_1_LINE);
	WRITE_LCD_CMD(MODE_8_BIT_1_LINE);
	WRITE_LCD_CMD(MODE_8_BIT_1_LINE);
	
	dlyms(100);
	
	WRITE_LCD_CMD(MODE_8_BIT_2_LINE);
	WRITE_LCD_CMD(MODE_8_BIT_1_LINE);
	WRITE_LCD_CMD(DISPLAY_ON_CUR_OFF);
	WRITE_LCD_CMD(CLEAR_LCD);
	WRITE_LCD_CMD(SHIFT_CUR_RIGHT);
	
}
