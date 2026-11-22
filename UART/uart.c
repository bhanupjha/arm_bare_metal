#include <lpc21xx.h>
#include "typedef.h"
#include "uart_defines.h"

void UART0_Init(void)
{
	//cfg P0.0, P0.1 pins as TxD0 & RxD0 pins respectively
	PINSEL0 &= ~((3<<2)|(3<<0));
	PINSEL0 |= TXD0_PIN_FUNC | RXD0_PIN_FUNC;
	
	// cfg uxLCR for 8N1 & DLAB activate
	U0LCR = ((1<<DLAB_BITS) | (_8BIT<<WORD_LEN_SEL_BITS));
	
	// cfg baudrate
	U0DLL = DIVISOR;
	U0DLM = DIVISOR>>8;
	
	// reset DLAB Bit
	U0LCR &= ~(1<<DLAB_BITS);
}

void UART0_TX(u8 sdat)
{
	// write to UxTHR, serialization begins
	U0THR = sdat;
	//wait until serialization out completes
	while(((U0LSR>>TEMT_BIT)&1)==0);
}

u8 UART0_RX(void)
{
	// wait until reception status observed
	while(((U0LSR>>DR_BIT)&1)==0);
	
	// read & return received byte
	return U0RBR;
}

void U0_Txstr(s8 *s)
{
	while(*s)
		UART0_TX(*s++);
}

void U0_TxU32(u32 n)
{
	s32 i = 0; u8 a[10];
	if(n==0)
	{
		UART0_TX('0');
	}
	else
	{
		while(n>0)
		{
			a[i++] = (n%10)+48;
			n/=10;
		}
		for(--i; i>=0; i--)
		{
			UART0_TX(a[i]);
		}
	}
}

void U0_Txs32(s32 n)
{
	if(n<0)
	{
		UART0_TX('-');
		n=-n;
	}
	U0_TxU32(n);
}

void U0_TxF32(f32 fn, u8 nDP)
{
	u32  n, i;
	if(fn<0.0)
	{
		UART0_TX('-');
		fn=-fn;
	}
	n=fn;
	U0_TxU32(n);
	UART0_TX('.');
	for(i=0; i<nDP; i++)
	{
		fn=((fn-n)*10);
		n=fn;
		UART0_TX(n+48);
	}
}

s8* U0_Rxstr(void)
{
	static s8 rbuff[100];
	s8 t, i=0;
	while(1)
	{
		t = UART0_RX();
		rbuff[i] = t;
		UART0_TX(t);
		if((t == '\n') | (t == '\r'))
		{
			rbuff[i] = '\0';
			break;
		}
		i++;
	}
	U0_Txstr("\n\r");  // formatting o/p
	return rbuff;
}
