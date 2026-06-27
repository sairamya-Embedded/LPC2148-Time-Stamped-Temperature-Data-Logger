#include "defines.h"
#include "lcd.h"
#include "uart.h"
#include "adc.h"
#include "rtc.h"
#include "keypad.h"
#include "switch.h"
#include "led.h"
#include "setpoint.h"
#include "delay.h"


float temperature;
int set_point = 45;
char key_value;

int main()
{
    LCD_Init();
    UART0_Init();
    ADC_Init();
    RTC_Init();
    Keypad_Init();
	  LED_Init();
	  Switch_Init();
	

    while(1)
{
    RTC_GetTime();

    temperature = ADC_ReadTemp();

    LCD_Clear();

    // Display Time
    LCD_Goto(1,0);
    LCD_Integer(hour);
    LCD_Char(':');
    LCD_Integer(minute);
    LCD_Char(':');
    LCD_Integer(second);

    // Display Temperature
    LCD_Goto(2,0);
    LCD_String("T:");
    LCD_Float(temperature);
    LCD_Char(223);     // Degree Symbol
    LCD_Char('C');
	  if(temperature > set_point)
    {
        LED_ON();
    }
    else
    {
        LED_OFF();
    }
		 UART0_TxString("[INFO] Temp: ");

    UART0_TxFloat(temperature);

    UART0_TxString(" @ ");

    UART0_TxInteger(hour);
    UART0_TxChar(':');
    UART0_TxInteger(minute);
    UART0_TxChar(':');
    UART0_TxInteger(second);

    UART0_TxString("\r\n");
		


		if(Switch_Read())
			{
				UART0_TxString("*** TIME EDITING MODE ACTIVATED ***\r\n");
				LCD_Clear();
				LCD_Goto(1,0);
				LCD_String("EDIT MODE");
				delay_ms(1000);
				
				LCD_Clear();
				LCD_Goto(1,0);

        LCD_String("1.RTC 2.SET");
         
        LCD_Goto(2,0);
        LCD_String("3.EXIT");

    key_value = Keypad_Read();

    switch(key_value)
    {
        case '1':
        {
            char h1,h2;
            unsigned char hr;

            LCD_Clear();
            LCD_String("Hour:");

            h1 = Keypad_Read();
            LCD_Char(h1);

            h2 = Keypad_Read();
            LCD_Char(h2);

            hr=((h1-'0')*10)+(h2-'0');

            RTC_EditHour(hr);

            LCD_Clear();
            LCD_String("Hour Updated");

            delay_ms(1000);
            break;
        }

     case '2':
{
    char m1,m2;
    unsigned char min;

    LCD_Clear();
    LCD_String("Minute:");

    m1 = Keypad_Read();
    LCD_Char(m1);

    m2 = Keypad_Read();
    LCD_Char(m2);

    min = ((m1-'0')*10) + (m2-'0');

    RTC_EditMinute(min);

    LCD_Clear();
    LCD_String("Minute Updated");

    delay_ms(1000);
    break;
}

       case '3':
{
    char s1,s2;
    unsigned char sec;

    LCD_Clear();
    LCD_String("Second:");

    s1 = Keypad_Read();
    LCD_Char(s1);

    s2 = Keypad_Read();
    LCD_Char(s2);

    sec = ((s1-'0')*10) + (s2-'0');

    RTC_EditSecond(sec);

    LCD_Clear();
    LCD_String("Second Updated");

    delay_ms(1000);

    break;
}
case '4':
{
    char d1,d2;
    unsigned char date;

    LCD_Clear();
    LCD_String("Date:");

    d1 = Keypad_Read();
    LCD_Char(d1);

    d2 = Keypad_Read();
    LCD_Char(d2);

    date = ((d1-'0')*10) + (d2-'0');

    RTC_EditDate(date);

    LCD_Clear();
    LCD_String("Date Updated");

    delay_ms(1000);

    break;
}

        case '5':
{
    char m1,m2;
    unsigned char month;

    LCD_Clear();
    LCD_String("Month:");

    m1 = Keypad_Read();
    LCD_Char(m1);

    m2 = Keypad_Read();
    LCD_Char(m2);

    month = ((m1-'0')*10) + (m2-'0');

    RTC_EditMonth(month);

    LCD_Clear();
    LCD_String("Month Updated");

    delay_ms(1000);

    break;
}
case '6':
{
    char y1,y2,y3,y4;
    unsigned short year;

    LCD_Clear();
    LCD_String("Year:");

    y1 = Keypad_Read();
    LCD_Char(y1);

    y2 = Keypad_Read();
    LCD_Char(y2);

    y3 = Keypad_Read();
    LCD_Char(y3);

    y4 = Keypad_Read();
    LCD_Char(y4);

    year = (y1-'0')*1000 +
           (y2-'0')*100 +
           (y3-'0')*10 +
           (y4-'0');

    RTC_EditYear(year);

    LCD_Clear();
    LCD_String("Year Updated");

    delay_ms(1000);
    break;
}
case '7':
{
    char d;

    LCD_Clear();
    LCD_String("Day(0-6):");

    d = Keypad_Read();
    LCD_Char(d);

    RTC_EditDay(d-'0');

    LCD_Clear();
    LCD_String("Day Updated");

    delay_ms(1000);

    break;
}
    }
}

    delay_ms(1000);
}
}

