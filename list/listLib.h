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

Node *addAtPosition(Node *start, int data, int pos);

Node *deleteKey(Node *start, int key);

Node *deleteAtPos(Node *start, uint32_t pos);

Node *deleteEntireList(Node *start);

Node *search(Node *start, int val);

Node *findMid(Node *start);

Node *findNthNodeFromLast(Node *start, int idx);

Node *reverse(Node *start);

int countKeyOccurance(Node *head, int key);

void displayList(Node *start);

#endif
