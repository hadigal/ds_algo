#include "listLib.h"

int countKeyOccurance(Node *head, int key)
{
  uint32_t count = 0;
  if(head == NULL)
  {
    printf("list empty\n");
    return count;
  }
  else if(head->next == NULL && head->data == key)
  {
    return 1;
  }

  Node *itr = head;
  while(itr != NULL)
  {
    if(itr->data == key)
    {
      ++count;
    }
    itr = itr->next;
  }
  return count;
}
