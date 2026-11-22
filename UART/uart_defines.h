#define TXD0_PIN_FUNC 0x00000001
#define RXD0_PIN_FUNC 0x00000004

#define BAUD 9600
#define FOSC 12000000
#define CCLK (FOSC*5)
#define PCLK (CCLK/4)
#define DIVISOR (PCLK/(16*BAUD))

// define for UxLCR
#define _8BIT 3
#define WORD_LEN_SEL_BITS 0
#define DLAB_BITS 7

// define for UxLSR SFR
#define TEMT_BIT 6
#define DR_BIT 0
