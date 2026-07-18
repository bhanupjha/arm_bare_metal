#include "pin_connect_block.h"
#include "port_fun_define.h"
int main()
{
	// cfg po.1 as fun2
	cfgportpin(0, 1, 1); // cfg port pin args  constant to meaningfull code

	// cfg po.1 as fun3
	cfgportpin(PORT0, PIN1, FUN3); 

	// cfg po.16 as fun2
	cfgportpin(PORT0, PIN16, FUN2);

	// cfg po.16 as fun3
	cfgportpin(PORT0, PIN16, FUN3);

	// cfg po.16 as fun4
	cfgportpin(PORT0, PIN16, FUN4);

	while(1);
}


							  