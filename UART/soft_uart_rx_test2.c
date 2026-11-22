// Bit banging version of uart protoocol for serial reception

#include "soft_uart.h"
#include "delay_header.h"
#include "typedef.h"
#include <lpc21xx.h>

#define OPIN_1 7  // P0.7 
#define OPIN_2 8  // P0.8

s8 rchar __attribute__((at(0x40000000)));

int main()
{
	// Initialize soft uart
	Init_soft_uart();
	
	// make as OPIN as o/p
	IODIR0 |= ((1<<OPIN_1) | (1<<OPIN_2));
	
	while(1)
	{
		if((rchar = rchar = soft_uart_RX()) == 'A')
		{
			IOPIN0 ^= 1<<OPIN_1;
			delay_ms(100);
		}
		else
		{
			IOPIN0 ^= 1<<OPIN_2;
			delay_ms(100);
		}
		soft_uart_TX(rchar);
	}
	
}
