// peripheral version of UART protocol for serial communication
#include "uart.h"
#include "typedef.h"
#include "delay_header.h"

int	main()
{
	UART0_Init();
	while(1)
	{
		UART0_TX('A');
		delay_ms(100);
	}
}
