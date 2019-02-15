#include "queueLib.h"

Node *createNode(int val)
{
  Node *temp = (Node *)calloc(1,sizeof(*temp));
  temp->data = val;
  temp->next = NULL;
  return temp;
}

void insert(int data)
{
  if(isFull() == 0)
  {
    Node *node = createNode(data);

    if(isEmpty() == 1)
    {
      frontNode = node;
    }
    else if(rearNode != NULL)
    {
      rearNode->next = node;
    }
    rearNode = node;
    ++fullFlag;
    return;
  }
  else
  {
    printf("Queue Overflow; cannot insert more nodes\n");
    return;
  }
}

void delete()
{
  if(isEmpty() == 1)
  {
    printf("Queue underflow\n");
    return;
  }
  else if(frontNode == NULL)
  {
    printf("No items left in queue\n");
    return;
  }
  Node *temp = frontNode->next;
  printf("Delete Item:%d\n",frontNode->data);
  free(frontNode);
  frontNode = temp;
  return;
}

int peek()
{
  if(isEmpty() == 1)
  {
    printf("Queue is empty\n");
    return 0;
  }
  return frontNode->data;
}

int isEmpty(void)
{
  if((frontNode == NULL) && (fullFlag == -1))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isFull(void)
{
  if(fullFlag == MAXSIZE -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void display(void)
{
  if(isEmpty() == 1)
  {
    printf("QUEUE is EMPTY\n");
    return;
  }

  Node *itr = frontNode;
  int count = MAXSIZE - 1 - fullFlag;
  while(itr != NULL)
  {
    printf("Queue order #:%d addr:%p val:%d\n",count++,itr,itr->data);
    itr = itr->next;
  }
  return;
}
