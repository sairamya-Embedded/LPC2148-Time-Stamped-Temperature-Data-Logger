#include "switch.h"

#define SW 15

void Switch_Init(void)
{
    IODIR0 &= ~(1<<SW);      // Input
}

int Switch_Read(void)
{
    if((IOPIN0 & (1<<SW)) == 0)
        return 1;            // Switch Pressed

    return 0;                // Switch Not Pressed
}

