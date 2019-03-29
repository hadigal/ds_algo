#include "queueWithStack.h"

int deQueue(Stack **stack)
{
  if(*stack == NULL)
  {
    return INT_MIN;
  }

  int ret = pop(stack);

  if(ret == INT_MIN)
  {
    printf("stack empty\n");
  }

  return ret;
}

void enQueue(Stack **stack1, Stack **s2, int val)
{
  int ret;

  // push all items from queue to new stack
  Stack **itrS1 = stack1;
  Stack **itrS2 = s2;

  while(*itrS1 != NULL)
  {
    ret = pop(itrS1);
    if(ret != INT_MIN)
    {
      push(itrS2,ret);
    }
  }

  // push new item to queue so that it is saved at end of stack
  push(stack1,val);
  itrS1 = stack1;

  // now push all the items from stack2 back to queue on top of new item
  while(*itrS2 != NULL)
  {
    val = pop(itrS2);
    // till the last item is poped from s2 stack keep pushing the poped items to queue
    if(val != INT_MIN)
    {
      push(itrS1,val);
    }
  }

  return;
}

int peekQueue(Stack *queue)
{
  if(queue == NULL)
  {
    printf("queue is empty\n");
    return INT_MIN;
  }

  int ret = peek(queue);

  return ret;
}

void display(Stack *queue)
{
  printf("\n-----------\n");
  if(queue == NULL)
  {
    printf("queue is empty\n");
    return;
  }

  Stack *itr = queue;

  while(itr != NULL)
  {
    printf("node:%d\n",itr->val);
    itr = itr->next;
  }
  printf("\n-----------\n");
  return;
}
