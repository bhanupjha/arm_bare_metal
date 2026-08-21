// LCD.c

#include<lpc21xx.h>
#include "types.h"
#include "delay.h"
#include "LCD_defines.h"
#include "defines.h"

void WRITE_LCD_CMD(u8 cmd)
{
	// perform write operation (rw=0)
	SCLRBIT(IOCLO, LCD_RW);

	// select command register (rs=0)
	SCLRBIT(IOCLRO, LCD_RS);

	// write command to the data pins
	WRITEBYTE(IOPIN0, LCD_DATA, cmd);

	// Apply H-L pulse on EN
	SSETBIT(IOSET0, LCD_EN);   // EN=1

	// delay 1s
	delay_us(1);

	SCLRBIT(IOCLR0, LCD_EN);  //EN=0

	// delay for internal process
	delay_ms(2);
}

void Init_LCD(void)
{
	// cfg p0.8 to p0.15 LCD data pin as o/p
	WRITEBYTE(IODIR0, LCD_DATA, OXFF);

	// cfg P0.16(rs), P0.17 (rw) and P0.18(en) as o/p
	SETBIT(IODIR0, LCD_RS);
	SETBIT(IODIR0, LCD_RW);
	SETBIT(IODIR0, LCD_EN);

	delay_ms(5);

	WRITE_LCD_CMD(MODE_8BIT_1LINE);
	delay_ms(5);
	WRITE_LCD_CMD(MODE_8BIT_1LINE);
	delay_ms(100);
	WRITE_LCD_CMD(MODE_8BIT_1LINE);

	WRITE_LCD_CMD(MODE_8BIT_2LINE);
	WRITE_LCD_CMD(DISP_ON_CUR_ON);
	WRITE_LCD_CMD(CLEAR_LCD);
	WRITE_LCD_CMD(SHIFT_CUR_RIGHT);

}

void WRITE_LCD_DATA(u8 ascii)
{
	SCL_BIT(IOCLR0, LCD_RW);

	// select data register (rs=1)
	SSET_BIT(IOSET0, LCD_RS);

	// write data on the data pins
	WRITEBYTE(IOPIN0, LCD_DATA, ascii);

	//apply H-L pulse on EN
	SSET_BIT(IOSET0, LCD_EN); // EN=1

	delay_us(1);

	SCLRBIT(IOCLR0, LCD_EN); // EN=0

	// delay for internal process
	delay_ms(2);
}

void strLCD(s8* str)
{
	While(*str)
	{
		WRITE_LCD_DATA(*str++)
	}
}

void u32 LCD(u32 n)
{
	u8 a[10];
	s32 i=0;
	if(n==0)
	{
		WRITE_LCD_DATA('0');
	}
	else
	{
		while(n)
		{
			a[i++]=n%10+48;
			n/=10;
		}
	for(--i; i>=0; i--)
	{
		WRITE_LCD_DATA(a[i]);
	}
	}
}

void s32 LCD(s32 n)
{
	if(n<0)
	{
		WRITE_LCD_DATA('-');
		n=-n;
	}
	u32 LCD(n);
}

void f32 LCD(f32 fn, u8 nDP)
{
	u32 inum;
	if(fn<0)
	{
		WRITE_LCD_DATA('-');
		fn =-fn;
	}
	inum=fn;
	u32 LCD(inum);
	WRITE_LCD_DATA('.');
	for(i=0; i<nDP; i++)
	{
		fn=(fn-inum)*10;
		inum=fn;
		WRITE_LCD_DATA(inum+'0');
	}
} 