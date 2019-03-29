#include "listLib.h"
#include "removeDuplicateNodes.h"

int main(void)
{
  Node *start = NULL;

  start = addAtBeginning(start,1);

  // Node *dummy = (Node *)calloc(1,sizeof(*dummy));
  // dummy->next = start;
  //
  // Node *prev = dummy;
  //
  // printf("prevaddr:%p\nstartaddr:%p\ndummyaddr:%p\n",prev,start,dummy);

  start = addAtEnd(start, 1);
  start = addAtEnd(start,2);
  start = addAtEnd(start,3);
  start = addAtEnd(start,3);

  displayList(start);

  printf("\n******** removed duplicates ********\n");
  //start = removeDuplicatesSorted(start);
  start = removeAllDupNodesSorted(start);

  displayList(start);

  return EXIT_SUCCESS;
}
