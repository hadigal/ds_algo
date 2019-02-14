#ifndef __STACKLIB_H__
#define __STACKLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int *stackArr;

#define MAXSIZE 12

void displayStack(void);

int32_t peek(void);

void push(int32_t val);

int32_t pop(void);

int32_t isEmpty(void);

int32_t isFull(void);

#endif
