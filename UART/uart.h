#include "typedef.h"
// primary drivers
void UART0_Init(void);
void UART0_TX(u8 sdat);
u8 UART0_RX(void);

// secondary drivers
void U0_Txstr(s8*);
void U0_TxU32(u32);
void U0_TxS32(s32);
void U0_TxF32(f32, u8);
s8 * U0_Rxstr(void);
