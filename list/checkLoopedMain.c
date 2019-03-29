#include "listLib.h"
#include "findLoopLengthLL.h"

int main(void)
{
  Node *start = NULL;

  start = addAtBeginning(start,1);
  start = addAtBeginning(start,2);
  start = addAtBeginning(start,3);
  start = addAtBeginning(start,4);

  displayList(start);

  Node *itr = start, *prev = NULL;

  while(itr != NULL)
  {
    prev = itr;
    itr = itr->next;
  }

  prev->next = start;

  int len =  findLoopLength(start);

  printf("length:%d\n",len);

  return EXIT_SUCCESS;
}
