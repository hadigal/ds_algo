#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *create(int data);

Node *addAtBeginning(Node *last, int data);

Node *addAtEnd(Node *last, int data);

int getNodeCount(Node *last);

Node *addAtPos(Node *last, int data, int pos);

Node *delete(Node *last, int data);

void display(Node *last);

#endif
