#include <lpc21xx.h>
#include "typedef.h"
#include "defines.h"
#include "delay_header.h"
#include "soft_uart_defines.h"

void Init_soft_uart(void)
{
	// cfg Txd_pin to be high
	IOSET0 = 1<<TXD_PIN;

	// cfg Txd_ pin to be gpio output pin
	IODIR0 |= 1<<TXD_PIN;

	// cfg Rxd_pin to be high
	IOSET0 = 1<<RXD_PIN;

	// cfg Rxd_pin to be gpio pin input
	IODIR0 &= ~(1<<RXD_PIN);
}

void soft_uart_TX(u8 sdat)
{
	u8 i;
	// issue start bit '0'
	IOCLR0 = 1<<TXD_PIN;

	// 9600 baud i.e bit period
	delay_us(BAUD);

	// serialize out 'sdat'
	for(i=0; i<8; i++)
	{
		// LSB to MSB order via TXD_PIN
		READWRITEBIT2(sdat, IOPIN0, i, TXD_PIN);

		// 9600 baud i.e bit period
		delay_us(BAUD);
	}
	// issue stop bit '1'
	IOSET0 = 1<<TXD_PIN;

	delay_us(BAUD);
}

u8 soft_uart_RX(void)
{
	u8 i, rdat;

	// wait for start bit from transmitter
	while(READBIT (IOPIN0, RXD_PIN));

	// @BAUD/2 only for start bit
	delay_us(BAUD/2);

	// serialize input & store
	for(i=0; i<8; i++)
	{
		// BAUD
		delay_us(BAUD);

		// LSB to MSB order to store into rdat
		READWRITEBIT2(IOPIN0, rdat, RXD_PIN, i);
	}
	// BAUD for stop bit
	delay_us(BAUD);

	while(READBIT(IOPIN0, RXD_PIN) == 0);

	return rdat;
}
