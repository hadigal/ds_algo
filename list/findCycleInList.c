#include "listLib.h"

// finding cycle in list with node data change
Node *findCycleWithChange(Node *head)
{
  Node *itr = NULL;
  if(head == NULL || head->next == NULL)
  {
    return itr;
  }
  else if(head->next == head)
  {
    return head;
  }

  itr = head;

  while(itr != NULL)
  {
    if(itr->data == NULL)
    {
      return itr;
    }
    itr->data == NULL;
    itr = itr->next;
  }
  return itr;
}

// finding cycle in list using floyd's algo
Node *findCycleWithoutChange(Node *head)
{
  Node *slow = NULL;
  if(head == NULL || head->next == NULL)
  {
    return slow;
  }
  else if(head->next == head)
  {
    return head;
  }

  slow = head;
  Node *fast = head;
  // if we want to send the looped node;
  uint16_t flg = 0;

  while(slow != NULL && fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast)
    {
      printf("found\n");
      flg = 1;
      break;
      //return true;
    }
  }
  if(flg == 1)
  {
    slow = head;
    while(slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
  slow = NULL;
  return slow;
}
