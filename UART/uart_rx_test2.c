// peripheral UART protocol for serial reception
#include <lpc21xx.h>
#include "uart.h"
#include "typedef.h"

int main()
{
	s8 *p;
	UART0_Init();
	while(1)
	{
		U0_Txstr("Enter any string\n\r");
		p = U0_Rxstr();
		U0_Txstr(p);
		U0_Txstr("\n\r");
	}
}
