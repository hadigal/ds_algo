#ifndef __QUEUEWITHSTACK_H__
#define __QUEUEWITHSTACK_H__

#include "../stack/stack.h"

void enQueue(Stack **stack1, Stack **s2, int val);

int deQueue(Stack **stack);

void display(Stack *queue);

int peekQueue(Stack *queue);

#endif
