#include "removeDuplicateNodes.h"

Node *removeDuplicatesSorted(Node *start)
{
  if(start == NULL || start->next == NULL)
  {
    return start;
  }

  Node *itr = start, *tmp, *next;

  while(itr->next != NULL)
  {
    if(itr->data == itr->next->data)
    {
      next = itr->next->next;
      tmp = itr->next;
      itr->next = next;
      free(tmp);
    }
    else
    {
      itr = itr->next;
    }
  }

  return start;
}

Node *removeDuplicateNodesRecursive(Node *start)
{
  if(start == NULL || start->next == NULL)
  {
    return start;
  }

  if(start->data == start->next->data)
  {
    Node *tmp = start->next;
    start->next = start->next->next;
    free(tmp);
    return removeDuplicateNodesRecursive(start);
  }
  else
  {
    start->next = removeDuplicateNodesRecursive(start->next);
    return start;
  }
}
