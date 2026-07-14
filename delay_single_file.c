#include "delay_header.h"
int main()
{
	//create 2 us delay
	delay_us(2);
	//create 10 msec delay
	delay_ms(10);
	//create 5 sec delay
	delay_s(5);
	while(1);
}

void delay_us(unsigned int dlyus)
{
	for(dlyus*=12; dlyus>0; dlyus--);
}

void delay_ms(unsigned int dlyms)
{
	for(dlyms*=12000; dlyms>0; dlyms--);
}

void delay_s(unsigned int dlys)
{
	for(dlys*=12000000; dlys>0; dlys--);
}
