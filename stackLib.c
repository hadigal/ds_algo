#include "stackLib.h"

int32_t topFlag = -1;

void displayStack(void)
{
  if(isEmpty() == 1)
  {
    printf("Stack is Empty\n");
    return;
  }

  for(int itr = topFlag; itr >=0; --itr)
  {
    printf("STACK[%d]:%d\n",itr,stackArr[itr]);
  }

  if(isFull() == 1)
  {
    printf("Stack is Full\n");
  }
  return;
}

int32_t isEmpty(void)
{
  if(topFlag == -1)
  {
    return 1;
  }
  return 0;
}

int32_t isFull()
{
  if(topFlag == MAXSIZE -1)
  {
    return 1;
  }
  return 0;
}

void push(int32_t val)
{
  if(isFull() == 1)
  {
    printf("Stack is FULL; cannot add more elements\n");
    return;
  }
  ++topFlag;
  stackArr[topFlag] = val;
  return;
}

int32_t pop(void)
{
  if(isEmpty() == 1)
  {
    printf("STACK is ALREADY empty\n");
    return EXIT_SUCCESS;
  }

  int32_t val = stackArr[topFlag];
  stackArr[topFlag] = 0;
  --topFlag;
  return val;
}

int32_t peek(void)
{
  if(isEmpty() == 1)
  {
    return 0;
  }
  return stackArr[topFlag];
}
