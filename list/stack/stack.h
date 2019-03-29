#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 10

typedef struct Node
{
  int val;
  struct Node *next;
}Stack;

Stack *createNode(int val);

void push(Stack **head, int val);

int pop(Stack **head);

bool isEmpty(Stack *head);

int peek(Stack *head);

#endif
