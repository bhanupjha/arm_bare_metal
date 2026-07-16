// cfg the different reg.
#include<lpc21xx.h>
int main()
{
// for PINSEL0 ->	funvalue<<po.no.*2
// cfg po.0 as fun 1
PINSEL0=0<<0*2;

// cfg po.0 as fun2
PINSEL0=1<<0*2;

// cfg po.0 as fun3
PINSEL0=2<<0*2;

// cfg po.0 as fun4
PINSEL0=3<<0*2;


// for PINSEL1 -> funvalue<<((pinvalue-16)*2)
// cfg po.16 as fun1
PINSEL1=0<<((16-16)*2);

// cfg po.16 as fun2
PINSEL1=1<<((16-16)*2);

// cfg po.16 as fun3
PINSEL1=2<<((16-16)*2);

// cfg po.16 as fun 4
PINSEL1=3<<((16-16)*2);

while(1);
}
