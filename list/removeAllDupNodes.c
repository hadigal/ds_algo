#include "removeDuplicateNodes.h"

Node *removeAllDupNodesSorted(Node *start)
{
  if(start == NULL || start->next == NULL)
  {
    return start;
  }

  //Node *prev = start; // taking this dummy node which pts to the 1st node of dup block to be checked
  Node *itr = start;

  Node *dummy = (Node *)calloc(1,sizeof(*dummy));
  dummy->next = start;
  Node *prev = dummy;

  //Node *newStart = NULL;

  while(itr != NULL)
  {
    while(itr->next != NULL && prev->next->data == itr->next->data)
    {
      itr = itr->next;
    }

    // To store the unique node and move on
    if(prev->next == itr)
    {
      // if(newStart == NULL)
      // {
      //   newStart = prev;
      // }
      prev = prev->next;
      itr = itr->next;
    }
    else
    {
      prev->next = itr->next;
      itr = prev->next;
    }
  }
  start = dummy->next;
  return start;
}
