#define EINT0_CHNO 14
#define EINT1_CHNO 15
#define EINT2_CHNO 16
#define EINT0_LED 8
#define EINT1_LED 9
#define EINT2_LED 10

void eint0_fiq_isr(void)__irq;
void eint1_virq_isr(void)__irq;
void eint2_nvirq_isr(void)__irq;
void eint0_fiq_enable(void);
void eint1_virq_enable(void);
void eint2_nvirq_enable(void);

