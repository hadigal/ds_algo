#include "listLib.h"
#include "findLoopLengthLL.h"

int findLoopLength(Node *head)
{
  if(head == NULL || head->next == NULL)
  {
    return 0;
  }

  Node *slow = head;
  Node *fast = head;

  Node *looped = NULL;

  // find the looped node
  while(slow != NULL && fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
    {
      looped = slow;
      break;
    }
  }

  // check for no loop
  if(looped == NULL)
  {
    return 0;
  }

  // if looped then itr from looped node till itr->next == loopedNode; return count
  Node *tmp = looped;
  int count = 1;
  while(tmp->next != looped)
  {
    ++count;
    tmp = tmp->next;
  }
  return count;
}
