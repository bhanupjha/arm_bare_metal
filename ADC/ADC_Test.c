//ADC_Test.c

#include<lpc21xx.h>
#include "typedef.h"
#include "ADC_defines.h"
#include "ADC.h"

u32 dval;
f32 eAR;
int main()
{
	Init_ADC();
	while(1)
	{
		Read_ADC(CH0, &dval, &eAR);
	}
}
