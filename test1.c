#include "types.h"
#include "LCD.h"

int main()
{
	Init_LCD();
	strLCD("hello");
	while(1);
}
