#include "uart.h"

void UART0_Init(void)
{
    PINSEL0 |= 0x00000005;      // P0.0 = TXD0, P0.1 = RXD0

    U0LCR = 0x83;               // 8-bit, 1 stop bit, DLAB = 1

    U0DLL = 97;                 // 9600 baud (PCLK = 15 MHz)
    U0DLM = 0;

    U0LCR = 0x03;               // DLAB = 0
}

void UART0_TxChar(char ch)
{
    U0THR = ch;
    while((U0LSR & 0x20) == 0);
}

void UART0_TxString(char *str)
{
    while(*str)
    {
        UART0_TxChar(*str++);
    }
}

void UART0_TxInteger(int num)
{
    char buf[10];
    sprintf(buf,"%d",num);
    UART0_TxString(buf);
}
void UART0_TxFloat(float num)
{
    char buf[20];
    sprintf(buf, "%.1f", num);
    UART0_TxString(buf);
}

