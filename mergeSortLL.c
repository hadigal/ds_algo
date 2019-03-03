#include "listLib.h"
#include "mergeSortLL.h"

void partition(struct Node *src, struct Node **l, struct Node ** r)
{
  // use of find mid of node by O(log n) tines algo
  // using fast and slow ptrs;

  struct Node *fast = src->next;
  struct Node *slow = src;

  *l = src;

  while(fast != NULL)
  {
    fast = fast->next;
    if(fast != NULL)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *r = slow->next;
  slow->next = NULL;
}

struct Node *sortedMerge(struct Node *l, struct Node *r)
{
  struct Node *ret = NULL;
  if(l == NULL)
  {
    return r;
  }
  else if(r == NULL)
  {
    return l;
  }

  if(l->data <= r->data)
  {
    ret = l;
    ret->next = sortedMerge(l->next,r);
  }
  else
  {
    ret = r;
    ret->next = sortedMerge(l,r->next);
  }
}

///* NEED TO TEST
void move(struct Node **dest, struct Node **src)
{
  struct Node *temp = *src;
  *src = temp->next;
  temp->next = *dest;
  *dest = temp;
}

struct Node *sortedDummyNode(struct Node *l, struct Node *r)
{
  struct Node dummy;

  struct Node *itr = &dummy;
  dummy.next = NULL;

  while(1)
  {
    if(l ==NULL)
    {
      itr->next = r;
      break;
    }
    else if(r ==NULL)
    {
      itr->next = l;
      break;
    }

    if(l->data <= r->data)
    {
      move(&(itr->next),&l);
    }
    else
    {
      move(&(itr->next),&r);
    }
    itr = itr->next;
  }
  return (dummy.next);
}


void mergeSort(struct Node **src)
{
  struct Node *head = *src;
  struct Node *l;
  struct Node *r;

  //stoping point
  if(head == NULL || head->next == NULL)
  {
    return;
  }

  partition(head,&l,&r);
  // split the left part first;
  mergeSort(&l);
  // split the 2nd half next;
  mergeSort(&r);

  //merging the sorted list using dummy node / recurrsion
  //*src = sortedMerge(l,r);
  *src = sortedDummyNode(l,r);
}
