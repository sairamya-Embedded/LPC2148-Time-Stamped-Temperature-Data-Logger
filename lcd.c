#include "lcd.h"
#include "defines.h"
#include "delay.h"

#define LCD_D 0x000000F0      // P0.4 - P0.7
#define RS     8              // P0.8
#define RW     9              // P0.9
#define EN     10             // P0.10

/*void delay_ms(unsigned int ms)
{
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<6000;j++);
}*/

void LCD_Enable()
{
    IOSET0 = (1<<EN);
    delay_ms(2);
    IOCLR0 = (1<<EN);
}

void LCD_Cmd(unsigned char cmd)
{
    IOCLR0 = (1<<RS);
    IOCLR0 = (1<<RW);

    IOCLR0 = LCD_D;
    IOSET0 = (cmd & 0xF0);
    LCD_Enable();

    IOCLR0 = LCD_D;
    IOSET0 = ((cmd<<4) & 0xF0);
    LCD_Enable();

    delay_ms(2);
}

void LCD_Char(unsigned char data)
{
    IOSET0 = (1<<RS);
    IOCLR0 = (1<<RW);

    IOCLR0 = LCD_D;
    IOSET0 = (data & 0xF0);
    LCD_Enable();

    IOCLR0 = LCD_D;
    IOSET0 = ((data<<4) & 0xF0);
    LCD_Enable();

    delay_ms(2);
}

void LCD_String(char *str)
{
    while(*str)
    {
        LCD_Char(*str++);
    }
}

void LCD_Clear()
{
    LCD_Cmd(0x01);
}

void LCD_Goto(unsigned char row,unsigned char col)
{
    if(row==1)
        LCD_Cmd(0x80+col);
    else
        LCD_Cmd(0xC0+col);
}

void LCD_Init()
{
    IODIR0 |= LCD_D;
    IODIR0 |= (1<<RS)|(1<<RW)|(1<<EN);

    delay_ms(20);

    LCD_Cmd(0x02);
    LCD_Cmd(0x28);
    LCD_Cmd(0x0C);
    LCD_Cmd(0x06);
    LCD_Cmd(0x01);
}
void LCD_Integer(int num)
{
    char buf[10];
    sprintf(buf,"%d",num);
    LCD_String(buf);
}

void LCD_Float(float num)
{
    char buf[20];
    sprintf(buf,"%.1f",num);
    LCD_String(buf);
}

