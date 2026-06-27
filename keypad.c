#include "keypad.h"

char key[4][4]={
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void Keypad_Init(void)
{
    IODIR1 |= 0x000F0000;      // Rows as Output (P1.16-P1.19)
    IODIR1 &= ~0x00F00000;     // Columns as Input (P1.20-P1.23)
}

char Keypad_Read(void)
{
    int row,col;

    while(1)
    {
        for(row=0;row<4;row++)
        {
            IOSET1 = 0x000F0000;
            IOCLR1 = (1<<(16+row));

            for(col=0;col<4;col++)
            {
                if(!(IOPIN1 & (1<<(20+col))))
                {
                    while(!(IOPIN1 & (1<<(20+col))));
                    return key[row][col];
                }
            }
        }
    }
}
