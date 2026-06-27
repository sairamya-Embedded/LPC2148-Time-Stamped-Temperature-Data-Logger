#ifndef _LCD_H_
#define _LCD_H_

#include "defines.h"

// Function Prototypes
void LCD_Init(void);
void LCD_Cmd(unsigned char cmd);
void LCD_Char(unsigned char data);
void LCD_String(char *str);
void LCD_Integer(int num);
void LCD_Float(float num);
void LCD_Clear(void);
void LCD_Goto(unsigned char row, unsigned char col);

#endif
