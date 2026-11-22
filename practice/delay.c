#include "type.h"
#include "delay.h"

void dlyus(u32 dly)
{
	for(dly*=12; dly>0; dly--);
}
void dlyms(u32 dly)
{
	for(dly*=12000; dly>0; dly--);
}
void dlys(u32 dly)
{
	for(dly*=12000000; dly>0; dly--);
}
