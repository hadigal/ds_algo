#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#define LEN 10
// my null ptr
#define NULL ((void *)0)

// node DS
typedef struct Node
{
  int data;
  struct Node *next;
}Node;

// queue info DS
typedef struct QueueStat
{
  Node *start;
  Node *end;
  int count;
}Queue;

void display(Node *head);

// add node to queue at begining
void add(Queue **q,int val);

// remove the item in FIFO order
int pop(Queue *q);

// return the val last added to the queue
int peek(Queue *q);

// init the queue using list!!
Queue *initQueue();

#endif
