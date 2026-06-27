#ifndef _UART_H_
#define _UART_H_

#include "defines.h"

void UART0_Init(void);
void UART0_TxChar(char ch);
void UART0_TxString(char *str);
void UART0_TxInteger(int num);
void UART0_TxFloat(float num);
#endif
