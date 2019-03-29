#include "listLib.h"

Node *reverse(Node *start)
{
  if(start == NULL || start->next == NULL)
  {
    return start;
  }

  Node *itr = start;
  Node *nxt = NULL;
  Node *prev = NULL;

  while(itr != NULL)
  {
    nxt = itr->next;
    itr->next = prev;
    prev = itr;
    itr = nxt;
  }

  return prev;
}
