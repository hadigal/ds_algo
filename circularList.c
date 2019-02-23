#include "circularList.h"

Node *last = NULL;

Node *create(int data)
{
  Node *temp = (Node *)calloc(1,sizeof(*temp));
  temp->data = data;
  temp->next = NULL;
  return last;
}

Node *addAtBeginning(Node *last, int data)
{
  Node *new;
  //Node *temp = last->next;
  if(last == NULL)
  {
    printf("List is empty\n");
    new = create(data);
    new->next = new;
    last = new;
    return last;
  }
  new = create(data);
  new->next = last->next;
  last->next = new;
  return last;
}

Node *addAtEnd(Node *last, int data)
{
  Node *new;
  if(last == NULL)
  {
    printf("List is empty\n");
    new = create(data);
    new->next = new;
    last = new;
    return last;
  }
  new = create(data);
  new->next = last->next;
  last->next = new;
  last = new;
  return last;
}

int getNodeCount(Node *last)
{
  Node *start;
  if(last == NULL)
  {
    return 0;
  }

  int count = 0;
  start = last->next;
  // ++count;
  //
  // while(start != last->next)
  // {
  //   ++count;
  // }

  do
  {
    ++count;
    start = start->next;
  }while(start != last->next);
  return count;
}

Node *addAtPos(Node *last, int data, int pos)
{
  int count = getNodeCount(last);

  if(count < pos || last == NULL)
  {
    printf("List is empty\n");
    return last;
  }
  Node *new, *temp;
  if(pos == 1)
  {
    new = create(data);
    new->next = last->next;
    last->next = new;
    return last;
  }

  Node *nodeItr = last->link;

  for(int itr = 1; itr < pos -1 && nodeItr->next != last->next; ++itr)
  {
    nodeItr = nodeItr->next;
  }

  if(nodeItr != last->next)
  {
    new = create(data);
    new->next = nodeItr->next;
  }
  else
  {
    printf("Invalid Pos:%d\n",pos);
  }
  return last;
}

Node *delete(Node *last, int data);

void display(Node *last)
{
  if(last == NULL)
  {
    printf("List is empty\n");
    return;
  }

  Node *start = last->next;
  int itr = 1;
  do
  {
    printf("Node[%d]: add:%p data:%d\n",itr,start,start->data);
    start = start->next;
  } while(start != last->next);
}
