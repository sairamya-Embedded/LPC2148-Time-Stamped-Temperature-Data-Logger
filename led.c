#include "led.h"

#define LED 10

void LED_Init(void)
{
    IODIR0 |= (1<<LED);
}

void LED_ON(void)
{
    IOSET0 = (1<<LED);
}

void LED_OFF(void)
{
    IOCLR0 = (1<<LED);
}
