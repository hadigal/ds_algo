#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__

typedef struct Node
{
  int data;
  struct Node *next;
}Node;

Node *create(int data);

Node *addAtBeginning(Node *last, int data);

Node *addAtEnd(Node *last, int data);

Node *addAtPos(Node *last, int data, int pos);

Node *delete(Node *last, int data);

void display(Node *last);

#endif
