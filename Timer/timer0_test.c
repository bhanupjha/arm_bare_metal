#include "timer0.h"

int main()
{
	init_timer0();
	tdelay_us(1);
	tdelay_ms(1);
	tdelay_s(5);
	while(1);
}
