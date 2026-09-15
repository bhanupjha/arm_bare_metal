#include "typedef.h"
#include "timer0.h"
#include <lpc21xx.h>

void init_timer0(void)
{
	// reset counter
	T0TCR = 1<<1;
	
	// stop on MR0
	T0MCR = 1<<2;
}	

void tdelay_us(u32 us)
{
	// set poing using MR0
	T0MR0 = us;
	
	// set prescaler value
	T0PR = 14;  // for 1 us
	
	// reset timer counter to 0
	T0TC =  0;
	
	// start counting
	T0TCR = 1<<0;
	
	while(T0MR0 != T0TC);
}

void tdelay_ms(u32 ms)
{
	// set poing using MR0
	T0MR0 = ms;
	
	// set prescaler value
	T0PR = 14999;  // for 1 us
	
	// reset timme counter to 0
	T0TC =  0;
	
	// start counting
	T0TCR = 1<<0;
	
	while(T0MR0 != T0TC);
}

void tdelay_s(u32 s)
{
	// set poing using MR0
	T0MR0 = s;
	
	// set prescaler value
	T0PR = 14999999;  // for 1 us
	
	// reset timme counter to 0
	T0TC =  0;
	
	// start counting
	T0TCR = 1<<0;
	
	while(T0MR0 != T0TC);
}

