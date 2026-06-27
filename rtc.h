#ifndef _RTC_H_
#define _RTC_H_

#include "defines.h"
void RTC_EditHour(unsigned char hr);
void RTC_EditMinute(unsigned char min);
void RTC_EditSecond(unsigned char sec);
void RTC_EditDate(unsigned char date);
void RTC_EditMonth(unsigned char month);
void RTC_EditYear(unsigned short year);
void RTC_EditDay(unsigned char day);
void RTC_Init(void);
void RTC_SetTime(unsigned char hr,
                 unsigned char min,
                 unsigned char sec,
                 unsigned char day,
                 unsigned char date,
                 unsigned char month,
                 unsigned short year);

void RTC_GetTime(void);

extern unsigned char hour;
extern unsigned char minute;
extern unsigned char second;
extern unsigned char day;
extern unsigned char date;
extern unsigned char month;
extern unsigned short year;

#endif




								 