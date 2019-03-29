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

Node *addAtPosition(Node *start, int data, int pos)
{
  int itr;
  Node *temp = createNode(data);
  if(pos == 1)
  {
    temp->next = start;
    start = temp;
    return start;
  }
  Node *nodeItr = start;
  for(itr = 1; itr < pos-1 && nodeItr != NULL; ++itr)
  {
    nodeItr = nodeItr->next;
  }
  if(nodeItr == NULL)
  {
    printf("Invalid pos; %d position not available in list\n",pos);
  }
  else
  {
    temp->next = nodeItr->next;
    nodeItr->next = temp;
  }
  return start;
}

Node *deleteKey(Node *start, int key)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return start;
  }

  Node *prev = NULL;
  Node *itr = start;

  while(itr != NULL)
  {
    if(itr->data == key)
    {
      if(prev != NULL)
      {
        prev->next = itr->next;
      }
      else
      {
        start = itr->next;
      }
      free(itr);
      return start;
    }
    prev = itr;
    itr = itr->next;
  }
  printf("key:%d not found\n",key);
  return start;
}

Node *deleteAtPos(Node *start, uint32_t pos)
{
  if(start == NULL)
  {
    printf("List empty\n");
    return start;
  }

  Node *tmp;
  if(pos == 0)
  {
    tmp = start;
    start = tmp->next;
    free(tmp);
    return start;
  }

  int count = 0;
  Node *itr = start;

  while(itr != NULL && (count < pos-1))
  {
    itr = itr->next;
    ++count;
  }

  if(itr == NULL || itr->next == NULL) //why itr->next? --> if pos == len+1; then this will handle the position
  {
    printf("pos:%d is invalid\n",pos);
    return start;
  }

  tmp = itr->next;
  itr->next = tmp->next;
  free(tmp);
  return start;
}

Node *deleteEntireList(Node *start)
{
  if(start == NULL)
  {
    printf("already empty\n");
    return start;
  }

  Node *tmp = NULL;
  Node *itr = start;

  while(itr != NULL)
  {
    tmp = itr;
    itr = itr->next;
    free(tmp);
  }
  start = NULL;
  return start;
}

Node *search(Node *start, int val)
{
  // recursive solution
  // if(start == NULL)
  // {
  //   printf("Node not found\n");
  //   return start;
  // }
  //
  // if(start->data == val)
  // {
  //   return start;
  // }
  //
  // return search(start->next,val);

  // iterative solution

  if(start == NULL)
  {
    printf("empty list\n");
    return start;
  }

  Node *itr = start;

  while(itr != NULL)
  {
    if(itr->data == val)
    {
      return itr;
    }
    itr = itr->next;
  }
  printf("Node not found\n");
  return itr;
}

Node *findMid(Node *start)
{
  if(start == NULL)
  {
    printf("list empty\n");
    return start;
  }

  Node *fast = start;
  Node *slow = start;

  while(fast != NULL)
  {
    fast = fast->next;
    if(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  return slow; // this returns the mid; if len is even return 2 mid as we have 2 mids in even len
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
