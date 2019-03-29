#include "queue.h"

int main(void)
{
  Queue *newQ;

  newQ = initQueue();

  add(&newQ,1);
  add(&newQ,2);
  add(&newQ,3);
  add(&newQ,4);

  display(newQ->start);

  int val = peek(newQ);

  printf("peek val:%d\n",val);

  val = pop(newQ);
  printf("pop val:%d\n",val);
  display(newQ->start);

  val = pop(newQ);
  display(newQ->start);
  printf("pop val:%d\n",val);

  val = pop(newQ);
  display(newQ->start);
  printf("pop val:%d\n",val);

  val = pop(newQ);
  display(newQ->start);
  printf("pop val:%d\n",val);

  val = pop(newQ);
  printf("pop val:%d\n",val);

  return 0;
}
