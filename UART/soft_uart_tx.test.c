#include "soft_uart.h"
#include "delay_header.h"

int main()
{
	Init_soft_uart();
	while(1)
	{
		soft_uart_TX('A');
		delay_ms(100);
	}
}
