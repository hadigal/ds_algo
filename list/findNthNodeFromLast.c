#include "listLib.h"

// O(n) solution using two ptrs
Node *findNthNodeFromLast(Node *start, int idx)
{
  if(start == NULL)
  {
    printf("List is empty\n");
    return start;
  }

  if(start->next == NULL)
  {
    if(idx != 0)
    {
      printf("Not Found\n");
      return start->next;
    }
    return start;
  }

  uint32_t count = 0;
  Node *itr1 = start;
  Node *itr2 = start;

  // itr till the count reaches idx val this will take the ptr to idxth node to last
  while(count < idx)
  {
    if(itr1 == NULL)
    {
      printf("n is greater than total nodes in list!\n");
      return itr1;
    }
    itr1 = itr1->next;
    ++count;
  }

  //now iterate the itr1 to last node; this will take the itr2 node till idxth node from start;
  while(itr1 != NULL)
  {
    itr1 = itr1->next;
    itr2 = itr2->next;
  }
  return itr2;
}
