#ifndef __QUEUELIB_H__
#define __QUEUELIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSIZE 10

int fullFlag;

typedef struct Node
{
  int data;
  struct Node *next;
}Node;


Node *frontNode, *rearNode;

Node *createNode(int val);

void insert(int data);

void delete();

int peek();

int isEmpty(void);

int isFull(void);

void display(void);

#endif
