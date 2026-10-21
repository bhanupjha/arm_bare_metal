//RTC_main.c
#include "LCD.h"
#include <lpc214x.h>
#include "defines.h"
#define FOSC 12000000
#define CCLK (5*FOSC)    
#define PCLK (CCLK/4)

#define PREINT_VAL  ((int)(PCLK/32768)-1)
#define PREFRAC_VAL (PCLK-((PREINT_VAL+1)*32768))

#define RTC_ENABLE (1<<0)
#define RTC_RESET (1<<1)

#define RTC_CLKSRC (1<<4) 

#define CPU_LPC2148		 

s32 hour,min,sec,date,month,year,day;
char week[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

#define SUN 0
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6


void RTC_Init(void)
{
  // Disable and reset the RTC
        CCR = RTC_RESET;
  #ifndef CPU_LPC2148
  // Set prescaler integer and fractional parts
        PREINT = PREINT_VAL;
        PREFRAC = PREFRAC_VAL;

  // Enable the RTC
        CCR = RTC_ENABLE;  //LPC_2129
        #else
        // Enable the RTC with external clock source
        CCR = RTC_ENABLE | RTC_CLKSRC;  //LPC_2148
        #endif
}
void SetRTCTimeInfo(u32 hour, u32 minute, u32 second)
{
        HOUR = hour;
        MIN = minute;
        SEC = second;
}


void GetRTCTimeInfo(s32 *hour, s32 *minute, s32 *second)
{
        *hour = HOUR;
        *minute = MIN;
        *second = SEC;
}
void DisplayRTCTime(u32 hour, u32 minute, u32 second)
{
        WRITE_LCD_CMD(GOTO_LINE1_POS0);
        WRITE_LCD_DATA(hour/10+48);
        WRITE_LCD_DATA(hour%10+48);
        WRITE_LCD_DATA(':');
        WRITE_LCD_DATA(minute/10+48);
        WRITE_LCD_DATA(minute%10+48);
        WRITE_LCD_DATA(':');
        WRITE_LCD_DATA(second/10+48);
        WRITE_LCD_DATA(second%10+48);
}
void SetRTCDateInfo(u32 date, u32 month, u32 year)
{
        DOM = date;
        MONTH = month;
        YEAR = year;
}
void GetRTCDateInfo(s32 *date, s32 *month, s32 *year)
{
        *date = DOM;
        *month = MONTH;
        *year = YEAR;
}
void DisplayRTCDate(u32 date, u32 month, u32 year)
{
        WRITE_LCD_CMD(GOTO_LINE2_POS0);
        WRITE_LCD_DATA(date/10+48);
        WRITE_LCD_DATA(date%10+48);
        WRITE_LCD_DATA('/');
        WRITE_LCD_DATA(month/10+48);
        WRITE_LCD_DATA(month%10+48);
        WRITE_LCD_DATA('/');
        u32LCD(year);
}
void SetRTCDay(u32 dow)
{
        DOW = dow;
}
void GetRTCDay(s32 *dow)
{
        *dow = DOW;
}
void DisplayRTCDay(u32 day)
{
        WRITE_LCD_CMD(GOTO_LINE1_POS0 + 10);
        strLCD(week[day]);
}

int main()
{
    // Initialize RTC 
                RTC_Init();
    // Initialize the LCD
                Init_LCD();

    // Set the initial time (hours, minutes, seconds)
                SetRTCTimeInfo(15,58,0);
    // Set the initial date (date, month, year)
                SetRTCDateInfo(5,9,2026);
    // Set initial day (SUN to SAT )
                SetRTCDay(SAT);


while (1)
    {
      // Get and display the current time info on LCD
                        GetRTCTimeInfo(&hour,&min,&sec);
                        DisplayRTCTime(hour,min,sec);
                        // Get and display the current date info on LCD
                        GetRTCDateInfo(&date,&month,&year);
                        DisplayRTCDate(date,month,year);
                  // Get and display the current day info on LCD
                        GetRTCDay(&day);
                        DisplayRTCDay(day);


    }
}
