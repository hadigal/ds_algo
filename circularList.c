#include "circularList.h"

//Node *last = NULL;

Node *create(int data)
{
  Node *temp = (Node *)calloc(1,sizeof(*temp));
  temp->data = data;
  temp->next = NULL;
  return temp;
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
    printf("Invalid Pos:%d\n", pos);
    return last;
  }
  Node *new, *nodeItr;
  if(pos == 1)
  {
    new = create(data);
    new->next = last->next;
    last->next = new;
    return last;
  }

  nodeItr = last->next; // pointer to start node
  // itreating until the nodeItr points to (pos -1)th node
  for(int itr = 1; itr < pos -1 && nodeItr->next != last->next; ++itr)
  {
    nodeItr = nodeItr->next;
  }

  // check for nodeItr is pointing to the 1st node again!!
  if(nodeItr != last->next)
  {
    new = create(data);
    new->next = nodeItr->next;
    nodeItr->next = new;
  }
  else
  {
    printf("Invalid Pos:%d\n",pos);
  }
  return last;
}

Node *delete(Node *last, int data)
{
  if(last == NULL)
  {
    printf("List empty\n");
    return last;
  }

  Node *temp, *itr;


  itr = last->next;

  if(itr->data == data)
  {
    if(itr->next == itr)
    {
      temp = itr;
      free(temp);
      last = NULL;
      return last;
    }

    temp = itr;
    last->next = temp->next;
    free(temp);
    return last;
  }

  while(itr->next != last->next)
  {
    if(itr->next->data == data)
    {
      temp = itr->next;
      itr->next = temp->next;
      free(temp);
      return last;
    }
    itr = itr->next;
  }
}

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
    printf("Node[%d]: add:%p data:%d\n",itr++,start,start->data);
    start = start->next;
  } while(start != last->next);
}
