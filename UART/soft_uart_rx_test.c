// Bit banging version of uart protoocol for serial reception

#include "soft_uart.h"
#include "delay_header.h"
#include "typedef.h"
#include <lpc21xx.h>

u8 t __attribute__((at(0x40000000)));

int main()
{
	Init_soft_uart();
	t = soft_uart_RX();  // o/p will store at 0x40000000 location
	delay_ms(100);
	while(1);
}
