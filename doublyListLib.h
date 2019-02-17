#ifndef __DOUBLYLISTLIB_H__
#define __DOUBLYLISTLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


typedef struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
}Node;

Node *createNode(int data);

Node *addAtBeginning(Node *start, int data);

Node *addAtEnd(Node *start, int data);

Node *addBeforeNode(Node *start, int data, int d);

Node *addAfterNode(Node *start, int data, int d);

Node *deleteNode(Node *start, int data);

int getNodeCount(Node *start);

Node *addAtPosition(Node *start, int data, int pos);

void displayList(Node *start);

#endif
