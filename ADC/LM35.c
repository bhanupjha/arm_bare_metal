#include "typedef.h"
#include "ADC.h"
#include "ADC_defines.h"

f32 LM35tc(void)
{
	u32 dval;
	f32 eAR;
	Read_ADC(CH0, &dval, &eAR);
	return (eAR*100);
}

f32 LM35tF(void)
{
	f32 tempc;
	tempc = LM35tc();
	return (tempc*(1.8)+32);
}
