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

Node *addInBetweenNodes(Node *start, int d1, int d2, int newData)
{
  if(start == NULL)
  {
    printf("LIST is EMPTY\n");
    return start;
  }
  Node *temp;
  Node *itr = start;
  uint8_t flag = 0;
  while(itr->next != NULL)
  {
    if((itr->data == d1) && (itr->next->data == d2))
    {
      temp = createNode(newData);
      temp->next = itr->next;
      itr->next = temp;
      flag = 1;
      break;
    }
    itr = itr->next;
  }
  if(flag == 1)
  {
    printf("Node[addr:%p] instered successfully between 2 nodes\n",temp);
  }
  else
  {
    printf("invalid input for node DATA\n");
  }
  return start;
}

Node *addAfterNode(Node *start, int data, int d)
{
  if(start == NULL)
  {
    printf("LIST IS EMPTY\n");
    return start;
  }

  Node *itr, *temp;
  itr = start;
  uint8_t flag = 0;

  while(itr->next != NULL)
  {
    if(itr->data == d)
    {
      temp = createNode(data);
      temp->next = itr->next;
      itr->next = temp;
      flag = 1;
      break;
    }
    itr = itr->next;
  }

  if(flag == 1)
  {
    printf("Node[addr:%p] successfully added after Node[addr:%p]\n",temp,itr);
  }
  else
  {
    if(itr->data == d)
    {
      temp = createNode(data);
      itr->next = temp;
      printf("Node[addr:%p] successfully added as final node after Node[addr:%p]\n",temp,itr);
    }
    else
    {
      printf("node not found\n");
    }
  }
  return start;
}

Node *addBeforeNode(Node *start, int data, int d)
{
  if(start == NULL)
  {
    printf("LIST is EMPTY\n");
    return start;
  }

  Node *temp, *itr;
  if(start->data == d)
  {
    temp = createNode(data);
    temp->next= start;
    start = temp;
    printf("Node[addr:%p] added before 1st Node[addr:%p]\n",temp,temp->next);
    return start;
  }

  itr = start;
  uint8_t flag  = 0;
  while(itr->next != NULL)
  {
    if(itr->next->data == d)
    {
      temp = createNode(data);
      temp->next = itr->next;
      itr->next = temp;
      flag  = 1;
      break;
    }
    itr = itr->next;
  }
  if(flag == 0)
  {
    printf("Node not found.\n");
  }
  else
  {
    printf("Node[addr:%p] added before Node[addr:%p]\n",temp,temp->next);
  }
  return start;
}

Node *deleteNode(Node *start, int data)
{
  Node *temp = NULL,*itr;
  uint8_t flag = 0;
  if(start->data ==  data)
  {
    temp = start;
    start = start->next;
    free(temp);
    printf("successfully deleted 1st node\n");
    return start;
  }
  itr = start;
  while(itr->next != NULL)
  {
    if(itr->next->data == data)
    {
      temp = itr->next;
      itr->next = itr->next->next;
      free(temp);
      flag = 1;
      break;
    }
    itr = itr->next;
  }
  if(flag == 1)
  {
    printf("successfully deleted node with data[%d] adrr:%p\n",data,temp);
  }
  else
  {
    printf("could not find data");
  }
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
