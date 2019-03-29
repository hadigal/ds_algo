#include "queue.h"

void add(Queue **q, int val)
{
  Node *node = (Node *)calloc(1,sizeof(*node));

  node->data = val;
  node->next = NULL;

  if((*q)->start == NULL)
  {
    (*q)->start = node;
    (*q)->end = node;
    (*q)->count += 1;
    return;
  }

  (*q)->count += 1;
  if((*q)->count >= LEN)
  {
    printf("queue full\n");
    free(node);
    return;
  }

  Node *tmp = (*q)->end;
  tmp->next = node;
  (*q)->end = node;
  return;
}

int pop(Queue *q)
{
  if(q->start == NULL)
  {
    printf("queue is empty\n");
    return INT_MIN;
  }

  Node *tmp =   q->start;
  q->start = tmp->next;

  int ret = tmp->data;
  q->count -= 1;

  if(q->count == 0 || q->start == NULL)
  {
    q->end = NULL;
  }

  free(tmp);
  return ret;
}

// return the val last added to the queue
int peek(Queue *q)
{

  if(q->end == NULL)
  {
    return INT_MIN;
  }

  int val = q->end->data;
  return val;
}

Queue *initQueue()
{
  Queue *q = (Queue *)calloc(1,sizeof(*q));
  q->start = NULL;
  q->end = NULL;
  q->count = 0;

  return q;
}

void display(Node *head)
{
  if(head == NULL)
  {
    printf("Queue empty\n");
    return;
  }

  Node *itr = head;
  printf("\n------------\n");
  while(itr != NULL)
  {
    printf("node:%d\n",itr->data);
    itr = itr->next;
  }
}
