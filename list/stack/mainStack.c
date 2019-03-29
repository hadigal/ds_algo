#include "stack.h"

int main()
{
  Stack *head = NULL;
  push(&head,12);
  push(&head,13);
  push(&head,14);
  push(&head,15);

  bool val = isEmpty(head);
  printf("val:%d\n",val);
  
  int peekVal = peek(head);

  printf("peekVal:%d\n",peekVal);

  int del;

  del = pop(&head);
  printf("value deleted:%d\n",del);
  del = pop(&head);
  printf("value deleted:%d\n",del);
  del = pop(&head);
  printf("value deleted:%d\n",del);
  del = pop(&head);
  printf("value deleted:%d\n",del);
  del = pop(&head);
  printf("value deleted:%d\n",del);

  return EXIT_SUCCESS;
}
