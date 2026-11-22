// peripheral Uart protocol for serial communication
#include <lpc21xx.h>
#include "uart.h"
#include "typedef.h"

#define SLED 7 // P0.7
#define FLED 8 // P0.8

int main()
{
	u8 t;
	UART0_Init();
	IODIR0 |= ((1<<SLED) | (1<<FLED));
	while(1)
	{
		t = UART0_RX();
		if(t=='A')
		{
			IOPIN0 ^= 1<<SLED;
		}
		else
		{
			IOPIN0 ^= 1<<FLED;
		}
	}
}
