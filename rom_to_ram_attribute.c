//copy rom to ram using attribute
#include "delay_header.h"
#include "typedef.h"
cs8 s[]__attribute__((at(0x00000010)))= "Welcome Bhanu";
s8 d[10]__attribute__((at(0x40000010)));
int main()
{
	s32 i;
	for(i=0; s[i]; i++)
	{
		d[i]=s[i];
		delay_s(1);
	} 
	while(1);
}
