#include "rtc.h"

unsigned char hour;
unsigned char minute;
unsigned char second;
unsigned char day;
unsigned char date;
unsigned char month;
unsigned short year;

void RTC_Init(void)
{
    CCR = 0x02;        // Reset RTC

    PREINT  = 456;
    PREFRAC = 25024;

    RTC_SetTime(10,30,00,1,26,06,2026);

    CCR = 0x01;        // Start RTC
}

void RTC_SetTime(unsigned char hr,
                 unsigned char min,
                 unsigned char sec,
                 unsigned char d,
                 unsigned char dt,
                 unsigned char mon,
                 unsigned short yr)
{
    HOUR = hr;
    MIN  = min;
    SEC  = sec;

    DOM  = dt;
    MONTH = mon;
    YEAR = yr;
    DOW = d;
}

void RTC_GetTime(void)
{
    hour   = HOUR;
    minute = MIN;
    second = SEC;

    date   = DOM;
    month  = MONTH;
    year   = YEAR;
    day    = DOW;
}
void RTC_EditHour(unsigned char hr)
{
    if(hr <= 23)
    {
        HOUR = hr;
    }
}
void RTC_EditMinute(unsigned char min)
{
    if(min <= 59)
    {
        MIN = min;
    }
}
void RTC_EditSecond(unsigned char sec)
{
    if(sec <= 59)
    {
        SEC = sec;
    }
}
void RTC_EditDate(unsigned char date)
{
    if(date >= 1 && date <= 31)
    {
        DOM = date;
    }
}
void RTC_EditMonth(unsigned char month)
{
    if(month >= 1 && month <= 12)
    {
        MONTH = month;
    }
}
void RTC_EditYear(unsigned short year)
{
    if(year >= 2000 && year <= 2099)
    {
        YEAR = year;
    }
}
void RTC_EditDay(unsigned char day)
{
    if(day <= 6)
    {
        DOW = day;
    }
}






