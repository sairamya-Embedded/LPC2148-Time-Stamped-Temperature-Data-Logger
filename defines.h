#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <LPC214x.h>
#include <stdio.h>
#include <string.h>

#define SETBIT(WORD,BIT)    WORD |= (1<<BIT)
#define CLRBIT(WORD,BIT)    WORD &= ~(1<<BIT)
#define READBIT(WORD,BIT)   ((WORD>>BIT)&1)

#endif
