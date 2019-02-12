#ifndef __LISTLIB_H__
#define __LISTLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *createNode(int data);

Node *addAtBeginning(Node *start, int data);

Node *addAtEnd(Node *start, int data);

void displayList(Node *start);

#endif
