#define FOSC 12000000	 // crystal oscillator
#define CCLK FOSC*5	  //processor clk frequency after PLL 60 MHZ   -> 12*5
#define PCLK CCLK/4   // peripheral clock frequecy after APB driver
#define ADCLK 3000000   // less than 4.5 we can take
#define CLKDIV ((PCLK/ADCLK)-1)       // FADC = ((PCLK)/CLKDIV+1) -> CLKDIV = ((PCLK/FADC) -1)

#include <lpc21xx.h>
void init_ADC()
{
	// cfg p0.29 as AD0.2
	PINSEL1 |=  0x04400000;

	//select channel no
	ADCR |= (1<<2);   // ch no. 2 selected

	// load clkdiv value to ADCR reg
	ADCR |= CLKDIV<<8;        // bit 8 to 15 to store clk div value

	// PDN bit 1 to start conversion
	ADCR |= 1<<21;  // 21 bit is PDN bit

	// start conversion - 1 , 24 - 26 start conversion
	ADCR |= 1<<24;

	if(((IOPIN0>>31)&1)==1)
	{
		
	}

}
