#ifndef __LISTLIB_H__
#define __LISTLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *createNode(int data);

Node *addAtBeginning(Node *start, int data);

Node *addAtEnd(Node *start, int data);

Node *addInBetweenNodes(Node *start, int d1, int d2, int data);

Node *addBeforeNode(Node *start, int data, int d);

Node *addAfterNode(Node *start, int data, int d);

Node *deleteNode(Node *start, int data);

void displayList(Node *start);

#endif
