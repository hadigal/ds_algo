#include "listLib.h"

Node *createNode(int data)
{
  Node *n1 = (Node *)calloc(1,sizeof(*n1));
  n1->data = data;
  n1->next = NULL;
  return n1;
}

Node * addAtBeginning(Node *start, int data)
{
  Node *temp;
  if(start == NULL)
  {
    temp = createNode(data);
    start = temp;
    return start;
  }

  temp = createNode(data);
  temp->next = start;
  start = temp;
  return start;
}

Node *addAtEnd(Node *start, int data)
{
  Node *temp, *itr;
  if(start == NULL)
  {
    temp = createNode(data);
    start = temp;
    return start;
  }
  
  itr = start;

  while((itr->next) != NULL)
  {
    itr = itr->next;
  }

  temp = createNode(data);
  itr->next = temp;
  return start;
}

void displayList(Node *start)
{
  if(start == NULL)
  {
    printf("LIST is empty\n");
    return;
  }

  Node *itr = start;

  int count = 1;
  while(itr != NULL)
  {
    printf("NODE%d[addr:%p]:%d\n",count++,itr,itr->data);
    itr = itr->next;
  }
  //printf("NODE%d[addr:%p]:%d\n",count++,itr,itr->data);
  return;
}
