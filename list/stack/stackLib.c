#include "stack.h"

int32_t top = -1;

Stack *createNode(int val)
{
  Stack *node = (Stack *)calloc(1,sizeof(*node));
  node->val = val;
  node->next = NULL;
  return node;
}

void push(Stack **head, int val)
{
  printf("top:%d\n",top);
  if(top == SIZE)
  {
    printf("stack full\n");
    return;
  }

  Stack *node = createNode(val);
  ++top;
  if(*head == NULL)
  {
    *head = node;
    return;
  }

  node->next = *head;
  *head = node;
  return;
}

int pop(Stack **head)
{
  if(isEmpty(*head) == true)
  {
    printf("stack is empty");
    return INT_MIN;
  }
  Stack *tmp = *head;
  int val = tmp->val;

  --top;

  *head = tmp->next;
  free(tmp);
  return val;
}

bool isEmpty(Stack *head)
{
  if(top == -1 || head == NULL)
  {
    printf("stack is empty!\n");
    return true;
  }
  else
  {
    return false;
  }
}

int peek(Stack *head)
{
  if(isEmpty(head) == false)
  {
    return head->val;
  }
  else
  {
    return INT_MIN;
  }
}
