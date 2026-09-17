#define EINT0_CHNO 14
#define EINT1_CHNO 15
#define EINT0_LED 7
#define EINT1_LED 8

void eint0_isr(void)__irq;
void eint1_isr(void)__irq;
void eint0_enable(void);
void eint1_enable(void);
