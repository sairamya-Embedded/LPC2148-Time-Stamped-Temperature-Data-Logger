#include "adc.h"

void ADC_Init(void)
{
    // P0.28 -> AD0.1
    PINSEL1 |= (1 << 24);

    // ADC Control Register
    AD0CR = (1 << 1)      |   // Select Channel 1 (AD0.1)
            (4 << 8)      |   // CLKDIV
            (1 << 21);        // Power ON
}

float ADC_ReadTemp(void)
{
    unsigned int adc_value;
    float voltage, temp;

    // Start Conversion
    AD0CR |= (1 << 24);

    // Wait until conversion completes
    while(((AD0GDR >> 31) & 1) == 0);

    adc_value = (AD0GDR >> 6) & 0x3FF;

    voltage = (adc_value * 3.3) / 1023.0;

    temp = voltage * 100.0;    // LM35: 10mV = 1°C

    return temp;
}


