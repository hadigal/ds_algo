#include "queueWithStack.h"

int main(void)
{
  Stack *queue = NULL;

  Stack *stack2 = NULL;


  enQueue(&queue,&stack2,1);
  enQueue(&queue,&stack2,2);
  enQueue(&queue,&stack2,3);
  enQueue(&queue,&stack2,4);
  enQueue(&queue,&stack2,5);

  display(queue);
  // test
  // display(stack2);

  int val;
  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  val = deQueue(&queue);
  printf("deQueue:%d\n",val);
  display(queue);

  return EXIT_SUCCESS;
}
