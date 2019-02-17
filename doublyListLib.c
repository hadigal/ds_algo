#include "doublyListLib.h"

Node *createNode(int data)
{
  Node *node = (Node *)calloc(1,sizeof(*node));
  node->prev = NULL;
  node->next = NULL;
  node->data = data;
  return node;
}

Node *addAtBeginning(Node *start, int data)
{
  Node *temp;
  temp = createNode(data);
  if(start == NULL)
  {
    start = temp;
    return start;
  }
  temp->next = start;
  start->prev = temp;
  start = temp;
  return start;
}

Node *addAtEnd(Node *start, int data)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return start;
  }
  Node *temp = createNode(data);
  Node *itr = start;

  while(itr->next != NULL)
  {
    itr = itr->next;
  }
  itr->next = temp;
  temp->prev = itr;
  return start;
}

Node *addBeforeNode(Node *start, int data, int d)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return start;
  }
  Node *itr, *temp;
  itr = start;
  temp = createNode(data);
  if(start->data == d)
  {
    temp->next = start;
    start->prev = temp;
    start = temp;
    return start;
  }

  while(itr->next != NULL)
  {
    if(itr->next->data == d)
    {
      temp->prev = itr;
      temp->next = itr->next;
      itr->next->prev = temp;
      itr->next = temp;
      return start;
    }
    itr = itr->next;
  }
  if(itr->data == d)
  {
    temp->prev = itr->prev;
    temp->next = itr;
    itr->prev->next = temp;
  }
  else
  {
    printf("Data not found\n");
  }
  return start;
}

Node *addAfterNode(Node *start, int data, int d)
{
  if(start == NULL)
  {
    printf("List empty\n");
    return start;
  }
  Node *itr = start;
  Node *temp = createNode(data);

  while(itr->next != NULL)
  {
    if(itr->data == d)
    {
      temp->prev = itr;
      temp->next = itr->next;
      itr->next = temp;
      return start;
    }
    itr = itr->next;
  }

  if(itr->data == d)
  {
    temp->prev = itr;
    itr->next = temp;
  }
  else
  {
    printf("data not found\n");
  }
  return start;
}

Node *deleteNode(Node *start, int data)
{
  if(start == NULL)
  {
    printf("list empty\n");
    return start;
  }
  Node *itr, *temp1, *temp2, *delNode;

  if(start->data == data)
  {
    temp1 = start->next;
    delNode = start;
    start = temp1;
    free(delNode);
    return start;
  }
  itr = start;

  while(itr->next != NULL)
  {
    if(itr->data == data)
    {
      delNode = itr;
      temp1 = itr->prev;
      temp2 = itr->next;
      temp1->next = temp2;
      temp2->prev = temp1;
      free(delNode);
      return start;
    }
    itr = itr->next;
  }
  if(itr->data == data)
  {
    delNode = itr;
    temp1 = itr->prev;
    temp1->next = NULL;
    free(delNode);
  }
  else
  {
    printf("data not found\n");
  }
  return start;
}

int getNodeCount(Node *start)
{
  Node *itr = start;
  int count = 0;
  if(start == NULL)
  {
    return count;
  }
  while(itr != NULL)
  {
    ++count;
    itr = itr->next;
  }
  return count;
}

Node *addAtPosition(Node *start, int data, int pos)
{
  Node *nodeItr, *temp;

  int count  = getNodeCount(start);
  if(count < pos || start == NULL)
  {
    printf("Invalid position:%d\n",pos);
    return start;
  }

  if(pos == 1)
  {
    temp = createNode(data);
    temp->next = start;
    start->prev = temp;
    start = temp;
    return start;
  }
  nodeItr = start;
  for(int itr = 1; (itr < (pos -1) && (nodeItr != NULL)); ++itr)
  {
    nodeItr = nodeItr->next;
  }

  if(nodeItr != NULL)
  {
    temp = createNode(data);
    temp->next = nodeItr->next;
    temp->prev = nodeItr;
    nodeItr->next->prev = temp;
    nodeItr->next = temp;
  }
  else
  {
    printf("invalid pos:%d\n",pos);
  }
  return start;
}

void displayList(Node *start)
{
  if(start == NULL)
  {
    printf("list is empty");
  }
  Node *itr = start;
  int count = 1;
  while(itr != NULL)
  {
    printf("Node[%d] addr:%p data:%d\n",count++,itr,itr->data);
    itr = itr->next;
  }
}
