// LCD pin define
#define LCD_RS 16
#define LCD_RW 17
#define LCD_EN 18
#define LCD_DATA 8

// LCD commands
#define CLEAR_LCD 0x01
#define RET_CUR_HOME 0x02
#define MODE_8_BIT_1_LINE 0x30
#define MODE_8_BIT_2_LINE 0x38
#define MODE_4_BIT_1_LINE 0x20
#define MODE_4_BIT_2_LINE 0x28
#define DISPLAY_OFF 0x08
#define DISPLAY_ON_CUR_OFF 0x0C
#define DISPLAY_ON_CUR_ON  0x0E
#define DISPLAY_ON_CUR_BLINK 0x0F
#define SHIFT_CUR_RIGHT 0x06
#define GOTO_LINE1_POS0 0x80
#define GOTO_LINE2_POS0 0xC0
