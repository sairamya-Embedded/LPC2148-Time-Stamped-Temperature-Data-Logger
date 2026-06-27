#include "defines.h"
#include "lcd.h"
#include "keypad.h"
#include "delay.h"
#include "setpoint.h"

extern int set_point;

void SetPoint_Edit(void)
{
    char d1,d2;

    LCD_Clear();
    LCD_String("Set Point:");

    d1 = Keypad_Read();
    LCD_Char(d1);

    d2 = Keypad_Read();
    LCD_Char(d2);

    set_point = ((d1-'0')*10) + (d2-'0');

    LCD_Clear();
    LCD_String("Updated");

    delay_ms(1000);
}
